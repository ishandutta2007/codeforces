#include<iostream>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,f[MN+5],F[MN+5],g[MN+5],G[MN+5],head[MN+5],cnt=0,ans=0,son[MN+5];
struct edge{int to,next;}e[MN*2+5];

inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}

int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;	
	return sum;
}

void Pre(int x,int fa)
{
	f[x]=F[x]=g[x]=G[x]=1;
	for(int i=head[x];i;i=e[i].next)	
		if(e[i].to!=fa)
		{
			Pre(e[i].to,x);++son[x];
			f[x]=1LL*f[x]*(f[e[i].to]+F[e[i].to])%mod;
			F[x]=1LL*F[x]*(g[e[i].to]+G[e[i].to])%mod;
			g[x]=1LL*g[x]*(g[e[i].to]+G[e[i].to])%mod;
			G[x]=1LL*G[x]*(f[e[i].to]+F[e[i].to])%mod;
		}
	if(!son[x]) f[x]=G[x]=0;
//	cout<<"Pre"<<x<<" "<<f[x]<<" "<<F[x]<<" "<<g[x]<<" "<<G[x]<<endl;
}

void Solve(int x,int fa)
{
//	cout<<x<<" "<<(g[x]+G[x])%mod<<endl;
	R(ans,(g[x]+G[x])%mod);	
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa)
		{
	//		cout<<x<<" - > "<<e[i].to<<endl;
	//		cout<<f[e[i].to]<<" "<<F[e[i].to]<<" "<<g[e[i].to]<<" "<<G[e[i].to]<<endl;
			int ftot=(f[e[i].to]+F[e[i].to])%mod,gtot=(g[e[i].to]+G[e[i].to])%mod;
			int invf=pow(ftot,mod-2),invg=pow(gtot,mod-2);
			int ff=1LL*f[x]*invf%mod,gg=1LL*g[x]*invg%mod;
			int FF=1LL*F[x]*invg%mod,GG=1LL*G[x]*invf%mod;
			if(!son[e[i].to]++) f[e[i].to]=F[e[i].to]=g[e[i].to]=G[e[i].to]=1;
			if(!(son[x]-1)) FF=gg=1,ff=GG=0;			
		//	cout<<ftot<<" "<<gtot<<" "<<(FF+ff)<<" "<<(gg+GG)<<endl;
			f[e[i].to]=1LL*f[e[i].to]*(ff+FF)%mod;
			g[e[i].to]=1LL*g[e[i].to]*(gg+GG)%mod;
			F[e[i].to]=1LL*F[e[i].to]*(gg+GG)%mod;
			G[e[i].to]=1LL*G[e[i].to]*(ff+FF)%mod; 
			Solve(e[i].to,x); 
		}
}

int main()
{
	n=read();
	for(int i=1;i<n;++i) ins(read(),read());
	Pre(1,0);Solve(1,0);cout<<ans;
	return 0;
}