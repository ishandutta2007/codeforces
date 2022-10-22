#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXN=1e5+2;
vector<int> adj[MAXN];
bool flag[MAXN];
int cnt;
void dfs(int v){
    flag[v]=true;
    cnt++;
    for(int i : adj[v]){
        if(!flag[i]) dfs(i);
    }
}
bool lucky(int w){
    while(w>0){
        if(w%10!=4 && w%10!=7) return false;
        w/=10;
    }
    return true;
}
int main()
{
    fast_io;
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x,y,w;
        cin >> x >> y >> w;
        if(lucky(w)) continue;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> comp;
    for(int i=1; i<=n; i++){
        if(!flag[i]){
            dfs(i);
            comp.push_back(cnt);
            cnt=0;
        }
    }
    ll ans=0;
    for(ll i : comp) ans+=i*(n-i)*(n-i-1);
    cout << ans;
    return 0;
}