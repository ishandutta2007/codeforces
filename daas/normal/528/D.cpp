#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define MOD(x) (x>=mod?x-mod:x)
using namespace std;
const int mod=998244353;
const int G=3;
const int iG=(mod+1)/G;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,sum[200010],f[4][530000],g[4][530000],zone[530000],ans;
char s[200001],t[200001],ch[4]={'A','G','C','T'};
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
int main()
{
	n=read(),m=read(),K=read();
	scanf("%s%s",s+1,t+1);
	int LOG=ceil(log2(n+m+1)),lim=(1<<LOG);
	for(int i=0;i<lim;++i) zone[i]=((zone[i>>1]>>1)|((i&1)<<LOG-1));
	for(int p=0;p<4;++p)
	{
		for(int i=1;i<=m;++i) f[p][m-i+1]=(t[i]==ch[p]);
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
			if(s[i]==ch[p])
			{
				++sum[max(1,i-K)];
				--sum[min(n,i+K)+1];
			}
		for(int i=1;i<=n;++i)
		{
			sum[i]+=sum[i-1];
			if(sum[i]) g[p][i]=1;
		}
		/*cout<<"cao "<<p<<endl;
		for(int i=1;i<=n;++i) cout<<g[p][i]<<" ";
		cout<<endl;
		for(int i=1;i<=m;++i) cout<<f[p][i]<<" ";
		cout<<endl;*/
		NTT(f[p],1,lim);
		NTT(g[p],1,lim);
		for(int i=0;i<lim;++i) f[p][i]=1ll*f[p][i]*g[p][i]%mod;
		NTT(f[p],0,lim);
		//for(int i=1;i<lim;++i) cout<<i<<" "<<f[p][i]<<endl;
	}
	for(int i=1;i<=n;++i) ans+=(f[0][i+m]+f[1][i+m]+f[2][i+m]+f[3][i+m]==m);
	printf("%d\n",ans);
	return 0;
}