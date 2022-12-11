#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,ver[N],nxt[N],head[N],tot,a[N],q,sz[N],son[N],d[N],num[N],st[N],tp,ans[N];
string s[N],t[N];
vector<pair<int,int> >v[N];
map<int,int>se[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
void dfs(int x){
    sz[x]=1;
    for(int i=head[x],y;i;i=nxt[i])d[y=ver[i]]=d[x]+1,
        dfs(y),sz[x]+=sz[y],sz[y]>sz[son[x]]?son[x]=y:0;
}
void change(int x){if(!se[d[x]][a[x]])num[d[x]]++;se[d[x]][a[x]]++;st[++tp]=x;}
void dfs3(int x){
    change(x);
    for(int i=head[x];i;i=nxt[i])dfs3(ver[i]);
}
void dfs2(int x){
    for(int i=head[x],y;i;i=nxt[i])
        if((y=ver[i])!=son[x]){
            dfs2(y);
            while(tp){
                int x=st[tp--];
                se[d[x]][a[x]]--;
                if(!se[d[x]][a[x]])num[d[x]]--;
            }
        }
    if(son[x])dfs2(son[x]);
    for(int i=head[x],y;i;i=nxt[i])if((y=ver[i])!=son[x])dfs3(y);
    change(x);
    for(int i=0;i<v[x].size();i++)ans[v[x][i].first]=d[x]+v[x][i].second>n?0:num[d[x]+v[x][i].second];
}
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++)cin>>s[i]>>x,add(x,i),t[i]=s[i];
    sort(s+1,s+n+1);m=unique(s+1,s+n+1)-s-1;
    for(int i=1;i<=n;i++)a[i]=lower_bound(s+1,s+m+1,t[i])-s;
    scanf("%d",&q);
    for(int i=1,x,y;i<=q;i++)scanf("%d%d",&x,&y),v[x].push_back(make_pair(i,y));
    dfs(0);dfs2(0);for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}