#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int dis[505][505];
int x[250005],y[250005],z[250005];
vector <int> v[505];
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) dis[i][j]=-1;
            dis[i][i]=0;
            queue <int> q;
            q.push(i);
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(auto t:v[temp])
                    if(dis[i][t]==-1)
                        dis[i][t]=dis[i][temp]+1,q.push(t);
            }
            //for(int j=1;j<=n;j++) cout<<dis[i][j]<<" ";puts("");
        }
        long long ans=LLONG_MAX/10;
        for(int i=1;i<=m;i++){
            int mn=min(dis[1][x[i]]+dis[y[i]][n],dis[1][y[i]]+dis[x[i]][n]);
            for(int j=1;j<=n;j++) mn=min(mn,min(dis[j][x[i]]+dis[1][j]+dis[n][j],dis[j][y[i]]+dis[1][j]+dis[n][j])+1);
            ans=min(ans,1LL*z[i]*(mn+1));
        }
        printf("%lld\n",ans);
    }
    return 0;
}