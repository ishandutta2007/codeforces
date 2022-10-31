#include <bits/stdc++.h>
using namespace std;

vector<int> v[200005];
vector<int> vv[200005];
int dp[200005];
int ans;
vector<int> q;
int n,x,y;
void dfs1(int x,int p){
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==p) continue;
        dfs1(to,x);
        dp[x]+=dp[to];
    }
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (to==p) continue;
        dfs1(to,x);
        dp[x]+=dp[to]+1;
    }
}
void dfs2(int x,int p,int y){
    if (x!=1) {
        dp[x]=dp[p]+y;
        if (dp[x]<ans) {
            ans=dp[x];
            q.clear();
            q.push_back(x);
        } else if (dp[x]==ans) {
            q.push_back(x);
        }
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==p) continue;
        dfs2(to,x,1);
    }
    for (int i=0;i<vv[x].size();++i){
        int to=vv[x][i];
        if (to==p) continue;
        dfs2(to,x,-1);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    dfs1(1,-1);
    ans=dp[1];
    q.push_back(1);
    dfs2(1,-1,0);
    cout<<ans<<'\n';
    sort(q.begin(),q.end());
    for (int i=0;i<q.size();++i)
        cout<<q[i]<<" ";
}