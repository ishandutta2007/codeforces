#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 200010

int ord[N], n, a[N], bit[N];

void add(int x, int d){
    for (;x <= n;x += x & -x) bit[x] += d;
}

int ask(int x){
    int ret = 0;
    for (;x;x -= x & -x) ret += bit[x];
    return ret;
}

int cmp(int i, int j){
    return a[i] > a[j];
}

int main(){
    scanf("%d", &n);
    for (int i = 1;i <= n;i ++) scanf("%d", &a[i]), a[i] = min(a[i], n), ord[i] = i;
    sort(ord + 1, ord + n + 1, cmp);
    int j = 0;
    long long ans = 0;
    for (int i = n;i >= 1;i --){
        while (j + 1 <= n && a[ord[j + 1]] >= i) {
            add(ord[j + 1], 1);
            j ++;
        }
        if (i <= a[i])
            ans += ask(a[i]) - ask(i);
    }
    cout << ans << endl;
    return 0;
}