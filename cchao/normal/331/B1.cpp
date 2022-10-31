#include <cstdio>
#include <iostream>
using namespace std;
int n, arr[110], a[110];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        a[arr[i]] = i;
    }

    int q, p, x, y;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i) {
        scanf("%d%d%d", &p, &x, &y);
        if(p == 2) {
            swap(arr[x], arr[y]);
            a[arr[x]] = x;
            a[arr[y]] = y;

        }
        else {
            int ans = 0,f = 0;
            for(int i = x; i <= y; ++i) {
                if(f && a[i] < a[i-1]) { ans++;}
                else { f = i; }
            }
            if(f) ++ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}