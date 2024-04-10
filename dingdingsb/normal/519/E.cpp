//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define TP int
inline TP read(){
	TP x=0;char c=getchar();bool k=false;
	for(;!isdigit(c);c=getchar())k|=c=='-';
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
	if(k)x=-x;return x;
}
void write(TP x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e5+100;
struct Graph{
	struct node{
		int v;
		int nxt;
	}e[2*maxn];
	int head[maxn],cnt;
	void add(int u,int v){
		cnt++;
		e[cnt].v=v;e[cnt].nxt=head[u];
		head[u]=cnt;
		
		swap(u,v);
		cnt++;
		e[cnt].v=v;e[cnt].nxt=head[u];
		head[u]=cnt;
		
	}
};
int n;
int lg[maxn];
struct LCA{
	Graph G;
	int fa[maxn][20];
	int deep[maxn];
	int size[maxn];
	void dfs(int rt){
		//printf("%d\n",rt);
		size[rt]=1;
		deep[rt]=deep[fa[rt][0]]+1;
		for(int i=1;i<=lg[deep[rt]];++i)
			fa[rt][i]=fa[fa[rt][i-1]][i-1];
		for(int i=G.head[rt];i;i=G.e[i].nxt)
			if(G.e[i].v!=fa[rt][0])
				fa[G.e[i].v][0]=rt,dfs(G.e[i].v),size[rt]+=size[G.e[i].v];
	}
	void init(int rt){
		deep[0]=0;
		dfs(rt);
	}
	inline int getLCA(int x,int y){
		//x
		//printf(" %d %d %d %d \n",x,y,deep[x],deep[y]);
		if(deep[x]<deep[y])
			swap(x,y);
		//printf(" %d %d %d %d \n",x,y,deep[x],deep[y]);
		while(deep[x]>deep[y])
			x=fa[x][lg[deep[x]-deep[y]]-1];
		//printf(" %d %d %d %d \n",x,y,deep[x],deep[y]);
		if(x==y)return x;
		for(int i=lg[deep[x]]-1;i>=0;i--)
			if(fa[x][i]!=fa[y][i])
				x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
	inline int getFA(int x,int k){
		//xk
		while (k)
			x=fa[x][lg[k]-1],k-=1<<(lg[k]-1);
		return x;
	}
}T;int m;
signed main(){
	for(int i=1;i<maxn;i++)
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	n=read();
	for(int i=1;i<n;i++)
		T.G.add(read(),read());
	m=read();
	T.init(1);
	for(int i=1;i<=m;i++){
		int a,b;
		a=read(),b=read();
		if(a==b)write(n),putchar('\n');
		else if((T.deep[a]&1)!=(T.deep[b]&1))write(0),putchar('\n');
		else{
			if(T.deep[a]<T.deep[b])
				swap(a,b);
			//a 
			int lca=T.getLCA(a,b);
			//printf("********   lca:%d\n",lca);
			int path=T.deep[a]+T.deep[b]-2*T.deep[lca];
			//printf("********   path:%d\n",path);
			if(T.deep[a]==T.deep[b]){
				//printf("%d %d %d %d\n",T.getFA(a,(path>>1)-1),T.size[T.getFA(a,(path>>1)-1)],T.getFA(b,(path>>1)-1),T.size[T.getFA(b,(path>>1)-1)]);
				write(n-T.size[T.getFA(a,(path>>1)-1)]-T.size[T.getFA(b,(path>>1)-1)]);
				putchar('\n');
			}
			else{
				int fa=T.getFA(a,(path>>1)-1);
				write(T.size[T.fa[fa][0]]-T.size[fa]);
				putchar('\n');
			}
		}
	}
}