#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,q,fa[400005],a[400005];
int u[300005],v[300005],ask[500005],N,s[2][400005];
bool del[500005];
int upd[500005];
int F(int x){
	return x==fa[x]?x:fa[x]=F(fa[x]);
}
int cnt,dfn[400005],siz[400005];
void dfs(int x){
	dfn[x]=++cnt,siz[x]=1;
	if(x>n){
		dfs(s[0][x]),siz[x]+=siz[s[0][x]];
		dfs(s[1][x]),siz[x]+=siz[s[1][x]];
	}
}
int tg[1100000];
pii dat[1100000];
void change(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		tg[i]=x;
		return;
	}
	if(tg[i]){
		tg[i<<1]=tg[i<<1|1]=tg[i];
		tg[i]=0;
	}
	int md=(l+r)>>1;
	change(i<<1,l,md,a,b,x),change(i<<1|1,md+1,r,a,b,x);
}
int getfa(int i,int l,int r,int p){
	if(l==r)return tg[i];
	if(tg[i]){
		tg[i<<1]=tg[i<<1|1]=tg[i];
		tg[i]=0;
	}
	int md=(l+r)>>1;
	if(p<=md)return getfa(i<<1,l,md,p);
	return getfa(i<<1|1,md+1,r,p);
}
pii qry(int i,int l,int r,int a,int b){
	if(r<a||b<l)return {-1,-1};
	if(a<=l&&r<=b)return dat[i];
	int md=(l+r)>>1;
	return max(qry(i<<1,l,md,a,b),qry(i<<1|1,md+1,r,a,b));
}
void update(int i,int l,int r,int p,pii x){
	if(l==r)dat[i]=x;
	else{
		int md=(l+r)>>1;
		if(p<=md)update(i<<1,l,md,p,x);
		else update(i<<1|1,md+1,r,p,x);
		dat[i]=max(dat[i<<1],dat[i<<1|1]);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q),N=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=q;i++){
		int op,v;scanf("%d%d",&op,&v);
		if(op==1)ask[i]=v;
		if(op==2)ask[i]=-v,del[v]=1;
	}
	for(int i=1;i<=m;i++)if(!del[i]){
		int U=F(u[i]),V=F(v[i]);
		if(U!=V){
			++N,fa[U]=N,fa[V]=N,fa[N]=N;
			s[0][N]=U,s[1][N]=V;
		}
	}
	for(int i=q;i;i--)if(ask[i]<0){
		int A=-ask[i];
		int U=F(u[A]),V=F(v[A]);
		if(U!=V){
			++N,fa[U]=N,fa[V]=N,fa[N]=N;
			s[0][N]=U,s[1][N]=V;
			upd[i]=N;
		}
	}
	for(int i=1;i<=N;i++)if(F(i)==i)
		dfs(i),change(1,1,N,dfn[i],dfn[i]+siz[i]-1,i);
	for(int i=1;i<=N;i++)update(1,1,N,dfn[i],{a[i],i});
	for(int i=1;i<=q;i++){
		if(ask[i]<0){
			int x=upd[i];
			if(x){
				int ls=s[0][x],rs=s[1][x];
				change(1,1,N,dfn[ls],dfn[ls]+siz[ls]-1,ls);
				change(1,1,N,dfn[rs],dfn[rs]+siz[rs]-1,rs);
			}
		}else{
			int x=ask[i];
			int rt=getfa(1,1,N,dfn[x]);
			pii tmp=qry(1,1,N,dfn[rt],dfn[rt]+siz[rt]-1);
			printf("%d\n",tmp.fi);
			update(1,1,N,dfn[tmp.se],{0,tmp.se});
		}
	}
}