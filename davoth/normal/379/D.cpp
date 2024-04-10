#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#pragma GCC optimize("O2")
/*#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
using ld = long double;
#define F first
#define S second
#define pb push_back
//#define mp make_pair
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=5e5+10,LN=20,M=3.5e7+10,SQ=350,BS=737,inf=1e9+10;
const ll INF=1e15;
const ld ep=1e-7;
const int MH=1000696969,MOD=1000000007,MD=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<pll, null_type,less<pll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll n,m,k,x,f[52],b[4];
string s1,s2;
int main(){
    fast_io;
    cin >> k >> x >> n >> m;
    for(ll bt=0; bt<81; bt++){
        ll z=bt;
        for(ll i=0; i<4; i++){
            b[i]=z%3;
            z/=3;
        }
        for(ll i=0; i<=n/2; i++){
            for(ll j=0; j<=m/2; j++){
                if(n==1 && b[0]!=b[1]) continue;
                if(m==1 && b[2]!=b[3]) continue;
                if(n==2 && i==0 && !b[0] && b[1]==1) continue;
                if(m==2 && j==0 && !b[2] && b[3]==1) continue;
                if(i*2==n && (b[0] || b[1]!=1)) continue;
                if(i && i*2==n-1 && b[0] && b[1]!=1) continue;
                if(j*2==m && (b[2] || b[3]!=1)) continue;
                if(j && j*2==m-1 && b[2] && b[3]!=1) continue;
                f[1]=i;
                f[2]=j;
                f[3]=i+j+(!b[1] && b[2]==1);
                for(ll t=4; t<=k; t++){
                    f[t]=f[t-1]+f[t-2];
                    if(t%2==0){
                        f[t]+=(!b[3] && b[0]==1);
                    }else{
                        f[t]+=(!b[3] && b[2]==1);
                    }
                    if(f[t]>x) f[t]=x+1;
                }
                if(f[k]==x){
                    //cout << b[0] << ' ' << b[1] << ' ' << b[2] << ' ' << b[3] << ' ' << i << ' ' << j << '\n';
                    ll q=i,p=j;
                    if(b[0]==1) s1="C";
                    else if(b[0]==2) s1="B";
                    else if(q) s1="AC",q--;
                    else s1="A";
                    for(ll t=0; t<q; t++) s1+="AC";
                    for(ll t=s1.size(); t<n-1; t++) s1+="B";
                    if(s1.size()==n-1){
                        if(b[1]==1) s1+="C";
                        else if(b[1]==2) s1+="B";
                        else s1+="A";
                    }
                    if(b[2]==1) s2="C";
                    else if(b[2]==2) s2="B";
                    else if(p) s2="AC",p--;
                    else s2="A";
                    for(ll t=0; t<p; t++) s2+="AC";
                    for(ll t=s2.size(); t<m-1; t++) s2+="B";
                    if(s2.size()==m-1){
                        if(b[3]==1) s2+="C";
                        else if(b[3]==2) s2+="B";
                        else s2+="A";
                    }
                    cout << s1 << '\n' << s2 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "Happy new year!\n";
    return 0;
}