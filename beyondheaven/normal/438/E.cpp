#include<bits/stdc++.h>
#define MaxN ((1<<19)+123)
typedef long long LL;
const LL Mod=998244353;

inline LL pow_mod(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%Mod)
	if(b&1)res=res*a%Mod;
	return res;
}

inline void NTT(LL*f,int n,int op)
{
	static int tr[MaxN];
	for(int i=0;i<n;++i)
	tr[i]=(tr[i>>1]>>1)|((i&1)?(n>>1):0);
	for(int i=0;i<n;++i)
	if(i<tr[i])std::swap(f[i],f[tr[i]]);
	LL g=(op==1?3:pow_mod(3,Mod-2));
	for(int p=2,len=1;p<=n;p<<=1,len<<=1)
	{
		LL w=pow_mod(g,(Mod-1)/p);
		for(int k=0;k<n;k+=p)
		{
			LL wn=1;
			for(int l=k;l<len+k;++l)
			{
				LL tmp=f[l+len]*wn%Mod;
				f[l+len]=(f[l]-tmp+Mod)%Mod;
				f[l]=(f[l]+tmp)%Mod;
				wn=wn*w%Mod;
			}
		}
	}
	if(op==-1)
	{
		LL InvN=pow_mod(n,Mod-2);
		for(int i=0;i<n;++i)
		f[i]=f[i]*InvN%Mod;
	}
}

inline void PolyInv(LL*F,LL*G,int n)
{
	static LL F0[MaxN];
	memset(F0,0,sizeof(LL)*(n<<1));
	G[0]=pow_mod(F[0],Mod-2);
	for(int p=2;p<=n;p<<=1)
	{
		memcpy(F0,F,sizeof(LL)*p);
		NTT(F0,(p<<1),1);NTT(G,(p<<1),1);
		for(int i=0;i<(p<<1);++i)
		G[i]=(2-F0[i]*G[i]%Mod+Mod)*G[i]%Mod;
		NTT(G,(p<<1),-1);
		memset(G+p,0,sizeof(LL)*p);
	}
}

inline void Derivate(LL*f,int n)
{
	for(int i=1;i<n;++i)
	f[i-1]=i*f[i]%Mod;
	f[n-1]=0;
}

inline void Integral(LL*f,int n,LL f0=0)
{
	for(int i=n-1;i>=0;--i)
	f[i+1]=pow_mod(i+1,Mod-2)*f[i]%Mod;
	f[0]=f0;
}

inline void PolyLn(LL*F,LL*G,int n)
{
	static LL F0[MaxN];
	memset(F0,0,sizeof(LL)*(n<<1));
	memcpy(F0,F,sizeof(LL)*n);
	PolyInv(F0,G,n);
	Derivate(F0,n);
	NTT(F0,(n<<1),1);NTT(G,(n<<1),1);
	for(int i=0;i<(n<<1);++i)
	G[i]=F0[i]*G[i]%Mod;
	NTT(G,(n<<1),-1);
	Integral(G,n);
	memset(G+n,0,sizeof(LL)*n);
}

inline void PolyExp(LL*F,LL*G,int n)
{
	static LL F0[MaxN],G0[MaxN];
	memset(F0,0,sizeof(LL)*(n<<1));
	memset(G0,0,sizeof(LL)*(n<<1));
	G[0]=1;
	for(int p=2;p<=n;p<<=1)
	{
		memcpy(F0,F,sizeof(LL)*p);
		memset(G0,0,sizeof(LL)*(p<<1));
		PolyLn(G,G0,p);
		for(int i=0;i<p;++i)
		F0[i]=(F0[i]-G0[i]+Mod)%Mod;
		NTT(G,(p<<1),1);NTT(F0,(p<<1),1);
		for(int i=0;i<(p<<1);++i)
		G[i]=G[i]*(1+F0[i])%Mod;
		NTT(G,(p<<1),-1);
		memset(G+p,0,sizeof(LL)*p);
	}
}

int n,m;
LL F[MaxN],G[MaxN],C[MaxN];
int main()
{
	
	scanf("%d%d",&n,&m);
	C[0]=1;
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		C[x]=Mod-4;
	}
	
	for(n=1;n<=m;n<<=1);
	
	PolyLn(C,G,n);
	LL Inv2=(Mod+1)/2;
	for(int i=0;i<n;++i)
	G[i]=G[i]*Inv2%Mod;
	memset(C,0,sizeof(LL)*n);
	PolyExp(G,C,n);
	
	C[0]=(C[0]+1)%Mod;
	
	PolyInv(C,F,n);
	for(int i=0;i<n;++i)
	F[i]=F[i]*2%Mod;
	
	for(int i=1;i<=m;++i)
	printf("%lld\n",F[i]);
	/*
	scanf("%d",&m);
	for(int i=0;i<m;++i)
	scanf("%lld",F+i);
	for(n=1;n<m;n<<=1);
	PolyExp(F,G,n);
	for(int i=0;i<m;++i)
	printf("%lld ",G[i]);
	*/
	return 0;
}