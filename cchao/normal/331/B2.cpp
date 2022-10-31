#include <cstdio>
#include <iostream>
using namespace std;
#define M 300100
int n, arr[M], a[M], b[M] = {0};
int low(int x) { return x&-x; }
int C[M*3] = {0};
int sum(int x) {
    int ret = 0;
    while(x > 0) {
        ret += C[x]; x-=low(x);
    }
    return ret;
}
void add(int x, int d) {
    while(x <= n) {
        C[x] += d; x += low(x);
    }
}

void update(int ori, int aft, int cmp, int type, int idx) {
    if(idx > n || idx <= 1) return;
    int x = ori < cmp ? 1 : 0, y = aft < cmp ? 1 : 0;
    if(x != y) {
        if(type==-1) add(idx, y - x);
        else add(idx, x - y);
    }
}
void update(int i) {
    int t;
    if(i >= 2) {
        t = a[i] < a[i-1] ? 1 : 0;
        add(i, t - b[i]);
        b[i] = t;
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        a[arr[i]] = i;
    }
    for(int i = 2; i <= n; ++i) {
        if(a[i] < a[i-1]) { add(i, 1); b[i] = 1; }
    }

    int q, p, x, y;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        scanf("%d%d%d", &p, &x, &y);
        if(p == 2) {
            swap(arr[x], arr[y]);
            a[arr[x]] = x;
            a[arr[y]] = y;
            update(arr[x]);
            update(arr[x]+1);
            update(arr[y]);
            update(arr[y]+1);

        }
        else {
            printf("%d\n", sum(y) - sum(x) + 1);
        }
    }
    return 0;
}