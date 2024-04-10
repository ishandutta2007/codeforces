#include<bits/stdc++.h>
using namespace std;

vector<int> g[2][200005];
int n;
bool u[200005];
long long dp[200005][4];
long long res;

void dfs(int x){
    u[x]=true;
    for(int j=0;j<2;j++){
        for(int i=0;i<g[j][x].size();i++){
            int y=g[j][x][i];
            if(!u[y]){
                dfs(y);
                res+=dp[x][j]*(2*dp[y][j]+dp[y][2|j]+dp[y][!j]+2);
                res+=dp[x][!j]*(dp[y][j]+1);
                res+=dp[x][2|j]*(dp[y][j]+1);
                dp[x][j]+=dp[y][j]+1;
                dp[x][2|j]+=dp[y][2|j]+dp[y][!j];
            }
        }
    }
    res+=2*dp[x][0]+2*dp[x][1]+dp[x][2]+dp[x][3];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[c][a].push_back(b);
        g[c][b].push_back(a);
    }
    dfs(1);
    cout<<res<<endl;

    return 0;
}