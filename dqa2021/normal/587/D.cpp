#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
#define forall(x,i) for (int i=0,_t=x.size();i<_t;i++)
#define foralld(x,i) for (int i=x.size()-1;i>=0;i--)
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n,m;
int bin[50010],bintop;
vector<int> d[50010];
struct Rec{
	int u,v,c,t;
}r[50010];
bool cmp(const int &x,const int &y){return r[x].c<r[y].c;}
bool cmp2(const int &x,const int &y){return r[x].t<r[y].t;}
vector<int> e[50010];
int findcoltot(int x,int c){
	r[0].c=c;
	int pos=lower_bound(e[x].begin(),e[x].end(),0,cmp)-e[x].begin();
	if (pos>=e[x].size()) return 0;
	if (r[e[x][pos]].c^c) return 0;
	if (pos+1>=e[x].size()||r[e[x][pos+1]].c^c) return 1;
	return 2;
}
int getcolpos(int x,int c){
	r[0].c=c;
	int pos=lower_bound(e[x].begin(),e[x].end(),0,cmp)-e[x].begin();
	return pos;
}

struct Edge{
	int to,nxt;
}edge[5000000];
int cnt,last[1000010]; int nodetot;
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int vis[1000010],tim;
int edgeid[50010],etop;
void dfs1(int x,int c){
	vis[x]=tim;
	int pos=getcolpos(x,c),v=r[e[x][pos]].u^r[e[x][pos]].v^x;
	if (vis[v]^tim) edgeid[++etop]=e[x][pos],dfs1(v,c);
	pos++; if (pos>=e[x].size()||r[e[x][pos]].c^c) return;
	v=r[e[x][pos]].u^r[e[x][pos]].v^x;
	if (vis[v]^tim) edgeid[++etop]=e[x][pos],dfs1(v,c);
}

void work(int x){
	int pos;
	forall(e[x],i){
		int id=e[x][i];
		++nodetot;
		if (i) addedge(pos,nodetot),addedge(pos,id);
		pos=nodetot;
		addedge(id+m,pos);
	}
	forall(e[x],i){
		int id=e[x][i];
		++nodetot;
		if (i) addedge(nodetot,pos),addedge(id+m,pos);
		pos=nodetot;
		addedge(pos,id);
	}
	foralld(e[x],i){
		int id=e[x][i];
		++nodetot;
		if (i+1<e[x].size()) addedge(pos,nodetot),addedge(pos,id);
		pos=nodetot;
		addedge(id+m,pos);
	}
	foralld(e[x],i){
		int id=e[x][i];
		++nodetot;
		if (i+1<e[x].size()) addedge(nodetot,pos),addedge(id+m,pos);
		pos=nodetot;
		addedge(pos,id);
	}
	forall(e[x],i){
		int u=e[x][i],v;
		if (i){
			v=e[x][i-1];
			if (r[u].c==r[v].c) addedge(u,v+m),addedge(v,u+m);
		}
	}
}

int dfn[1000010],low[1000010];
int stk[1000010];
int coltot,col[1000010];
bool isM; bool visited_146;
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	vis[x]=tim; stk[++*stk]=x;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if (!dfn[v=edge[i].to]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if (vis[v]==tim) low[x]=min(low[x],dfn[v]);
	if (dfn[x]^low[x]) return;
	++coltot;
	do{
		int u=stk[*stk];
		vis[u]=0; col[u]=coltot;
	}while (stk[(*stk)--]^x);
}

int ansbin[50010],ansbintop;
int id[50010];
bool check(int M){  //init
	nodetot=m+m; cnt=0;
	for (int i=M+1;i<=m;i++) addedge(m+id[i],id[i]);
	for (int i=1;i<=bintop;i++){
		++tim;
		forall(d[i],j){
			if (vis[d[i][j]]^tim){
				if (findcoltot(d[i][j],i)==2) continue;
				etop=0;
				dfs1(d[i][j],i);
				int t=++nodetot;
				for (int u=2;u<=etop;u+=2) addedge(t,m+edgeid[u]);
				for (int u=1;u<=etop;u+=2) addedge(edgeid[u],t);
				t=++nodetot;
				for (int u=1;u<=etop;u+=2) addedge(t,m+edgeid[u]);
				for (int u=2;u<=etop;u+=2) addedge(edgeid[u],t);
			}
		}
		forall(d[i],j){
			if (vis[d[i][j]]^tim){
				etop=0;
				dfs1(d[i][j],i);
				int t=++nodetot;
				for (int u=2;u<=etop;u+=2) addedge(t,m+edgeid[u]);
				for (int u=1;u<=etop;u+=2) addedge(edgeid[u],t);
				t=++nodetot;
				for (int u=1;u<=etop;u+=2) addedge(t,m+edgeid[u]);
				for (int u=2;u<=etop;u+=2) addedge(edgeid[u],t);
			}
		}
	}
	for (int i=1;i<=n;i++) work(i);
	++tim; coltot=0;
	for (int i=0;i<=nodetot;i++) dfn[i]=0;
	for (int i=1;i<=nodetot;i++)
		if (!dfn[i])
			tarjan(i);
	for (int i=1;i<=nodetot;i++) last[i]=0;
	for (int i=1;i<=m;i++) if (col[i]==col[i+m]) return 0;
	ansbintop=0;
	for (int i=1;i<=m;i++) if (col[i+m]<col[i]) ansbin[++ansbintop]=i;
	return 1;
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),c=read(),t=read();
		r[i]=(Rec){u,v,c,t};
		e[u].pb(i); e[v].pb(i);
		bin[++bintop]=c;
		id[i]=i;
	}
	sort(bin+1,bin+bintop+1);
	bintop=unique(bin+1,bin+bintop+1)-bin-1;
	for (int i=1;i<=m;i++){
		int &c=r[i].c;
		c=lower_bound(bin+1,bin+bintop+1,c)-bin;
		d[c].pb(r[i].u); d[c].pb(r[i].v);
	}
	for (int i=1;i<=bintop;i++){
		sort(d[i].begin(),d[i].end());
		int t=unique(d[i].begin(),d[i].end())-d[i].begin();
		d[i].resize(t);
	}
	sort(id+1,id+m+1,cmp2);
	for (int i=1;i<=n;i++){
		sort(e[i].begin(),e[i].end(),cmp);
		forall(e[i],j) if (j+2<_t&&!cmp(e[i][j],e[i][j+2])) return puts("No"),0;
	}
	int L=0,R=m,Mid,ans=-1;
	while (L<=R){
		Mid=L+R>>1;
		if (check(Mid)) ans=Mid,R=Mid-1;
		else L=Mid+1;
	}
	if (!~ans) return puts("No"),0;
	puts("Yes");
	printf("%d %d\n",r[id[ans]].t,ansbintop);
	for (int i=1;i<=ansbintop;i++) printf("%d ",ansbin[i]);
	puts("");
	return 0;
}