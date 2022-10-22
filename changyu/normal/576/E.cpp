#include<bits/stdc++.h>
const int N=5e5+3,D=1<<20,K=53;
struct edge{int u,v;}e[N];
int n,m,k,q,d[N],c[N],l[N];
struct dsu{
	int p[N],siz[N],c[N],stx[N],sty[N],tp,f;
	int Find(int k){return p[k]==k?k:Find(p[k]);}
	int Depth(int k){return p[k]==k?0:Depth(p[k])^c[k];}
	inline void Init(){
		tp=f=0;
    	for(int u=1;u<=n;u++)siz[u]=1,p[u]=u,c[u]=0;
	}
	inline void Merge(int i){
		int x=Find(e[i].u),y=Find(e[i].v);
		++tp;
		if(x==y){
		  stx[tp]=sty[tp]=0;
		  if(!f&&Depth(e[i].u)==Depth(e[i].v))f=1,sty[tp]=1;
		  return;
    	}
		if(siz[x]>siz[y])std::swap(x,y);
		stx[tp]=x,sty[tp]=y;
		c[x]=Depth(e[i].u)^Depth(e[i].v)^1,p[x]=y,siz[y]+=siz[x];
	}
	inline void Ctrlz(){
		int x=stx[tp],y=sty[tp];
		--tp;
		if(!x){
		  if(y)f=0;
		  return;
    	}
    	c[x]=0,p[x]=x,siz[y]-=siz[x];
    }
}t[K];
#define M (L+R>>1)
struct query{int l,r,i,s,t;}qry[N];
std::vector<int>h[D];
void Add_query(int l,int r,int L,int R,int k){
	if(l<=L&&R<=r){h[k].push_back(l);return;}
	if(l<=M)Add_query(l,r,L,M,k<<1);
	if(r>M)Add_query(l,r,M+1,R,k<<1|1);
}
void Dfs(int L,int R,int k){
	for(int i=0;i<h[k].size();i++)if(qry[h[k][i]].t)
	  t[qry[h[k][i]].t].Merge(qry[h[k][i]].i);
	if(L==R){
	  if(L<q){
		int tmp=qry[L+1].t;
		t[tmp].Merge(qry[L+1].i);
		if(!t[qry[L+1].t].f)puts("YES");
		else{
		  puts("NO");
		  qry[L+1].t=qry[L+1].s;
		  qry[qry[L+1].r+1].s=qry[L+1].t;
		}
		t[tmp].Ctrlz();
	  }
	}else Dfs(L,M,k<<1),Dfs(M+1,R,k<<1|1);
	if(h[k].size())for(int i=0;i<h[k].size();i++)if(qry[h[k][i]].t)
	  t[qry[h[k][i]].t].Ctrlz();
}
int main(){
	int x,y;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int l=1;l<=k;l++)t[l].Init();
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].u,&e[i].v);
	for(int j=1;j<=q;j++){
	  scanf("%d%d",&x,&y);
	  if(c[x]){
		qry[l[x]]=(query){l[x],j-1,x,d[x],c[x]};
		Add_query(l[x],j-1,1,q,1);
	  }
	  d[x]=c[x],c[x]=y,l[x]=j;
	}
	for(int i=1;i<=m;i++)if(c[i]){
	  qry[l[i]]=(query){l[i],q,i,d[i],c[i]};
	  Add_query(l[i],q,1,q,1);
	}
	t[qry[1].t].Merge(qry[1].i);
	if(!t[qry[1].t].f)puts("YES");
	else{
	  puts("NO");
	  qry[1].t=qry[1].s;
	  qry[qry[1].r+1].s=qry[1].t;
	}
	t[qry[1].t].Ctrlz();
	Dfs(1,q,1);
    return 0;
}