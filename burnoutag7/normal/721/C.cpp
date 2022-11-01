#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,T;
vector<pair<int,int> > g[5005];
int dp[5005][5005];
int f[5005][5005];

void print(int x,int cur){
    if(x==1){
        cout<<x<<' ';
        return;
    }
    print(f[x][cur],cur-1);
    cout<<x<<' ';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>T;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b,c));
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=n;x++){
            if(dp[x][i]>1e9)continue;
            for(int k=0;k<g[x].size();k++){
                int y=g[x][k].first;
                int z=g[x][k].second;
                if(dp[y][i+1]>dp[x][i]+z){
                    dp[y][i+1]=dp[x][i]+z;
                    f[y][i+1]=x;
                }
            }
        }
    }
    int ans=1e9;
    for(int i=1;i<=n;i++){
        if(dp[n][i]<=T){
            ans=i;
        }
    }
    cout<<ans<<endl;
    print(n,ans);

    return 0;
}