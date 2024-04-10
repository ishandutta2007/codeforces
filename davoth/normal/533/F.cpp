#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10,LN=30,SQ=550,M=1e6+10;
const ll INF=1e16;
const int MOD=1000000007 /*998244353*/;
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
ll n1,n2,m=1000696969,b=737,h1[26][N],h2[26][N],p[N],f[26];
string s,t;
vector<ll> ans;
int main(){
    fast_io;
    cin >> n1 >> n2;
    cin >> s >> t;
    p[0]=1;
    memset(f,-1,sizeof f);
    for(ll i=1; i<N; i++) p[i]=p[i-1]*b%m;
    for(ll i=0; i<26; i++){
        for(ll j=0; j<n1; j++){
            if(j>0) h1[i][j]=h1[i][j-1]*b%m;
            if(s[j]-'a'==i) h1[i][j]++,h1[i][j]%=m;
        }
        for(ll j=0; j<n2; j++){
            if(j>0) h2[i][j]=h2[i][j-1]*b%m;
            if(t[j]-'a'==i) h2[i][j]++,h2[i][j]%=m;
        }
    }
    for(ll i=n2-1; i>=0; i--) f[t[i]-'a']=i;
    for(ll i=0; i<n1-n2+1; i++){
        bool c=1;
        for(ll j=0; j<26; j++){
            if(f[j]==-1) continue;
            ll k=s[i+f[j]]-'a';
            ll x=0;
            if(i>0){
                x=h1[k][i-1]*p[n2]%m;
            }
            c&=h2[j][n2-1]==(h1[k][i+n2-1]-x+m)%m;
            if(i>0){
                x=h1[j][i-1]*p[n2]%m;
            }
            c&=h2[k][n2-1]==(h1[j][i+n2-1]-x+m)%m;
        }
        if(c) ans.push_back(i+1);
    }
    cout << ans.size() << '\n';
    for(ll i : ans) cout << i << ' ';
    cout << '\n';
    return 0;
}