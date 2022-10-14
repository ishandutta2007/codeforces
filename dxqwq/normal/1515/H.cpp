// Problem: H. Phoenix and Bits
// Contest: Codeforces - Codeforces Global Round 14
// URL: https://codeforces.com/problemset/problem/1515/H
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int n,m,c,cnt;
int ls[10000003],rs[10000003];
int s[10000003],v[10000003],txor[10000003],tor[10000003];
int stk[10000003],top=10000000;
bool f[2000003];
int pre[2000003];
void build(int x,int nl,int nr)
{
	if(nl==nr) 
	{
		assert(f[nl]);
		s[x]=1;
		return ;
	}
	int mid=(nl+nr)>>1;
	(pre[mid]-pre[nl]+f[nl])&&(ls[x]=stk[top--],build(ls[x],nl,mid),1),
	(pre[nr]-pre[mid])&&(rs[x]=stk[top--],build(rs[x],mid+1,nr),1),
	s[x]=s[ls[x]]+s[rs[x]],
	v[x]=v[ls[x]]|v[rs[x]],
	(ls[x]&&rs[x])&&(v[x]+=(nr-nl+1)>>1);
	return ;
}
void del(int x){ls[x]=rs[x]=tor[x]=txor[x]=s[x]=v[x]=0,stk[++top]=x;}
void pd(int x,int N)
{
	int T=tor[x];
	if(T&N) 
	{
		assert(!(ls[x]&&rs[x]));
		if(ls[x]) rs[x]=ls[x],ls[x]=0;
		txor[rs[x]]-=txor[rs[x]]&(T-N),
		tor[rs[x]]|=(T-N);
	}
	else 
		txor[ls[x]]-=txor[ls[x]]&T,
		tor[ls[x]]|=T,
		txor[rs[x]]-=txor[rs[x]]&T,
		tor[rs[x]]|=T;
	T=txor[x];
	if(T&N) swap(ls[x],rs[x]),T-=N,(ls[x])&&(txor[ls[x]]^=T),(rs[x])&&(txor[rs[x]]^=T);
	else (ls[x])&&(txor[ls[x]]^=T),(rs[x])&&(txor[rs[x]]^=T);
	txor[x]=tor[x]=0;
	return ;
}
void merge(int x,int y,int N)
{
	(txor[x]||tor[x])&&(pd(x,N),1),(txor[y]||tor[y])&&(pd(y,N),1);
	if(ls[y]) if(ls[x]) merge(ls[x],ls[y],N>>1); else ls[x]=ls[y];
	if(rs[y]) if(rs[x]) merge(rs[x],rs[y],N>>1); else rs[x]=rs[y];
	s[x]=s[ls[x]]+s[rs[x]]+(N==0),v[x]=v[ls[x]]|v[rs[x]],del(y);
	(ls[x]&&rs[x])&&(v[x]+=N);
	return ;
}
void debug(int x,int l,int r)
{
	if(l==r) return ;
	//return (void)printf("%d ",l);
	int mid=(l+r)>>1;
	(txor[x]||tor[x])&&(pd(x,(r-l+1)>>1),1);
	if(ls[x]) debug(ls[x],l,mid);
	if(rs[x]) debug(rs[x],mid+1,r);
	return ;
}
void update(int x,int N,int V)
{
	(txor[x]||tor[x])&&(pd(x,N),1);
	if(N&V) if(ls[x]) if(rs[x]) merge(rs[x],ls[x],N>>1),ls[x]=0;
	else rs[x]=ls[x],ls[x]=0;
	(ls[x]&&(v[ls[x]]&V))
		?(update(ls[x],N>>1,V-(N&V)),1)
		:(txor[ls[x]]-=txor[ls[x]]&(V-(N&V)),tor[ls[x]]|=V-(N&V)),
	(rs[x]&&(v[rs[x]]&V))
		?(update(rs[x],N>>1,V-(N&V)),1)
		:(txor[rs[x]]-=txor[rs[x]]&(V-(N&V)),tor[rs[x]]|=V-(N&V));
	s[x]=s[ls[x]]+s[rs[x]],
	v[x]=v[ls[x]]|v[rs[x]],
	(ls[x]&&rs[x])&&(v[x]+=N);
	return ;
}
int query(int x,int nl,int nr,int l,int r)
{
	(txor[x]||tor[x])&&(pd(x,(nr-nl+1)>>1),1);
	if(l<=nl&&nr<=r) return s[x];
	if(nr<l||r<nl) return 0;
	int res=0;
	int mid=(nl+nr)>>1;
	if(ls[x]) res+=query(ls[x],nl,mid,l,r);
	if(rs[x]) res+=query(rs[x],mid+1,nr,l,r);
	return res;
}
void split(int x,int& y,int N,int k) 
{
	if(x==0) return ;
	y=stk[top--];
	int val=s[ls[x]];
	if(k>val) split(rs[x],rs[y],N>>1,k-val); else swap(rs[x],rs[y]);
	if(k<val) split(ls[x],ls[y],N>>1,k);
	s[y]=s[x]-k,s[x]=k,
	(x)&&(v[x]=v[ls[x]]|v[rs[x]]),
	(y)&&(v[y]=v[ls[y]]|v[rs[y]]),
	(x&&ls[x]&&rs[x])&&(v[x]+=N),
	(y&&ls[y]&&rs[y])&&(v[y]+=N);
	return;
}
const int N=1<<19,M=(1<<20)-1;
signed main()
{
	for(int i=1; i<=10000000; ++i) stk[i]=i+1;
    n=read(),m=read(),c=1,cnt=1;
    for(int i=1; i<=n; ++i) f[read()]=1;
    pre[0]=f[0];
    for(int i=1; i<=M; ++i) pre[i]=pre[i-1]+f[i];
    build(1,0,M);
    for(int op,x,y; m--;)
    {
    	op=read(),x=read(),y=read();
    	if(op==1) 
    	{
    		int A=query(1,0,M,0,y);
    		int B=query(1,0,M,x,y);
    		int tmp=0,qwq=0;
    		split(1,qwq,N,A-B),
    		split(qwq,tmp,N,B),
    		txor[qwq]^=M,
    		update(qwq,N,M^read()),
    		txor[qwq]^=M,
// #ifdef local
	//debug(qwq,0,M);
	//puts(""),
// #endif
    		merge(1,tmp,N),
    		merge(1,qwq,N);
    	}
    	else if(op==2)
    	{
    		int A=query(1,0,M,0,y);
    		int B=query(1,0,M,x,y);
    		int tmp=0,qwq=0;
    		split(1,qwq,N,A-B),
    		split(qwq,tmp,N,B),
    		update(qwq,N,read()),
    		merge(1,tmp,N),
    		merge(1,qwq,N);
    	}
    	else if(op==3)
    	{
    		int A=query(1,0,M,0,y);
    		int B=query(1,0,M,x,y);
    		int tmp=0,qwq=0;
    		split(1,qwq,N,A-B),
    		split(qwq,tmp,N,B),
    		txor[qwq]^=read(),
    		merge(1,tmp,N),
    		merge(1,qwq,N);
    	}
    	else printf("%d\n",query(1,0,M,x,y));
// #ifdef local
	//debug(1,0,M);
	//puts("");
// #endif
    }
    return 0;
}