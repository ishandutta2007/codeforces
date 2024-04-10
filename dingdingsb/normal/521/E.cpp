#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=2e5+100;
int n,m;
vector<int>e[N];
int dfn[N],fa[N],dep[N];
int cnt=0;
int col[N];
bool vis[N];
pair<int,int>ee[N];
int tot=0;
void dfs(int u){
	dfn[u]=++cnt;dep[u]=dep[fa[u]]+1;
	for(auto v:e[u])if(v!=fa[u]){
		if(!dfn[v])
			fa[v]=u,dfs(v);
		else if(dfn[v]<dfn[u])
			ee[++tot]={u,v};
	}
}
void upd(int x,int y,int c){
	while(dep[x]!=dep[y]){
		if(dep[y]>dep[x])swap(x,y);
		assert(dep[x]>dep[y]);
		col[x]=c;x=fa[x];
	}
	while(x!=y){
		col[x]=col[y]=c;
		x=fa[x];y=fa[y];
	}
}
int get(int x,int y){
	//
	while(dep[x]!=dep[y]){
		if(dep[y]>dep[x])swap(x,y);
		assert(dep[x]>dep[y]);
		if(col[x])return col[x];
		x=fa[x];
	}
	while(x!=y){
		if(col[x])return col[x];
		if(col[y])return col[y];
		x=fa[x];y=fa[y];
	}
	return 0;
}
bool t1[N],t2[N];//_
void dfs2(int u,int _,bool *t){
	t[u]=col[u]==_;
	for(auto v:e[u])
		if(fa[v]==u)t[u]|=col[v]==_,dfs2(v,_,t);
}
void print(vector<int>&a){
	write(a.size());putchar(' ');
	for(auto x:a)write(x),putchar(' ');
	putchar('\n');
}
signed main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		int u,v;read(u,v);
		e[u].push_back(v);e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!dfn[i]){
		tot=0;dfs(i);
		for(int j=1,_;j<=tot;j++){
			if((_=get(ee[j].first,ee[j].second))==0)
				upd(ee[j].first,ee[j].second,j);
			else{
				puts("YES");
				dfs2(i,_,t1);
				upd(ee[j].first,ee[j].second,j);
				dfs2(i,j,t2);
				int st=0;
				vector<int>ans1,ans2,ans3;
				for(int k=1;k<=n;k++)
					if(dep[k]>=dep[st]&&t1[k]&&t2[k])
						st=k;
				queue<int>q;q.push(st);
				while(q.size()){
					int u=q.front();q.pop();
					vis[u]=1;ans1.push_back(u);
					for(auto v:e[u])
						if(t1[v]&&t2[v]&&!vis[v]
							&&(fa[u]==v||fa[v]==u))
							q.push(v);
				}
				int ed=*ans1.rbegin();
				q.push(st);memset(vis,0,sizeof vis);
				while(q.size()){
					int u=q.front();q.pop();
					vis[u]=1;ans2.push_back(u);
					for(auto v:e[u])
						if((t1[v]&&!t2[v])&&!vis[v]
							&&(fa[u]==v||fa[v]==u||
								v==ee[_].first&&u==ee[_].second||
								v==ee[_].second&&u==ee[_].first))
							q.push(v);
				}
				ans2.push_back(ed);
				q.push(st);memset(vis,0,sizeof vis);
				while(q.size()){
					int u=q.front();q.pop();
					vis[u]=1;ans3.push_back(u);
					for(auto v:e[u])
						if((!t1[v]&&t2[v])&&!vis[v]
							&&(fa[u]==v||fa[v]==u||
								v==ee[j].first&&u==ee[j].second||
								v==ee[j].second&&u==ee[j].first))
							q.push(v);
				}
				ans3.push_back(ed);
				print(ans1);
				print(ans2);
				print(ans3);
				return 0;
			}
		}
	}
	puts("NO");
}