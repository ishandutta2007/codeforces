#pragma GCC optimize("Ofast,unroll-loops")
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
using namespace std;
vector <int> e[100005];
int fa[100005],f[200005];
int ff[100005][20],cc,id[100005],dep[100005],tag[100005],sz[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs(int x,int from){
    ff[x][0]=from,id[x]=++cc,dep[x]=dep[from]+1,sz[x]=1;
    for(auto t:e[x])
        if(t!=from)
            dfs(t,x),sz[x]+=sz[t];
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--) if(dep[ff[x][i]]>=dep[y]) x=ff[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(ff[x][i]!=ff[y][i]) x=ff[x][i],y=ff[y][i];
    return ff[x][0];
}
int x[200005],y[200005];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1,xx,yy;i<=m;i++){
            scanf("%d%d",&x[i],&y[i]);
            xx=find(x[i]),yy=find(y[i]);
            if(xx!=yy) fa[yy]=xx,f[i]=1,e[x[i]].push_back(y[i]),e[y[i]].push_back(x[i]);
            else f[i]=0;
        }
        dfs(1,0);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                ff[j][i]=ff[ff[j][i-1]][i-1];
        for(int i=1;i<=m;i++)
            if(!f[i]){
                int xx=x[i],yy=y[i];
                //cout<<xx<<" "<<yy<<endl;
                if(dep[xx]<dep[yy]) swap(xx,yy);
                int l=lca(xx,yy);
                if(l!=yy){
                    tag[1]++,tag[n+1]--;
                    tag[id[xx]]--,tag[id[xx]+sz[xx]]++;
                    tag[id[yy]]--,tag[id[yy]+sz[yy]]++;
                }
                else{
                    int temp=xx;
                    for(int j=19;j>=0;j--) if(ff[temp][j]!=yy&&dep[ff[temp][j]]>dep[yy]) temp=ff[temp][j];
                    tag[id[temp]]++,tag[id[temp]+sz[temp]]--;
                    //cout<<temp<<" "<<id[temp]<<" "<<id[temp]+sz[temp]<<endl;
                    tag[id[xx]]--,tag[id[xx]+sz[xx]]++;
                }
            }
        for(int i=1;i<=n;i++){
            tag[i]+=tag[i-1];
            //cout<<i<<" "<<tag[i]<<endl;
        }
        for(int i=1;i<=n;i++){
            printf("%d",tag[id[i]]==0?1:0);
        }
        puts("");
    }
    return 0;
}
//unordered_map
//cf