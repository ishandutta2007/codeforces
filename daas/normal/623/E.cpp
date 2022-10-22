#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define ll long long
using namespace std;
const double pi=acos(-1);
const int mod=1e9+7;
const int sqr=sqrt(mod)+1;
inline int MOD(int x){return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int K,ans[66001],sum[30001],sum2[30001],inv[30001],zone[66001],mem[66001],lim,Lim;
long long n;
struct complex
{
	double x,y; //x+yi;
	complex(double _x=0,double _y=0){x=_x,y=_y;}
}mem1[66001],mem2[66001],mem3[66001],mem4[66001],w[66001];
complex operator +(complex x,complex y){return complex(x.x+y.x,x.y+y.y);}
complex operator -(complex x,complex y){return complex(x.x-y.x,x.y-y.y);}
complex operator *(complex x,complex y){return complex(x.x*y.x-x.y*y.y,x.y*y.x+x.x*y.y);}
complex operator /(complex x,int y){return complex(x.x/y,x.y/y);}
inline complex conj(complex x){return complex(x.x,-x.y);}
inline complex I(complex x){return complex(-x.y,x.x);}
void FFT(complex A[],int flag)
{
	for(int i=0;i<lim;++i)
		if(zone[i]<i)
			swap(A[zone[i]],A[i]);
	for(int len=1;len<lim;len*=2)
		for(int i=0;i<lim;i+=2*len)
			for(int j=0;j<len;++j)
			{
				complex A1=A[i+j],A2=w[Lim/len*j]*A[i+j+len];
				A[i+j]=A1+A2;
				A[i+j+len]=A1-A2;
			}
	if(flag==-1)
	{
		for(int i=0;i<lim;++i) A[i]=A[i]/lim;
		reverse(A+1,A+lim);
	}
}
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2) z=(ll)z*x%mod;
		x=(ll)x*x%mod;
		y/=2;
	}
	return z;
}
void mul(int A[],int B[])
{
	/*int C[66001];
	memset(C,0,sizeof(C));
	for(int i=0;i<lim;++i)
		for(int j=0;j<lim;++j)
			if(i+j<lim) C[i+j]=(C[i+j]+1ll*A[i]*B[j]%mod)%mod;
	//for(int i=0;i<lim;++i) cout<<A[i]<<" ";
	//cout<<endl;
	//for(int i=0;i<lim;++i) cout<<B[i]<<" ";
	//cout<<endl;
	for(int i=0;i<lim;++i) A[i]=C[i];
	return;*/
	for(int i=0;i<lim;++i)
	{
		mem1[i].x=A[i]/sqr,mem1[i].y=A[i]%sqr;
		mem3[i].x=B[i]/sqr,mem3[i].y=B[i]%sqr;
	}
	FFT(mem1,1);
	FFT(mem3,1);
	mem2[0]=conj(mem1[0]);
	mem4[0]=conj(mem3[0]);
	for(int i=1;i<lim;++i)
	{
		mem2[i]=conj(mem1[lim-i]);
		mem4[i]=conj(mem3[lim-i]);
	}
	for(int i=0;i<lim;++i)
	{
		complex P=mem1[i],Q=mem2[i];
		mem1[i]=(P+Q)/2,mem2[i]=I((Q-P)/2);
		P=mem3[i],Q=mem4[i];
		mem3[i]=(P+Q)/2,mem4[i]=I((Q-P)/2);
	}
	for(int i=0;i<lim;++i)
	{
		mem1[i]=mem1[i]*mem3[i]+I(mem1[i]*mem4[i]);
		mem2[i]=mem2[i]*mem3[i]+I(mem2[i]*mem4[i]);
	}
	FFT(mem1,-1);
	FFT(mem2,-1);
	for(int i=0;i<lim;++i)
	{
		ll v1=mem1[i].x+0.5,v2=mem1[i].y+0.5,v3=mem2[i].x+0.5,v4=mem2[i].y+0.5;
		/*v1=v1%mod;
		v2=v2%mod;
		v3=v3%mod;
		v4=v4%mod;*/
		A[i]=MOD(v1*sqr%mod*sqr%mod+MOD(MOD(v2*sqr%mod+v3*sqr%mod-mod)+v4%mod-mod)-mod);
	}
}
void fun(int A[],int n)
{
	if(n==1)
	{
		for(int i=1;i<=K;++i) A[i]=inv[i];
		return;
	}
	memset(mem,0,sizeof(mem));
	if(n&1)
	{
		fun(A,n-1);
		for(int i=0;i<=K;++i) A[i]=(ll)A[i]*sum2[i]%mod;
		mem[0]=0;
		for(int i=1;i<=K;++i) mem[i]=inv[i];
		for(int i=K+1;i<lim;++i) mem[i]=0;
		mul(A,mem);
		for(int i=K+1;i<lim;++i) A[i]=0;
		return;
	}
	int mid=n/2;
	fun(A,mid);
	int S=1,v=sum2[mid];
	for(int i=0;i<=K;++i,S=(ll)S*v%mod) mem[i]=(ll)A[i]*S%mod;
	for(int i=K+1;i<lim;++i) mem[i]=0;
	mul(A,mem);
	for(int i=K+1;i<lim;++i) A[i]=0;
}
inline int C(int n,int m){return (n<0 || m<0 || n<m)?0:(ll)sum[n]*inv[m]%mod*inv[n-m]%mod;}
int main()
{
	scanf("%lld%d",&n,&K);
	//n=K=30000;
	int LOG=ceil(log2(2*K+1));
	lim=(1<<LOG);
	for(int i=0;i<lim;++i) zone[i]=((zone[i>>1]>>1)|((i&1)<<LOG-1));
	Lim=lim;
	for(int i=0;i<Lim;++i) w[i]=complex(cos(pi/Lim*i),sin(pi/Lim*i));
	sum[0]=inv[0]=sum2[0]=1;
	for(int i=1;i<=K;++i) sum[i]=(ll)i*sum[i-1]%mod,sum2[i]=(ll)2*sum2[i-1]%mod;
	inv[K]=ksm(sum[K],mod-2);
	for(int i=K-1;i>=1;--i) inv[i]=(ll)(i+1)*inv[i+1]%mod;
	if(n>K)
	{
		puts("0");
		return 0;
	}
	fun(ans,n);
	int out=0;
	for(int i=1;i<=K;++i) out=MOD(out+(ll)ans[i]*sum[i]%mod*C(K,i)%mod-mod);
	printf("%d\n",out);
	//cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
	return 0;
}