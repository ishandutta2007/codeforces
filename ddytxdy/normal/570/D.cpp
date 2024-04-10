#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
int n,m,ver[N],nxt[N],head[N],tot,d[N],sz[N],son[N],num[N][26],dat[N],st[N],tp,ans[N];char c[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
vector<pair<int,int> >v[N];
void dfs(int x){
    sz[x]=1;
    for(int i=head[x],y;i;i=nxt[i])d[y=ver[i]]=d[x]+1,
        dfs(y),sz[x]+=sz[y],sz[y]>sz[son[x]]?son[x]=y:0;
}
void change(int x){num[d[x]][c[x]]^=1;num[d[x]][c[x]]?dat[d[x]]++:dat[d[x]]--;}
void dfs3(int x){
    change(x);st[++tp]=x;
    for(int i=head[x];i;i=nxt[i])dfs3(ver[i]);
}
void dfs2(int x){
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=son[x]){
            dfs2(y);while(tp)change(st[tp--]);
        }
    if(son[x])dfs2(son[x]);
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=son[x])dfs3(y);
    change(x);st[++tp]=x;
    for(int i=0;i<v[x].size();i++)
        ans[v[x][i].first]=dat[v[x][i].second]<2;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)add(read(),i);
    scanf("%s",c+1);for(int i=1;i<=n;i++)c[i]-='a';
    for(int i=1,x,y;i<=m;i++)x=read(),y=read(),v[x].push_back(make_pair(i,y));
    dfs(d[1]=1);dfs2(1);
    for(int i=1;i<=m;i++)puts(ans[i]?"Yes":"No");
    return 0;
}