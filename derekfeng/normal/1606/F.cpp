#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int INF=5e5;
typedef pair<ll,ll> pii;
pii operator +(const pii &A,const pii &B){
	return {A.fi+B.fi,A.se+B.se};
}
pii operator -(const pii &A,const pii &B){
	return {A.fi-B.fi,A.se-B.se};
}
int rt[200004];
int tot;
pii dat[15000000];
int s[2][15000000];
pii got(int i,int l,int r,int p){
	if(!i||l==r)return dat[i];
	int md=(l+r)>>1;
	pii res;
	if(p<=md)res=got(s[0][i],l,md,p);
	else res=got(s[1][i],md+1,r,p);
	return res+dat[i];
}
int add(int i,int l,int r,int a,int b,pii x){
	if(r<a||b<l)return i;
	if(!i)i=++tot;
	if(a<=l&&r<=b){
		dat[i]=dat[i]+x;
		return i;
	}
	int md=(l+r)>>1;
	s[0][i]=add(s[0][i],l,md,a,b,x),s[1][i]=add(s[1][i],md+1,r,a,b,x);
	return i;
}
int asn(int i,int l,int r,int a,int b,pii x,pii y){
	if(r<a||b<l)return i;
	if(!i)i=++tot;
	if(a<=l&&r<=b){
		i=++tot;
		dat[i]=x-y;
		return i;
	}
	int md=(l+r)>>1;
	s[0][i]=asn(s[0][i],l,md,a,b,x,y+dat[i]),s[1][i]=asn(s[1][i],md+1,r,a,b,x,y+dat[i]);
	return i;
}
pii qry(int x,int k){
	return got(rt[x],0,INF,k);
}
void ins(int x,int l,int r,pii z){
	rt[x]=add(rt[x],0,INF,l,r,z);
}
void ang(int x,int l,int r,pii z){
	rt[x]=asn(rt[x],0,INF,l,r,z,{0,0});
}
int merge(int i1,int i2){
	if(!i1||!i2)return i1|i2;
	dat[i1]=dat[i1]+dat[i2];
	s[0][i1]=merge(s[0][i1],s[0][i2]);
	s[1][i1]=merge(s[1][i1],s[1][i2]);
	return i1;
}
ll F(pii p,int x){
	return p.fi+p.se*x;
}
int bs(int i){
	int ld=-1,rd=INF+1;
	while(rd>ld+1){
		int md=(ld+rd)/2;
		if(md<=INF&&(md==-1||F(qry(i,md),md)-md>1))ld=md;
		else rd=md;
	}
	return ld;
}
int n,q,K[200004];
vector<int>g[200004],ask[200004];
ll ans[200004];
void iter(int x,int l,int r){
	if(!x)return;
	int md=(l+r)>>1;
	iter(s[0][x],l,md),iter(s[1][x],md+1,r);
}
void dfs(int x,int fa){
	for(auto y:g[x])if(y!=fa){
		dfs(y,x);
		rt[x]=merge(rt[x],rt[y]);
	}
	for(auto y:ask[x]){
		int k=K[y];
		ans[y]=F(qry(x,k),k);
	}
	int pos=bs(x);
	if(pos+1<=INF)ang(x,pos+1,INF,{1,0});
	if(pos>=0)ins(x,0,pos,{0,-1});
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int v;scanf("%d%d",&v,&K[i]);
		ask[v].push_back(i);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}