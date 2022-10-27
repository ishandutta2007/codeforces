#include <bits/stdc++.h>
using namespace std;
#define vll vector<ll>
#define vvll vector<vll>
#define here cout << "here";
#define rep(i, n) for (ll i = 0; i < n; i++)
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define nl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)((x).size())
#define pii pair<ll, ll>
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define asc(arr) sort(arr.begin(), arr.end())
#define desc(arr) sort(arr.begin(), arr.end(), greater<ll>())
 
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t p = 998244353;
int bfs(vvll & edge, vector<bool> & vis,int src,map<ll,ll>&mp){
    int flag=1;
    if(mp[src]) flag=0;
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        auto t=q.front();
        if(mp[t]) 
        flag=0;
        q.pop();
        for(auto x:edge[t]){
            if(!vis[x])
            {
                q.push(x);
                vis[x]=1;
            }
        }
    }
    return flag;
}
ll power(ll a, ll b){
    ll res=1;
    while(b>0){
        if(b&1){
            res=((res%M)*(a%M))%M;
        }
        a=((a%M)*(a%M))%M;
        b=b/2;
    }
    return res%M;
}
void solve()
{
map<ll,ll>mp;
ll n;
cin>>n;
vll arr(n),brr(n),crr(n);
rep(i,n) cin>>arr[i];
rep(i,n) { cin>>brr[i]; if(brr[i]==arr[i]) mp[arr[i]]=1; }
rep(i,n) { cin>>crr[i]; mp[crr[i]]= 1; }
vector<vector<ll>>edge(n+1);
rep(i,n){
    edge[arr[i]].pb(brr[i]);
    edge[brr[i]].pb(arr[i]);
}
int conn=0;
vector<bool> vis(n+1,0);
for(int i=1;i<=n;i++){
    if(vis[i]) continue;
    conn+=bfs(edge,vis,i,mp);
}
ll ans=power(2,conn);
cout<<ans<<endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll t = 1;
    cin >> t;
    while (t--)
        solve();
}