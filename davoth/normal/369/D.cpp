#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=3e3+10;
const int MOD=1000000007;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using pll=pair<ll,ll>;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll pow(ll x, ll y, int mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    ll a=y/2,b=y/2;
    b+=y%2;
    return (pow(x,a,mod)*pow(x,b,mod))%mod;
}
ll n,k;
ll p[N];
int main() {
    fast_io;
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> p[i];
    bool y[n],g[n];
    y[n-1]=p[n-1]==100;
    g[n-1]=p[n-1]!=0;
    for(int i=n-2; i>=0; i--){
        y[i]=y[i+1]||p[i]==100;
        g[i]=g[i+1] || p[i]!=0;
    }
    queue<pll> q;
    ll dist[N][N];
    memset(dist,63,sizeof dist);
    dist[0][1]=0;
    q.push({0,1});
    ll cnt=1;
    while(!q.empty()){
        ll A=q.front().F,B=q.front().S;
        q.pop();
        if(A>=n || B>=n || dist[A][B]>=k) continue;
        if(p[A]>0 && g[B] && dist[B+1][B+2]>dist[A][B]+1) q.push({B+1,B+2}),dist[B+1][B+2]=dist[A][B]+1,cnt++;
        if(p[A]>0 && !y[B] && dist[A][B+1]>dist[A][B]+1) q.push({A,B+1}),dist[A][B+1]=dist[A][B]+1,cnt++;
        if(p[A]<100 && g[B] && dist[B][B+1]>dist[A][B]+1) q.push({B,B+1}),dist[B][B+1]=dist[A][B]+1,cnt++;
    }
    cout << cnt;
    return 0;
}