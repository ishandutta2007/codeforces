#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int f=1,num=0;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1; ch=getchar();}
    while(isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
int tot,head[5000003],nxt[1000003],to[1000003];
int sz[500003],son[500003],dis[500003],dep[500003],fa[500003][18];
int n,m;
char a[500003];
inline void addedge(int x,int y){ nxt[++tot]=head[x],head[x]=tot,to[tot]=y; }
void dfs1(int x)
{
	for(int i=1; i<=17; ++i) fa[x][i]=fa[fa[x][i-1]][i-1];
    sz[x]=1;
    for(int i=head[x]; i; i=nxt[i])
    {
        int y=to[i];
        if(y==fa[x][0])continue;
        fa[y][0]=x,dep[y]=dep[x]+1,dfs1(y),sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
    return ;
}
int cnt[500003],ans[500003];
int qwqwq;
string s[100003];
map<pair<string,int>,int> mp;
void calc(int x,int fa,int op) 
{
  	if(op==1) (mp[make_pair(s[x],dep[x])]++==0)&&(++cnt[dep[x]]); else (--mp[make_pair(s[x],dep[x])]==0)&&(--cnt[dep[x]]);
  	for(int i=head[x]; i; i=nxt[i]) if(to[i]!=fa&&to[i]!=qwqwq) calc(to[i],x,op);
}
struct node{int first,second;};
vector<node> v[500003];
void solve(int x,int fa,int op) 
{
   	for(int i=head[x]; i; i=nxt[i]) if(to[i]!=fa&&to[i]!=son[x]) solve(to[i],x,0);
  	if(son[x]) solve(son[x],x,1),qwqwq=son[x]; calc(x,fa,1);
  	qwqwq=0;
	for(auto q:v[x]) ans[q.first]=cnt[dep[x]+q.second];
  	if(!op) calc(x,fa,0); 
}
int zkyakioi(int x,int y)
{
	for(int i=17,t=1<<17; i>=0; --i,t>>=1) if(y&t) x=fa[x][i];
	return x;
}
vector<int> qwq;
signed main()
{
    n=read();
	for(int i=1,x,y; i<=n; ++i) 
	{
		cin>>s[i];
		x=read(),y=i;
		if(x==0) {qwq.push_back(i);continue;}
		addedge(x,y),addedge(y,x);
	}
	m=read();
	for(int awa:qwq) fa[awa][0]=awa,dfs1(awa);
	for(int i=1,x,k; i<=m; ++i) 
	{
		x=read(),k=read();
		v[x].push_back((node){i,k});
	}
	for(int awa:qwq) solve(awa,0,0);
	for(int i=1; i<=m; ++i) printf("%d ",ans[i]);
    return 0;
}