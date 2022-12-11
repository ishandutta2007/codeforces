#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define MN 16384
#define MX 8000
#define MOD 1000000007
#define r(x) (long long)(x+0.5)
struct cp{double r,i;}g[15][MN+5],w[MN+5],a1[MN+5],a2[MN+5],b1[MN+5],b2[MN+5],z[MN+5],t[MN+5];
inline cp operator+(const cp&a,const cp&b){return (cp){a.r+b.r,a.i+b.i};}
inline cp operator-(const cp&a,const cp&b){return (cp){a.r-b.r,a.i-b.i};}
inline cp operator*(const cp&a,const cp&b){return (cp){a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r};}
inline cp conj(const cp&a){return (cp){a.r,-a.i};}
int N,R[MN+5],d[15],r[MX+5],u[15];
const double pi=acos(-1);
void fftinit(int n)
{
	int x,i,j,k;
	for(N=1,x=0;N<n;N<<=1,++x);
	if(!u[x])for(u[x]=1,i=0;i<N;++i)g[x][i]=(cp){cos(2*pi/N*i),sin(2*pi/N*i)};
	for(i=0;i<N;++i)w[i]=g[x][i];
	for(i=j=0;i<N;R[++i]=j)for(k=N>>1;(j^=k)<k;k>>=1);
}
void fft(cp*x,int v)
{
	int i,j,k;
	if(v)for(i=0;i<N;++i)if(i<(N-1&N-i))swap(x[i],x[N-1&N-i]);
	for(i=0;i<N;++i)if(i<R[i])swap(x[i],x[R[i]]);
	for(i=1;i<N;i<<=1)for(j=0;j<N;j+=i<<1)for(k=0;k<i;++k)
	{
		cp p=x[i+j+k]*w[N/(i<<1)*k];
		x[i+j+k]=x[j+k]-p;x[j+k]=x[j+k]+p;
	}
	if(v)for(i=0;i<N;++i)x[i].r/=N,x[i].i/=N;
}
void fft(cp*x,cp*y,int v)
{
	int i,j;
	for(i=0;i<N;++i)t[i]=x[i]+y[i]*(cp){0,1};
	fft(t,v);
	for(i=0;i<N;++i)j=N-1&N-i,
		x[i]=v?(cp){t[i].r,0}:(t[i]+conj(t[j]))*(cp){0.5,0},
		y[i]=v?(cp){t[i].i,0}:(t[i]-conj(t[j]))*(cp){0,-0.5};
}
struct pol
{
	int n,*x;
	pol(int n=0):n(n),x(new int[n]){}
	inline int operator()(int z)const{return z<n?x[z]:0;}
}iv[MN+5],P[30];
void mul(pol&a,const pol&b,int u=0)
{
	fftinit(u?u:a.n+b.n-1);int i;
	for(i=0;i<N;++i)
		a1[i]=(cp){a(i)>>16,0},a2[i]=(cp){a(i)&65535,0},
		b1[i]=(cp){b(i)>>16,0},b2[i]=(cp){b(i)&65535,0};
	fft(a1,a2,0);fft(b1,b2,0);
	for(i=0;i<N;++i)z[i]=a1[i]*b1[i],a1[i]=a1[i]*b2[i]+a2[i]*b1[i],a2[i]=a2[i]*b2[i];
	fft(z,1);fft(a1,a2,1);
	for(i=0;i<a.n;++i)a.x[i]=((r(z[i].r)%MOD<<32)+(r(a1[i].r)%MOD<<16)+r(a2[i].r))%MOD;
}
void inv(pol&a)
{
	if(a.n<2)return;
	pol b(a.n+1>>1);int i;
	for(i=0;i<b.n;++i)b.x[i]=a.x[i];
	inv(b);mul(a,b);mul(a,b);
	for(i=0;i<a.n;++i)a.x[i]=(2LL*b(i)+MOD-a.x[i])%MOD;
}
void rev(pol&a){for(int i=0;i<a.n-1-i;++i)swap(a.x[i],a.x[a.n-1-i]);}
void MUL(pol&a,const pol&b,const pol&mod)
{
	pol A(a.n+b.n-1);int i;
	for(i=0;i<A.n;++i)A.x[i]=a(i);
	mul(A,b,A.n);a=A;
	if(a.n<mod.n)return;
	pol c(a.n-mod.n+1);
	if(iv[c.n].n)for(i=0;i<c.n;++i)c.x[i]=iv[c.n].x[i];
	else
	{
		for(i=0;i<c.n;++i)c.x[i]=mod.x[mod.n-i-1];inv(c);
		iv[c.n]=pol(c.n);
		for(i=0;i<c.n;++i)iv[c.n].x[i]=c.x[i];
	}
	rev(a);i=a.n;a.n=c.n;mul(c,a);a.n=i;rev(a);rev(c);
	pol res(mod.n-1);
	for(i=0;i<res.n;++i)res.x[i]=c(i);
	mul(res,mod);
	for(i=0;i<res.n;++i)res.x[i]=(a.x[i]+MOD-res.x[i])%MOD;
	a=res;
}
void pw(pol&a,long long k,const pol&mod)
{
	pol res(1);res.x[0]=1;
	for(;k;k>>=1,MUL(a,a,mod))if(k&1)MUL(res,a,mod);
	a=res;
}
int main()
{
	int n,m,i,j,mx=0;long long k;
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;++i)scanf("%d",&d[i]);
	for(i=1;i<=m;++i)scanf("%d",&r[i]),mx=max(mx,r[i]);
	pol x(mx),mod(mx+1);
	for(i=0;i<x.n;++i)mod.x[i]=x.x[i]=0;mod.x[i]=1;
	for(i=1;i<=m;++i)mod.x[mx-r[i]]=(mod.x[mx-r[i]]+MOD-1)%MOD;
	P[0]=pol(2);P[0].x[0]=0;P[0].x[1]=1;
	for(i=1;i<30;++i)
	{
		P[i]=pol(P[i-1].n);
		for(j=0;j<P[i].n;++j)P[i].x[j]=P[i-1].x[j];
		MUL(P[i],P[i-1],mod);
	}
	for(i=1;i<=n;++i)
	{
		pol a(1);a.x[0]=1;
		for(j=0;j<30;++j)if(d[i]&(1<<j))MUL(a,P[j],mod);
		for(j=0;j<x.n;++j)x.x[j]=(x.x[j]+a(j))%MOD;
	}
	pw(x,k,mod);
	for(i=mx;--i;)for(j=1;j<=i;++j)x.x[i-j]=(x.x[i-j]+1LL*x.x[i]*(MOD-mod.x[mx-j]))%MOD;
	printf("%d",x.x[0]);
}