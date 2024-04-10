#include <bits/stdc++.h>
using namespace std;

int n,m,d;
int x,y;
vector<int> v[100005];
int dp[100005];
bool used[100005];
int ans;
vector<int> q[100005],qq[100005];

void dfs(int x,int y=-1){
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        if (dp[to]) dp[x]=max(dp[x],dp[to]+1);
        else if (used[to] && !dp[x]) dp[x]=1;
    }

    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) {
            q[x].push_back(0);
            continue;
        }
        if (dp[to]) q[x].push_back(dp[to]+1);
        else if (used[to]) q[x].push_back(1);
        else q[x].push_back(0);
    }
    qq[x].push_back(q[x][0]);
    for (int i=1;i<q[x].size();++i){
        qq[x].push_back(max(q[x][i],qq[x][i-1]));
    }
    for (int i=q[x].size()-2;i>=0;--i)
        q[x][i]=max(q[x][i],q[x][i+1]);

}

void dfs2(int x,int y,int depth){
    if (max(dp[x],depth)<=d) { ++ans;}
    if (depth>d) return;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int todepth=0;
        if (i && qq[x][i-1]) todepth=qq[x][i-1]+1;
        if (i!=q[x].size()-1 && q[x][i+1]) todepth=max(todepth,q[x][i+1]+1);
        if (used[x]) todepth=max(todepth,1);
        if (depth) todepth=max(todepth,depth+1);
        dfs2(to,x,todepth);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>d;
    for (int i=1;i<=m;++i) {
        cin>>x;
        used[x]=true;
    }
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    dfs2(1,-1,0);
    cout<<ans;
}