#include<bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int n,m,dfn[N],tot;
vector<int>g[N],ans;
int sz,vec[N],SZ,VEC[N];
queue<int>q;
void sol(){
    int s=vec[sz--],cnt=0;
    queue<int>q;q.push(s);
    while(!q.empty()){
        SZ=0,++cnt,++tot;
        int u=q.front();q.pop();
        for(auto v:g[u])dfn[v]=tot;
        for(int i=1;i<=sz;i++){
            int x=vec[i];
            if(dfn[x]!=tot)q.push(x);
            else VEC[++SZ]=x;
        }
        sz=SZ;
        memcpy(vec+1,VEC+1,sz<<2);
    }
    ans.push_back(cnt);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        g[u].push_back(v),g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)vec[++sz]=i;
    while(sz)sol();
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto x:ans)printf("%d ",x);
}