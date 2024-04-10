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
inline int lowbit(int x){return x&-x;}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,K,p,maxn[101],DP[20001][101],a[500001];
inline int MOD(int x){return x+((x>>31)&p);}
void sbsolve()
{
	memset(DP,-0x3f,sizeof(DP));
	DP[0][0]=0;
	for(int j=1;j<=K;++j)
	{
		memset(maxn,-0x3f,sizeof(maxn));
		for(int i=j-1;i<=n;++i)
		{
			for(int k=0;k<p;++k) DP[i][j]=max(DP[i][j],maxn[k]+MOD(a[i]-k));
			maxn[a[i]]=max(maxn[a[i]],DP[i][j-1]);
		}
	}
	printf("%d\n",DP[n][K]);
}
int main()
{
	n=read(),K=read(),p=read();
	for(int i=1;i<=n;++i) a[i]=MOD(a[i-1]+read()%p-p);
	sbsolve();
	return 0;
}