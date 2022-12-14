#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 100010
typedef long long ll;
int a[N], bin[N], n, cnt, S[N], T[N];
ll K;

void add(int *bit, int x, int v){
    for (;x <= cnt; x += x & -x) bit[x] += v;
}

int ask(int *bit, int x){
    int ret = 0;
    for (;x;x -= x & -x) ret += bit[x];
    return ret;
}

int main(){
    scanf("%d%I64d", &n, &K);
    for(int i = 1;i <= n;i ++){
        scanf("%d", &a[i]);
        bin[++ cnt] = a[i];
    }
    sort(bin + 1, bin + n + 1);
    cnt = unique(bin + 1, bin + n + 1) - bin - 1;
    for(int i = 1;i <= n;i ++)
        a[i] = lower_bound(bin + 1, bin + cnt + 1, a[i]) - bin;
    ll cur = 0;
    for (int i = n;i >= 1;i --){
        add(T, a[i], 1);
        cur += ask(T, a[i] - 1);
    }
    add(T, a[1], -1);
    add(S, a[1], 1);
    int l = 1, r = 2;
    ll ans = 0;
    while (l < n){
        while ((cur > K && r + 1 <= n) || r <= l) {
            cur -= l - ask(S, a[r]);
            cur -= ask(T, a[r] - 1);
            add(T, a[r], -1);
            r ++;
        }
        if (cur > K) break;
        ans += n - r + 1;
        l ++;
        add(S, a[l], 1);
        cur += l - ask(S, a[l]);
        cur += ask(T, a[l] - 1);
    }
    cout << ans << endl;
    return 0;
}