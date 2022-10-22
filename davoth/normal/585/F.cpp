#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
/*#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")*/
using namespace std;
using ll = long long int;
#define F first
#define S second
#define pb push_back
#define lc v<<1
#define rc v<<1|1
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e4+10,LN=50,M=1e5+10,SQ=350,inf=1e9;
const ll INF=1e18;
const int MOD=1000000007 /*998244353*/;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
using pii=pair<int,int>;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, ll mod){
    ll ans=1;
    while (y != 0) {
        if (y & 1) ans = ans * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return ans;
}
ll C[N][10],F[N],ts,Q[N],R,L,A[N],d,dp[N][51],X,Y,D;
string s,e,x,y;
void AddTrie(ll l){
    int v=0;
    for (ll i=l; i<l+d; i++){
        char ch=s[i];
        if (!C[v][ch-'0']) C[v][ch-'0']=++ts;
        v=C[v][ch-'0'];
    }
    A[v]=1;
}
void BuildAho(){
    for (int i=0; i<10; i++) if (C[0][i]) Q[R++]=C[0][i];
    while (L<R){
        int v=Q[L++];
        A[v]|=A[F[v]];
        for (int i=0; i<10; i++){
            if (!C[v][i]) C[v][i]=C[F[v]][i];
            else{
                F[C[v][i]]=C[F[v]][i];
                Q[R++]=C[v][i];
            }
        }
    }
}
ll calc(string s){
    if(s[0]=='0') return -1;
    ll ans=0,v=0;
    for(ll i=0; i<D; i++){
        for(ll j=!i; j<s[i]-'0'; j++){
            ans=(ans+dp[C[v][j]][D-i-1])%MOD;
        }
        v=C[v][s[i]-'0'];
        if(A[v]) return ans-1;
    }
    return ans%MOD;
}
int main(){
    fast_io;
    cin >> s >> x >> y;
    D=y.size();
    d=D/2;
    for(ll i=D-1; i>=0; i--){
        if(x[i]!='0'){
            x[i]--;
            break;
        }
        else x[i]='9';
    }
    for(ll i=0; i<D; i++){
        Y=(Y*10+y[i]-'0')%MOD;
        X=(X*10+x[i]-'0')%MOD;
    }
    for(ll i=0; i+d-1<s.size(); i++) AddTrie(i);
    BuildAho();
    for(ll i=0; i<=ts; i++) if(!A[i]) dp[i][0]=1;
    for(ll j=1; j<=D; j++){
        for(ll i=0; i<=ts; i++){
            if(A[i]) continue;
            for(ll k=0; k<10; k++){
                dp[i][j]=(dp[i][j]+dp[C[i][k]][j-1])%MOD;
            }
        }
    }
    cout << (Y-X-calc(y)+calc(x)+2*MOD)%MOD << '\n';
    return 0;
}