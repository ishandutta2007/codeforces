#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
#define id(x,y) ((x-1)*m+y)
int n,m,dis[2510],nxt[4][2]={{0,1},{0,-1},{1,0},{-1,0}},ans=2e9;
char ch[60][60];
vector<pair<int,int> > G[2510];
deque<int> Q;
bool vis[2510];
void BFS(int x){
    for(int i=1;i<=n*m;i++) dis[i]=2e9;
    memset(vis,0,sizeof(vis));
    Q.push_back(x);dis[x]=1;
    int maxn=0;
    while(!Q.empty()){
        int t=Q.front();Q.pop_front();
        if(vis[t]) continue;
        if(ch[(t-1)/m+1][(t-1)%m+1]=='B') maxn=max(maxn,dis[t]);
        vis[t]=1;
        for(auto to:G[t]){
            // printf("T %d\n",to.first);
            if(vis[to.first]) continue;
            int d=dis[t]+to.second;
            if(d<dis[to.first]){
                dis[to.first]=d;
                if(!to.second) Q.push_front(to.first);
                else Q.push_back(to.first);
            }
        }
    }
    // printf("%d\n",maxn);
    ans=min(ans,maxn);
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=0;k<4;k++){
                int nx=i+nxt[k][0],ny=j+nxt[k][1];
                if(nx<1||nx>n||ny<1||ny>m) continue;
                // printf("%d %d %d %d\n",i,j,nx,ny);
                G[id(i,j)].push_back(make_pair(id(nx,ny),(ch[i][j]!=ch[nx][ny])));
            }
        }
    }
    for(int i=1;i<=n*m;i++) BFS(i);
    printf("%d",ans);
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}