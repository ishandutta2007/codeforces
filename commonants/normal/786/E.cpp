#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

const int MX=20011,inf=0x3f3f3f3f;
struct Edge{int f,t;}e[MX];
int pool[MX<<1],*G[MX];
int D[MX],sz[MX],fa[MX];
int tp[MX],d[MX],cd[MX],dfn[MX],dfc;
int no[MX];
int n,m;
namespace flw{
	struct E{int t,c,f;E* r;E(int _t=0,int _c=0,E* _r=NULL):t(_t),c(_c),f(0),r(_r){}}pool[MX*37],*G[MX<<3],*cur[MX<<3];
	struct Edge{int f,t,c;E* x;Edge(int _f=0,int _t=0,int _c=0):f(_f),t(_t),c(_c){}}e[MX*19];int ec=0;
	int S,T,nm[MX<<3],cnt=0,n,D[MX<<3];
	int d[MX<<3],q[MX<<3],qd[MX<<3],vis[MX<<3],lvno[MX];
	void build(int no,int l,int r){
		nm[no]=++cnt;
		if(l==r)lvno[l]=nm[no]/*,printf("lvno[%d]=%d\n,l,lvno[l])"*/,e[++ec]=Edge(S,nm[no],1);
		else{
			int mid=(l+r)>>1;
			build(no<<1,l,mid);
			build(no<<1|1,mid+1,r);
			e[++ec]=Edge(nm[no<<1],nm[no],inf);
			e[++ec]=Edge(nm[no<<1|1],nm[no],inf);
		}
	}
	void ini(int _n){
		n=_n;
		memset(D,0,sizeof(D));
		S=++cnt,T=++cnt;
		build(1,1,n);
	}
	void ade(int no,int l,int r,int ll,int rr,int t){
		if(ll<=l&&rr>=r)e[++ec]=Edge(nm[no],t,inf);
		else{
			int mid=(l+r)>>1;
			if(ll<=mid)ade(no<<1,l,mid,ll,rr,t);
			if(rr>mid)ade(no<<1|1,mid+1,r,ll,rr,t);
		}
	}
	void ade(int l,int r,int no){
		ade(1,1,n,l,r,no);
	}
	int dfs(int k,int mx){
		if(k==T||mx==0)return mx;
		int ans=0;
		for(E* &i=cur[k];i!=G[k+1];i++){
			if(i->c>i->f&&d[i->t]==d[k]+1){
				int f=dfs(i->t,min(i->c-i->f,mx));
				//if(f)printf("%d %d\n",k,i->t);
				mx-=f,ans+=f,i->f+=f,i->r->f-=f;
				if(mx==0)break;
			}
		}
		if(!ans)d[k]=-1;
		return ans;
	}
	bool bfs(){
		memset(vis,0,sizeof(int)*(cnt+2));
		int h=0,t=0;
		q[++t]=S;qd[t]=1;vis[S]=1;
		while(h<t){
			int r=q[++h];
			d[r]=qd[h];
			for(E* i=G[r];i!=G[r+1];i++){
				if(!vis[i->t]&&i->c>i->f)q[++t]=i->t,qd[t]=qd[h]+1,vis[i->t]=1;
			}
		}
		return vis[T];
	}
	void buildg(){
		//for(int i=1;i<=ec;i++)printf("%d %d %d\n",e[i].f,e[i].t,e[i].c);
		for(int i=1;i<=ec;i++)++D[e[i].f],++D[e[i].t];
		G[1]=pool;for(int i=1;i<=cnt;i++)G[i+1]=G[i]+D[i];
		for(int i=1;i<=ec;i++){
			--D[e[i].f],--D[e[i].t];
			e[i].x=&G[e[i].f][D[e[i].f]];
			G[e[i].f][D[e[i].f]]=E(e[i].t,e[i].c,&G[e[i].t][D[e[i].t]]);
			G[e[i].t][D[e[i].t]]=E(e[i].f,0,&G[e[i].f][D[e[i].f]]);
		}
	}
	int dinic(){
		int ans=0;
		while(bfs()){
			memcpy(cur,G,sizeof(E*)*(cnt+2));
			ans+=dfs(S,inf);
		}
		return ans;
	}
};

void dfs(int k){
	sz[k]=1;
	for(int *i=G[k];i!=G[k+1];i++){
		if(*i!=fa[k]){
			fa[*i]=k;dfs(*i);sz[k]+=sz[*i];
		}
	}
}
void tcp(int k,int p,int dep,int dc){
	dfn[k]=++dfc;tp[k]=p;cd[k]=dc;d[k]=dep;
	int mx=0,mi=0;
	for(int *i=G[k];i!=G[k+1];i++){
		if(*i!=fa[k]&&sz[*i]>mx)mx=sz[*i],mi=*i;
	}
	if(mi)tcp(mi,p,dep+1,dc);
	else return;
	for(int *i=G[k];i!=G[k+1];i++){
		if(*i!=fa[k]&&*i!=mi)tcp(*i,*i,dep+1,dc+1);
	}
}
void ini(){
	dfs(1);
	tcp(1,1,1,1);
	flw::ini(dfc);
}
inline int rd(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
inline void pr(int x){
	char s[11];int c=0;
	while(x||!c)s[c++]=x%10+'0',x/=10;
	while(c)putchar(s[--c]);
}
int main(){
	n=rd(),m=rd();
	for(int i=1;i<n;i++){
		e[i].f=rd(),e[i].t=rd();
		++D[e[i].f],++D[e[i].t];
	}
	G[1]=pool;for(int i=1;i<=n;i++)G[i+1]=G[i]+D[i];
	for(int i=1;i<n;i++){
		G[e[i].f][--D[e[i].f]]=e[i].t;
		G[e[i].t][--D[e[i].t]]=e[i].f;
	}
	ini();
	for(int i=1;i<=m;i++){
		int x=rd(),y=rd();
		no[i]=++flw::cnt;
		flw::e[++flw::ec]=flw::Edge(no[i],flw::T,1);
		while(tp[x]!=tp[y]){
			if(cd[x]>cd[y]){
				flw::ade(dfn[tp[x]],dfn[x],no[i]),x=fa[tp[x]];
			}else flw::ade(dfn[tp[y]],dfn[y],no[i]),y=fa[tp[y]];
		}
		if(d[x]>d[y])flw::ade(dfn[y]+1,dfn[x],no[i]);
		else if(d[y]>d[x])flw::ade(dfn[x]+1,dfn[y],no[i]);
	}
	flw::buildg();
	printf("%d\n",flw::dinic());
	flw::bfs();
	vector<int>C;C.clear();
	for(int i=1;i<=m;i++)if(flw::vis[no[i]])C.push_back(i);
	vector<int>E;E.clear();
	for(int i=1;i<n;i++){
		int k=((d[e[i].f]>d[e[i].t])?dfn[e[i].f]:dfn[e[i].t]);
		if(!flw::vis[flw::lvno[k]])E.push_back(i);
	}
	pr(C.size());putchar(' ');
	for(vector<int>::iterator it=C.begin();it!=C.end();it++)printf("%d ",*it);
	putchar('\n');
	pr(E.size());putchar(' ');
	for(vector<int>::iterator it=E.begin();it!=E.end();it++)printf("%d ",*it);
	putchar('\n');
	/*for(int i=1;i<=n;i++)printf("tp[%d]=%d\n",i,tp[i]);
	for(int i=1;i<=n;i++)printf("fa[%d]=%d\n",i,fa[i]);
	for(int i=1;i<=n;i++)printf("dfn[%d]=%d\n",i,dfn[i]);
	for(int i=1;i<=n;i++)printf("d[%d]=%d\n",i,d[i]);
	for(int i=1;i<=n;i++)printf("tp[%d]=%d\n",i,tp[i]);*/
	return 0;
}