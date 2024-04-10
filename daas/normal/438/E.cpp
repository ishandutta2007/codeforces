#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define MOD(x) (x>=mod?x-mod:x)
using namespace std;
const int mod=998244353;
const int G=3;
const int iG=(mod+1)/G;
const int inv2=(mod+1)/2;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=(kkk*10+(c-'0'))%mod,c=getchar();
	return kkk*x;
}
int n,m,a[530000],g[530000],f[530000],mem[530000],zone[530000];
int ksm(int x,int y)
{
	int z=1;
	while(y)
	{
		if(y%2) z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return z;
}
void NTT(int A[],int flag,int lim)
{
	for(int i=0;i<lim;++i)
		if(zone[i]<i)
			swap(A[zone[i]],A[i]);
	for(int len=1;len<lim;len*=2)
	{
		int wn=ksm(flag?G:iG,(mod-1)/2/len);
		for(int i=0;i<lim;i+=2*len)
		{
			int w=1;
			for(int j=0;j<len;++j,w=1ll*w*wn%mod)
			{
				int A1=A[i+j],A2=1ll*w*A[i+j+len]%mod;
				A[i+j]=MOD(A1+A2);
				A[i+j+len]=MOD(A1-A2+mod);
			}
		}
	}
	if(!flag)
	{
		int inv=ksm(lim,mod-2);
		for(int i=0;i<lim;++i) A[i]=1ll*A[i]*inv%mod;
	}
}
void getinv(int A[],int len,int B[])
{
	if(len==1)
	{
		B[0]=ksm(A[0],mod-2);
		return;
	}
	getinv(A,(len+1)/2,B);
	int LOG=ceil(log2(2*len)),lim=(1<<LOG);
	for(int i=0;i<lim;++i) zone[i]=((zone[i>>1]>>1)|((i&1)<<LOG-1));
	for(int i=0;i<len;++i) mem[i]=A[i];
	for(int i=len;i<lim;++i) mem[i]=0;
	NTT(mem,1,lim);
	NTT(B,1,lim);
	for(int i=0;i<lim;++i) B[i]=1ll*B[i]*MOD(2-1ll*mem[i]*B[i]%mod+mod)%mod;
	NTT(B,0,lim);
	for(int i=len;i<lim;++i) B[i]=0;
}
void getsqrt(int A[],int len,int B[])
{
	if(len==1)
	{
		B[0]=1;
		return;
	}
	getsqrt(A,(len+1)/2,B);
	memset(f,0,sizeof(f));
	getinv(B,len,f);
	int LOG=ceil(log2(2*len)),lim=(1<<LOG);
	for(int i=0;i<lim;++i) zone[i]=((zone[i>>1]>>1)|((i&1)<<LOG-1));
	for(int i=0;i<len;++i) mem[i]=A[i];
	for(int i=len;i<lim;++i) mem[i]=0;
	NTT(B,1,lim);
	NTT(f,1,lim);
	NTT(mem,1,lim);
	for(int i=0;i<lim;++i) B[i]=MOD(B[i]+1ll*f[i]*mem[i]%mod);
	NTT(B,0,lim);
	for(int i=0;i<len;++i) B[i]=1ll*inv2*B[i]%mod;
	for(int i=len;i<lim;++i) B[i]=0;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[read()]=1;
	for(int i=0;i<=m;++i) a[i]=MOD(mod-4*a[i]);
	++a[0];
	getsqrt(a,m+1,g);
	++g[0];
	memset(f,0,sizeof(f));
	getinv(g,m+1,f);
	for(int i=1;i<=m;++i) printf("%lld\n",2ll*f[i]%mod);
	return 0;
}