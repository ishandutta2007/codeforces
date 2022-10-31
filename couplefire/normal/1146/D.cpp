#include<bits/stdc++.h>
#define ls x<<1
#define rs x<<1|1
#define PI acos(-1.0)
using namespace std;
 
typedef long long ll;
ll m,a,b,lim,ans;
bool vis[200010];
 
ll gcd(ll a,ll b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
 
void dfs(ll u,ll maxv)
{
    vis[u]=1;
    ans+=lim-maxv+1;
    if(u>=b&&!vis[u-b]) dfs(u-b,max(maxv,u-b));
    if(u<=lim-a&&!vis[u+a]) dfs(u+a,max(maxv,u+a));
}
 
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>m>>a>>b;
    lim=min(m,a+b-1);
    dfs(0,0);
    ll g=gcd(a,b);
    if(lim<m) ans+=(m-lim+m-m/g*g+1)*(m/g-(lim+1)/g+1)/2+(lim+1)/g*(m-lim);
    cout<<ans;
    return 0;
}