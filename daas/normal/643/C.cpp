#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#define int long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,T[200001],S[200001],dl[200001],h,t;
double A[200001],B[200001],dp[51][200001];
double Y(int x,int p){return dp[p][x]-A[x]+S[x]*B[x];}
int X(int x){return S[x];}
double slope(int x,int y,int p)
{
	double yx=Y(x,p),yy=Y(y,p);
	int xx=X(x),xy=X(y);
	if(xx==xy) return yx<yy?1e9:-1e9;
	return (double)(yx-yy)/(xx-xy);
}
signed main()
{
	n=read(),K=read();
	for(int i=1;i<=n;++i) T[i]=read();
	for(int i=1;i<=n;++i) S[i]=S[i-1]+T[i];
	for(int i=1;i<=n;++i)
	{
		A[i]=A[i-1]+(double)S[i]/T[i];
		B[i]=B[i-1]+1.0/T[i];
	}
	for(int i=1;i<=n;++i) dp[1][i]=A[i];
	for(int p=2;p<=K;++p)
	{
		h=t=0;
		for(int i=1;i<=n;++i)
		{
			/*dp[p][i]=0x3f3f3f3f;
			for(int j=1;j<i;++j) dp[p][i]=min(dp[p][i],dp[p-1][j]+A[i]-A[j]-S[j]*(B[i]-B[j]));
			continue;*/
			while(t-h>1 && slope(dl[h+1],dl[h+2],p-1)<=B[i]) ++h;
			if(h!=t) dp[p][i]=dp[p-1][dl[h+1]]+A[i]-A[dl[h+1]]-S[dl[h+1]]*(B[i]-B[dl[h+1]]);
			else dp[p][i]=0x3f3f3f3f;
			while(t-h>1 && slope(dl[t-1],dl[t],p-1)>=slope(dl[t-1],i,p-1)) --t;
			dl[++t]=i;
		}
	}
	printf("%.4lf\n",dp[K][n]);
	return 0;
}