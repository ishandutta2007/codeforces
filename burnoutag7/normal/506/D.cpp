#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100005];
map<int,int> f[100005];
map<pair<int,int>,int> mem;
int n,m,q;

int find(int &id,int x){
    if(f[id].find(x)==f[id].end()||f[id][x]==x)return f[id][x]=x;
    else return f[id][x]=find(id,f[id][x]);
}

void unite(int &id,int x,int y){
    x=find(id,x);
    y=find(id,y);
    if(x!=y)f[id][x]=y;
}

int main(){

    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        unite(c,a,b);
    }
    for(int i=1;i<=m;i++){
        for(map<int,int>::iterator it=f[i].begin();it!=f[i].end();it++){
            g[it->first].push_back(make_pair(i,it->second));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            g[i][j].second=find(g[i][j].first,i);
        }
    }
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(g[u].size()>g[v].size()||(g[u].size()==g[v].size()&&u>v))swap(u,v);
        if(mem.find(make_pair(u,v))!=mem.end()){
            printf("%d\n",mem[make_pair(u,v)]);
            continue;
        }
        int ans=0;
        for(int i=0;i<g[u].size();i++){
            if(binary_search(g[v].begin(),g[v].end(),g[u][i])){
                ans++;
            }
        }
        mem[make_pair(u,v)]=ans;
        printf("%d\n",ans);
    }

    return 0;
}