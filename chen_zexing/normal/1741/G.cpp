#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int dis[7][10005];
vector <int> v[10005];
int dp[1<<6],nxt[1<<6],h[10005],p[7];
bool cmp(int x,int y){
    return dis[0][h[p[x]]]<dis[0][h[p[y]]];
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,m,f,k;
        cin>>n>>m;
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        cin>>f;
        for(int i=1;i<=f;i++) scanf("%d",&h[i]);
        cin>>k;
        for(int i=1;i<=k;i++) scanf("%d",&p[i]);
        p[0]=0,h[0]=1;
        for(int i=0;i<=k;i++){
            for(int j=1;j<=n;j++) dis[i][j]=-1;
            queue <int> q;
            dis[i][h[p[i]]]=0,q.push(h[p[i]]);
            while(!q.empty()){
                int temp=q.front();
                q.pop();
                for(auto t:v[temp])
                    if(dis[i][t]==-1)
                        dis[i][t]=dis[i][temp]+1,q.push(t);
            }
        }
        memset(dp,0,sizeof(dp)),memset(nxt,0,sizeof(nxt));
        dp[0]=1;
        for(int i=1;i<=f;i++){
            int ck=1;
            for(int j=1;j<=k;j++) if(i==p[j]) ck=0;
            if(!ck) continue;
            //cout<<"enter"<<" "<<i<<" "<<h[i]<<endl;
            for(int j=0;j<(1<<k);j++){
                int fl=1;
                vector <int> v;
                for(int t=0;t<k;t++)
                    if((1<<t)&j){
                        if(dis[0][h[i]]<dis[0][h[p[t+1]]]+dis[t+1][h[i]]) fl=0;
                        v.push_back(t+1);
                    }
                sort(v.begin(),v.end(),cmp);
                v.insert(v.begin(),0);
                int sum=0;
                for(int t=0;t+1<v.size();t++)
                    sum+=dis[v[t]][h[p[v[t+1]]]];
                sum+=dis[v.back()][h[i]];
                if(sum!=dis[0][h[i]]) fl=0;
                if(fl){
                    for(int t=0;t<(1<<k);t++) if(dp[t]) nxt[t|j]=1;
                }
            }
            swap(nxt,dp);
        }
        int mx=0;
        for(int i=0;i<(1<<k);i++) if(dp[i]) mx=max(mx,__builtin_popcount(i));
        printf("%d\n",k-mx);
    }
    return 0;
}