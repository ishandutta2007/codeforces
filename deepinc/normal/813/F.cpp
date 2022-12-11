#include<bits/stdc++.h>
using namespace std;
const int S=400005;
int ok=1,n,q,f[S],sz[S],top,of[S],op[S],os[S],tf[S];
vector<int>x[S],y[S]; unordered_map<int,int>M[S];
#define lc p<<1
#define rc lc|1
#define md (L+R>>1)
int find(int x){while(x!=f[x])x=f[x];return x;}
int dt(int x,int a=0){while(x!=f[x])a^=tf[x],x=f[x];return a;}
void link(int a,int b){
	int x=find(a),y=find(b),d=dt(a)^dt(b);
	if(x==y)ok&=d;
	else{
		op[++top]=x; os[top]=sz[x]; of[top]=f[x];
		op[++top]=y; os[top]=sz[y]; of[top]=f[y];
		if(sz[x]>sz[y])tf[y]=d^1,f[y]=x,sz[x]+=sz[y];
		else tf[x]=d^1,f[x]=y,sz[y]+=sz[x];
	}
}
void ins(int l,int r,int a,int b,int p=1,int L=1,int R=q){
	if(l<=L&&R<=r)return x[p].push_back(a),y[p].push_back(b);
	if(l<=md)ins(l,r,a,b,lc,L,md);
	if(r>md)ins(l,r,a,b,rc,md+1,R);
}
void dfs(int p=1,int L=1,int R=q){
	int r=ok,tp=top;
	for(int i=0;i<x[p].size();++i)link(x[p][i],y[p][i]);
	if(L==R){puts(ok?"YES":"NO");goto E;}
	dfs(lc,L,md);dfs(rc,md+1,R);
	E:while(top>tp)sz[op[top]]=os[top],f[op[top]]=of[top],top--;ok=r;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)f[i]=i,sz[i]=1;
	for(int i=1,a,b;i<=q;++i){
		scanf("%d%d",&a,&b); if(a>b)swap(a,b); int&z=M[a][b];
		if(z)ins(z,i-1,a,b),z=0;
		else z=i;
	}
	for(int i=1;i<=n;++i)for(auto x:M[i])if(x.second)ins(x.second,q,i,x.first);
	dfs(1,1,q);
}