#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int n,m,ans[200010],ed[200010][2];
vector<pair<int,int> > G[200010];
bool vis[200010];
int dep[200010],fae[200010];
map<pair<int,int>,int> mp;
int cntE;vector<int> nd;
void dfs(int x){
    vis[x]=1;
    for(auto ed:G[x]){
        int to=ed.first;
        if(ans[ed.second]!=-1) continue;
        if(vis[to]){
            ans[ed.second]=1;
            cntE++;
            nd.push_back(x);
            nd.push_back(to);
        }
        else{
            dep[to]=dep[x]+1;
            ans[ed.second]=0;
            fae[to]=ed.second;
            dfs(to);
        }
    }
}
bool cmp(int x,int y){return dep[x]<dep[y];}
void solve(){mp.clear();cntE=0;nd.clear();
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) G[i].clear(),vis[i]=0;
    for(int i=1,x,y;i<=m;i++){
        ans[i]=-1;
        scanf("%d %d",&x,&y);
        G[x].push_back({y,i});
        G[y].push_back({x,i});
        ed[i][0]=x;ed[i][1]=y;
        mp[{x,y}]=mp[{y,x}]=i;
    }dfs(1);
    sort(nd.begin(),nd.end());
    nd.erase(unique(nd.begin(),nd.end()),nd.end());
    if(nd.size()==3&&cntE==3){
        sort(nd.begin(),nd.end(),cmp);
        ans[fae[nd[1]]]^=1;
        ans[mp[{nd[0],nd[1]}]]^=1;
    }
    for(int i=1;i<=m;i++) printf("%d",ans[i]);
    puts("");
}
int main(){int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}