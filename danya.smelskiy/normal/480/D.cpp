#include <bits/stdc++.h>
using namespace std;



int n,ss;
bool used[505][1005];
int dp[505][1005];
int tin[505],tout[505],w[505],pr[505],s[505];
vector<int> v[1005];
int solve(int x,int y){
    if (used[x][y]) return dp[x][y];
    used[x][y]=true;
    vector<int> q;
    for (int i=tin[x];i<=tout[x];++i)
        q.push_back(0);
    for (int i=tin[x];i<tout[x];++i) {
        q[i-tin[x]+1]=max(q[i-tin[x]+1],q[i-tin[x]]);
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (tout[to]>tout[x] || to==x || w[to]>y) continue;
            int pos=tout[to]-tin[x];
            q[pos]=max(q[pos],q[i-tin[x]]+pr[to]+solve(to,min(y-w[to],s[to])));
        }
    }
    dp[x][y]=q[tout[x]-tin[x]];
    return dp[x][y];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>ss;
    for (int i=1;i<=n;++i) {
        cin>>tin[i]>>tout[i]>>w[i]>>s[i]>>pr[i];
        v[tin[i]].push_back(i);
    }
    tin[0]=0;
    tout[0]=n+n+1;
    s[0]=ss;
    cout<<solve(0,ss);
}