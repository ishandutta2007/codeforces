#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_map>
using namespace std;
int a[300005],n;
int cnt(int x){
    int t=0;
    if(a[x]>a[x-1]) t+=a[x]-a[x-1];
    if(x<n&&a[x]<a[x+1]) t+=a[x+1]-a[x];
    return t;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        long long ans = 0;
        int q, l, r;
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] - a[i - 1] > 0) ans += a[i] - a[i - 1];
        }
        printf("%lld\n", ans);
        for (int i = 1; i <= q; i++) {
            scanf("%d%d", &l, &r);
            if(l==r){
                swap(a[l],a[r]),printf("%lld\n",ans);
                continue;
            }
            if(l==r-1){
                ans-=cnt(l)+cnt(r);
                if(a[l]<a[r]) ans+=a[r]-a[l];
                swap(a[l],a[r]);
                ans+=cnt(l)+cnt(r);
                if(a[l]<a[r]) ans-=a[r]-a[l];
                printf("%lld\n",ans);
                continue;
            }
            ans -= cnt(l) + cnt(r);
            swap(a[r], a[l]);
            ans += cnt(l) + cnt(r);
            printf("%lld\n", ans);
        }
    }
    return 0;
}