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
using namespace std;
int p[200005],rk[200005];
struct node{
    int x,y;
    friend bool operator <(node a,node b){
        assert(a.x==b.x&&a.y!=a.x&&b.y!=a.x);
        if(rk[a.y]>rk[a.x]) return rk[b.y]>rk[a.y]||rk[b.y]<rk[a.x];
        else return rk[b.y]>rk[a.y]&&rk[b.y]<rk[a.x];
    }
};
vector <node> v[200005];
map <pair<int,int>,int> mp;
vector <int> vv[200005],e[200005];
int in[200005];
void dfs(int x){
    if(!rk[vv[x][0]]) rk[vv[x][0]]=rk[x]+1,dfs(vv[x][0]);
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            vv[i].push_back(p[i]);
        }
        for(int i=1;i<=n;i++) if(!rk[i]) rk[i]=1,dfs(i);
        for(int i=1;i<=n;i++) assert(rk[i]);
        for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),v[x].push_back(node{x,y}),v[y].push_back(node{y,x}),mp[make_pair(min(x,y),max(x,y))]=i;
        for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end());
        for(int i=1;i<=n;i++)
            for(int j=0;j<int(v[i].size())-1;j++)
                e[mp[make_pair(min(v[i][j].x,v[i][j].y),max(v[i][j].x,v[i][j].y))]].push_back(mp[make_pair(min(v[i][j+1].x,v[i][j+1].y),max(v[i][j+1].x,v[i][j+1].y))]),in[mp[make_pair(min(v[i][j+1].x,v[i][j+1].y),max(v[i][j+1].x,v[i][j+1].y))]]++;
        queue <int> q;
        for(int i=1;i<=m;i++) if(in[i]==0) q.push(i);
        while(!q.empty()){
            int temp=q.front();
            printf("%d ",temp),q.pop();
            for(auto x:e[temp]){
                in[x]--;
                if(in[x]==0) q.push(x);
            }
        }
    }
    return 0;
}