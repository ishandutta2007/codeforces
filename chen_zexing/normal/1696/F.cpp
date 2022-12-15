#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
#include <bitset>
using namespace std;
int bi[105][105][105];
int dis[105][105];
char s[105];
int fa[20005],sz[20005],n;
int id(int x,int y){
    if(x>y) swap(x,y);
    return x*101+y;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector <pair<int,int>> v[20005];
vector <int> e[105];
int vis[105];
void dfs(int x,int from,int d,int st){
    dis[st][x]=d,vis[x]=1;
    for(auto t:e[x])
        if(t!=from&&!vis[t])
            dfs(t,x,d+1,st);
}
int check(int p){
    for(int i=1;i<=n;i++) e[i].clear();
    for(auto t:v[p]){
        e[t.first].push_back(t.second);
        e[t.second].push_back(t.first);
    }
    for(int i=1;i<=n;i++) memset(vis,0,sizeof(vis)),memset(dis[i],-1,sizeof(dis)),dfs(i,0,0,i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n-i;j++)
            for(int k=1;k<=n;k++)
                if((dis[i][k]==dis[i+j][k])!=bi[i][i+j][k]&&dis[i][k]!=-1&&dis[i+j][k]!=-1)
                    return 0;
    return 1;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n-i;j++){
                scanf("%s",s+1);
                for(int k=1;k<=n;k++) bi[i][i+j][k]=s[k]-'0';
            }
        if(n==2){
            if(bi[1][2][1]==0&&bi[1][2][2]==0) puts("Yes"),puts("1 2");
            else puts("No");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                assert(id(i,j)<=20000),fa[id(i,j)]=id(i,j),sz[id(i,j)]=1,v[id(i,j)].clear();
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(bi[i][j][k]==1){
                        int x=find(id(i,k)),y=find(id(j,k));
                        if(x!=y) fa[y]=x,sz[x]+=sz[y];
                    }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                v[find(id(i,j))].push_back(make_pair(i,j));
        int f=0;
        for(int i=1;i<=n&&!f;i++)
            for(int j=i+1;j<=n;j++)
                if(fa[id(i,j)]==id(i,j)&&v[id(i,j)].size()==n-1){
                    //cout<<i<<" "<<j<<endl;
                    if(check(id(i,j))){
                        puts("Yes");
                        for(auto t:v[id(i,j)])
                            printf("%d %d\n",t.first,t.second);
                        f=1;
                        break;
                    }
                }
        if(!f) puts("No");
    }
    return 0;
}
//cf