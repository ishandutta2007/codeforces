#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>rt;
const int S=3333333;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lc[S],rc[S],n,A[S],ans,g[S],w[S],m,pc;
#define md (L+R>>1)
void build(int p,int L,int R){
	if(L==R)return void(g[p]=A[L]);
	build(p<<1,L,md);build(p<<1|1,md+1,R);
	g[p]=gcd(g[p<<1],g[p<<1|1]);
}
void ask(int l,int r,int p=1,int L=1,int R=n){
	if(l<=L&&R<=r)return void(ans=gcd(g[p],ans));
	if(l<=md)ask(l,r,p<<1,L,md);
	if(r>md)ask(l,r,p<<1|1,md+1,R);
}
void ins(int&p,int x,int L=1,int R=n){
	if(!p)p=++pc; w[p]++;
	if(L==R)return;
	if(x<=md)ins(lc[p],x,L,md);else ins(rc[p],x,md+1,R);
}
int cnt(int&p,int l,int r,int L=1,int R=n){
	if(!p)return 0; if(l<=L&&R<=r)return w[p];
	return (l<=md?cnt(lc[p],l,r,L,md):0)+(r>md?cnt(rc[p],l,r,md+1,R):0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),ins(rt[A[i]],i);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;++i)scanf("%d%d",&l,&r),ans=0,ask(l,r),printf("%d\n",r-l+1-cnt(rt[ans],l,r));
}