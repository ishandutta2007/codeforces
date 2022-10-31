#include <bits/stdc++.h>
using namespace std;

bool used[1005];
long double dp[105][3];
int depth[105][3];
vector<int> v[105];
int q[105];
int n,m;
int x,y;
void bfs(int x,int y){
    for (int i=1;i<=n;++i)
        used[i]=false;
    int r=1;
    q[1]=x;
    used[x]=true;
    dp[x][y]=1;
    depth[x][y]=1;
    for (int i=1;i<=r;++i) {
        x=q[i];
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j];
            if (used[to]==false) {
                used[to]=true;
                ++r;
                q[r]=to;
                depth[to][y]=depth[x][y]+1;
            }
        }
    }
    for (int i=1;i<=r;++i) {
        x=q[i];
        for (int j=0;j<v[x].size();++j) {
            int to=v[x][j];
            if (depth[to][y]==depth[x][y]+1) dp[to][y]=(dp[to][y]+dp[x][y]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cout<<fixed<<setprecision(10);
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        if ((x==1 || y==1) && (x==n || y==n)) {
            cout<<1;
            return 0;
        }
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(n,0);
    bfs(1,1);
    long double ans=0;
    for (int i=2;i<n;++i) {
        long double q1=0,q2=0;
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (depth[to][1]==depth[i][1]-1) q2+=dp[to][1];
            else if (depth[to][0]==depth[i][0]-1) q1+=dp[to][0];
        }
        if (!(depth[i][0]+depth[i][1]-1==depth[n][1])) continue;
        long double res=q1*q2*2/dp[n][1];
        ans=max(ans,res);
    }
    long double res=0;
    for (int i=0;i<v[1].size();++i) {
        int to=v[1][i];
        if (depth[to][0]==depth[1][0]-1)
        res+=dp[to][0];
    }
    ans=max(ans,res/dp[n][1]);
    res=0;
    for (int i=0;i<v[n].size();++i) {
        int to=v[n][i];
        if (depth[to][1]==depth[n][1]-1)
        res+=dp[to][1];
    }
    ans=max(ans,res/dp[n][1]);
    cout<<ans;
}