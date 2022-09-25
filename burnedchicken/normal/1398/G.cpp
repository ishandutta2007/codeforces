#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define rep(a) for(int i=0; i<a; i++)
using namespace std;
int n,x,y,a[200005],q,l,ans[1000005];
bitset<200005> bs1,bs2;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> x >> y;n++;
    rep(n) {cin >> a[i];bs2[a[i]]=1;}
    rep(n) bs1|=bs2>>a[i];
    memset(ans,-1,sizeof(ans));
    for(int i=2*y+2; i<2*y+400010; i+=2) if(bs1[i/2-y]) for(int j=i; j<1000005; j+=i) ans[j]=i;
    cin >> q;
    while(q--){cin >> l;cout << ans[l] << ' ';}
    return 0;
}