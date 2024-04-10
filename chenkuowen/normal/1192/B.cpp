#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e6;
const ll DINF=0xcfcfcfcfcfcfcfcf;
struct Matrix{
	ll a[3][3];
	inline ll* operator[](int x){ return a[x]; }
	Matrix(){ memset(a,0xcf,sizeof(a)); }
	void gbase(){
		for(int i=0;i<3;++i) a[i][i]=0;
	}
	inline Matrix operator*(Matrix b){
		Matrix c;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				for(int k=0;k<3;++k)
					c[i][j]=max(c[i][j],a[i][k]+b[k][j]);
		return c;
	}
	inline Matrix operator|(Matrix b){
		Matrix c;
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				c[0][j]=max(c[0][j],a[0][k]+b[k][j]);
		return c;
	}
	void print(){
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j)
				printf("(%lld)",a[i][j]);
			puts("");
		}
	}
};	
struct HP{
	priority_queue<ll> q,rq;
	inline ll top(){
		while(!rq.empty()&&q.top()==rq.top())
			q.pop(),rq.pop();
		return q.top();
	}
	inline void erase(ll key){ rq.push(key); }
	inline void pop(){ erase(top()); }
	inline void push(ll key){ q.push(key); }
	inline int size(){ return q.size()-rq.size(); }
	inline ll query(){
		if(size()==0) return 0;
		if(size()==1) return top();
		ll x=top(); pop();
		ll ret=x+top();
		push(x);
		return ret;
	}
};
struct Graph{
	struct Edge{ int to,nxt; ll d; }edge[MAX_N*2];
	int head[MAX_N],top;
	Graph(){ memset(head,-1,sizeof(head)); top=-1; }
	inline void add(int x,int y,ll d){
		edge[++top]=(Edge){y,head[x],d};
		head[x]=top;
	}
}G;
ll dhs[MAX_N],f[MAX_N][3],d[MAX_N],gd[MAX_N];
int dep[MAX_N],hs[MAX_N],fa[MAX_N];
int lsz[MAX_N],sz[MAX_N],n,pos[MAX_N];
void dfs(int x,int pre){
	fa[x]=pre; dep[x]=dep[pre]+1; hs[x]=0; sz[x]=1;
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			pos[j>>1]=y;
			d[y]=G.edge[j].d;
			dfs(y,x); sz[x]+=sz[y];
			if(sz[hs[x]]<sz[y]) hs[x]=y;
		}
	}
	lsz[x]=sz[x]-sz[hs[x]];
	dhs[x]=d[hs[x]];
}
struct GT{
	struct Node{
		Matrix key,sum;
		HP t,t2;
		int son[2],fa;
		bool mark;
	}tree[MAX_N];
	GT(){ tree[0].sum.gbase(); }
	inline void up(int x){
		tree[x].sum=tree[tree[x].son[1]].sum
			*tree[x].key*tree[tree[x].son[0]].sum;
	}
	inline void get_mark(int x){
		tree[x].mark=tree[tree[x].fa].son[0]==x||tree[tree[x].fa].son[1]==x;
	}
	int rt;
	void build(){ 
		rt=build(1,0,0); 
		for(int i=1;i<=n;++i) get_mark(i);
	}
	Matrix get(int x){
		Matrix c; c[0][0]=c[0][1]=c[0][2]=0;
		c=c|tree[x].sum;
		return c;
	}
	void updata(int i){
		tree[i].key[0][0]=dhs[i];
		tree[i].key[0][2]=tree[i].t.top()+dhs[i];
		tree[i].key[1][0]=tree[i].t.top();
		tree[i].key[1][1]=0;
		tree[i].key[1][2]=max(tree[i].t2.top(),tree[i].t.query());
		tree[i].key[2][2]=0;
		up(i);
	}
	int build(int x,int y,int pre){
		if(x==y) return 0; int i=x;
//		printf("(%d %d %d)\n",x,y,pre);
		for(;hs[i]!=y;i=hs[i]);
		for(;i!=fa[x];i=fa[i])
			sz[i]=(hs[i]==y?0:sz[hs[i]])+lsz[i];
		int dsz=sz[x]>>1;
		for(i=x;i!=y;i=hs[i])
			if(sz[x]-sz[i]<=dsz&&(hs[i]==y||sz[hs[i]]<=dsz)){
//				printf("[%d]\n",i);
				tree[i].t.push(0);
				tree[i].t2.push(0);
				tree[i].fa=pre; 
				tree[i].son[0]=build(x,i,i);
				tree[i].son[1]=build(hs[i],y,i);
				ll mx=0;
				for(int j=G.head[i];~j;j=G.edge[j].nxt){
					int t=G.edge[j].to;
					if(t!=fa[i]&&t!=hs[i]){
						t=build(t,0,i);
						gd[t]=G.edge[j].d;
						Matrix c=get(t);
						tree[i].t.push(c[0][0]+G.edge[j].d);
						tree[i].t2.push(c[0][2]);
					}
				}
	//			printf("(%d %lld)",i,tree[i].t.top());
				updata(i);
				Matrix c=get(i);
				f[i][0]=c[0][0]; 
				f[i][1]=c[0][2];
//				printf("{%d %lld %lld}\n",i,f[i][0],f[i][1]);
//				tree[i].key.print();
				return i;
			}
	}
	ll query(){  return f[rt][1]; }
	void change(int x,ll dis){
		if(x!=hs[fa[x]]){
//			puts("A");
			int y=x;
			while(tree[y].mark) y=tree[y].fa;
			tree[fa[x]].t.erase(f[y][0]+gd[y]);
			tree[fa[x]].t.push(f[y][0]+dis);
			gd[y]=dis;
		}else dhs[fa[x]]=dis;
		d[x]=dis;
		updata(fa[x]);
		x=fa[x];
		for(;x;x=tree[x].fa){
//			printf("(%d)\n",x); puts("");
//			tree[x].key.print();
			up(x);
			if(!tree[x].mark){
//				puts("A");
				if(tree[x].fa!=0){
					tree[tree[x].fa].t.erase(f[x][0]+gd[x]);
					tree[tree[x].fa].t2.erase(f[x][1]);
				}
				Matrix c=get(x); 
				f[x][0]=c[0][0],f[x][1]=c[0][2];
//				printf("|%d %lld %lld|",x,f[x][0],f[x][1]);
				if(tree[x].fa!=0){
					tree[tree[x].fa].t.push(f[x][0]+gd[x]);
					tree[tree[x].fa].t2.push(f[x][1]);
					updata(tree[x].fa);
				}
			} 
		}
//		puts("");
//		tree[3].key.print();
//		Matrix c;
//		c[0][0]=c[0][1]=c[0][2]=0;
//		c=c|(tree[4].key*tree[3].key*tree[2].key*tree[1].key);
//		printf("<%lld %lld %lld>",c[0][0],c[0][1],c[0][2]);
		
	}
}gt;
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int q; ll w;
	scanf("%d%d%lld",&n,&q,&w);
	for(int i=1;i<n;++i){
		int x,y; ll d; scanf("%d%d%lld",&x,&y,&d);
		G.add(x,y,d); G.add(y,x,d);
	}
	dfs(1,0);
	gt.build();
//	printf("%lld\n",gt.query());
	ll last=0;
	while(q--){
		ll d,e; scanf("%lld%lld",&d,&e);
		d=pos[(d+last)%(n-1)];
		e=(e+last)%w;
//		printf("(%lld %lld)\n",d,e);
		gt.change(d,e);
		printf("%lld\n",last=gt.query());
	}
	return 0;
}