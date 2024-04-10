#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e5+10,LN=30,SQ=550;
const int MOD=1000000009 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
int n,m,a[N],F[N],sum[SQ];
pii lazy[SQ];
int f(int x){
    return (F[x+2]-2+MOD)%MOD;
}
int f(int l, int r){
    return (MOD+F[r+2]-F[l+1])%MOD;
}
int main() {
    fast_io;
    cin >> n >> m;
    F[1]=1;
    for(int i=2; i<N; i++) F[i]=(F[i-1]+F[i-2])%MOD;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum[i/SQ]+=a[i];
        sum[i/SQ]%=MOD;
    }
    while(m--){
        int q,l,r,t;
        cin >> q >> l >> r;
        --l,--r;
        t=l/SQ+1;
        if(q==1){
            int k=1;
            //cout << min(t*SQ,r+1) << '\n';
            for(int i=l; i<min(t*SQ,r+1); i++) a[i]+=F[k],sum[l/SQ]+=F[k],k++,a[i]%=MOD,sum[l/SQ]%=MOD;
            for(int i=t; i<r/SQ; i++){
                sum[i]+=f(k,k+SQ-1);
                sum[i]%=MOD;
                lazy[i].F+=F[k],lazy[i].S+=F[k+1],lazy[i].F%=MOD,lazy[i].S%=MOD;
                k+=SQ;
            }
            if(l/SQ!=r/SQ) for(int i=r/SQ*SQ; i<=r; i++) a[i]+=F[k],sum[r/SQ]+=F[k],k++,a[i]%=MOD,sum[r/SQ]%=MOD;
        }else{
            int ans=0;
            int k=lazy[t-1].F%MOD,kk=lazy[t-1].S%MOD;
            lazy[t-1]={0,0};
            a[(t-1)*SQ]+=k;
            a[(t-1)*SQ]%=MOD;
            a[(t-1)*SQ+1]+=kk;
            a[(t-1)*SQ+1]%=MOD;
            for(int i=(t-1)*SQ+2; i<t*SQ; i++) a[i]+=(k+kk)%MOD,a[i]%=MOD,kk=kk+k,k=kk-k,kk%=MOD;
            for(int i=l; i<min(t*SQ,r+1); i++) ans+=a[i],ans%=MOD;
            for(int i=t; i<r/SQ; i++) ans+=sum[i],ans%=MOD;
            int o=r/SQ;
            k=lazy[o].F%MOD,kk=lazy[o].S%MOD;
            lazy[o]={0,0};
            a[o*SQ]+=k;
            a[o*SQ]%=MOD;
            a[o*SQ+1]+=kk;
            a[o*SQ+1]%=MOD;
            for(int i=o*SQ+2; i<min(n,(o+1)*SQ); i++) a[i]+=(k+kk)%MOD,a[i]%=MOD,kk=kk+k,k=kk-k,kk%=MOD;
            if(l/SQ!=r/SQ) for(int i=o*SQ; i<=r; i++) ans+=a[i],ans%=MOD;
            cout << ans << '\n';
        }
        //for(ll i=0; i<n; i++) cout << a[i] << ' ';
        //cout << '\n';
    }
    return 0;
}