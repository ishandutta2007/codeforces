#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define MO 998244353
#define N 500005
int Ans,vv[50],n,f[N],p[N],q,u,l,r,H[N];
set<int>S;
inline int ksm(int a,int p)
{
	vv[0]=a; for(int i=1;i<=29;++i)vv[i]=(long long)vv[i-1]*vv[i-1]%MO;
	int s=1;
	for(int i=29;i>=0;--i)if(1<<i<=p){
		p-=1<<i;
		s=(long long)s*vv[i]%MO;
	}
	return s;
}

struct node {
#define ls (p<<1)
#define rs ((p<<1)|1)
#define M 550005

int ad[M],su[M];

inline void upd(int p)
{
	su[p]=(su[ls]+su[rs])%MO;
}

inline void pudo(int p)
{
	ad[ls]=(long long)ad[ls]*ad[p]%MO;
	ad[rs]=(long long)ad[rs]*ad[p]%MO;
	su[ls]=(long long)su[ls]*ad[p]%MO;
	su[rs]=(long long)su[rs]*ad[p]%MO;
	ad[p]=1;
}

void bui(int p, int l, int r)
{
	ad[p]=1;
	if(l==r){
		su[p]=f[l];
		return;
	}
	int mi=l+r>>1;
	bui(ls,l,mi); bui(rs,mi+1,r);
	upd(p);
}

void ch(int p, int l, int r, int x, int y, int w)
{
	if(x<=l&&r<=y){
		ad[p]=(long long)ad[p]*w%MO;
		su[p]=(long long)su[p]*w%MO;
		return;
	}
	if(x>r||y<l)return;
	int mi=l+r>>1;
	ch(ls,l,mi,x,y,w);
	ch(rs,mi+1,r,x,y,w);
	upd(p);
}

int que(int p, int l, int r, int x, int y)
{
	if(x<=l&&r<=y)return su[p];
	if(x>r||y<l)return 0;
	int mi=l+r>>1;
	pudo(p);
	return (que(ls,l,mi,x,y)+que(rs,mi+1,r,x,y))%MO;
}

}tr;

inline int op(int l, int r)
{
	if(l==r)return 0;
	int _u=tr.que(1,1,n,r-1,r-1);
	int _v=tr.que(1,1,n,l,r-2);
	_v=(_v+1)%MO;	
	return (long long)_v*ksm(_u,MO-2)%MO;
}

inline void upd(int&a,int b)
{
	a=(a+b)%MO;
}

int main()
{
	n=read(); q=read();
	for(int i=1;i<=n;++i)p[i]=read(),p[i]=(long long)p[i]*ksm(100,MO-2)%MO;
	f[1]=p[1];for(int i=2;i<=n;++i)f[i]=(long long)f[i-1]*p[i]%MO;
	tr.bui(1,1,n);
	Ans=op(1,n+1);
	
	S.insert(1);
	while(q--){
		u=read();
		l=*(--S.lower_bound(u));
		auto it=S.upper_bound(u);
		if(it==S.end())r=n+1; else r=*it;
		if(H[u]){
			upd(Ans,MO-op(l,u));
			upd(Ans,MO-op(u,r));
			tr.ch(1,1,n,u,r-1,tr.que(1,1,n,u-1,u-1));
			upd(Ans,op(l,r));
			H[u]=0; S.erase(u);
			printf("%d\n",Ans);
			continue;
		}
		upd(Ans,MO-op(l,r));
		tr.ch(1,1,n,u,r-1,ksm(tr.que(1,1,n,u-1,u-1),MO-2));
		upd(Ans,op(l,u));
		upd(Ans,op(u,r));
		H[u]=1; S.insert(u);
		printf("%d\n",Ans);
	}
}