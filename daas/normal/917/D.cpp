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
const int mod=1e9+7;
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
int n,poly[101][101][2],A[101][101],y[101],sum[101],inv[101],ans,mtx[101][110];
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
int Gauss(int n)
{
	int bck=1;
	for(int i=1;i<=n;++i)
	{
		int bj=-1;
		for(int j=i;j<=n;++j) if(A[j][i]) {bj=j;break;}
		if(bj==-1) return 0;
		if(i!=bj) swap(A[i],A[bj]),bck=MOD(-bck);
		bck=(ll)bck*A[i][i]%mod;
		int inv=ksm(A[i][i],mod-2);
		for(int j=i+1;j<=n;++j)
		{
			int p=(ll)inv*A[j][i]%mod;
			for(int k=i;k<=n;++k) A[j][k]=MOD(A[j][k]-(ll)A[i][k]*p%mod);
		}
	}
	return bck;
}
int main()
{
	n=read();
	sum[0]=1;
	for(int i=1;i<=n;++i) sum[i]=(ll)i*sum[i-1]%mod;
	inv[n]=ksm(sum[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=(ll)(i+1)*inv[i+1]%mod;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		poly[u][v][1]-=1;
		poly[v][u][1]-=1;
		poly[u][u][1]+=1;
		poly[v][v][1]+=1;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(!poly[i][j][1])
			{
				poly[i][j][0]-=1;
				poly[j][i][0]-=1;
				poly[i][i][0]+=1;
				poly[j][j][0]+=1;
			}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				A[j][k]=MOD(i*poly[j][k][1]+poly[j][k][0]);
		for(int j=0,p=1;j<n;++j,p=(ll)p*i%mod) mtx[i][j+1]=p;
		mtx[i][n+1]=Gauss(n-1);
	}
	for(int i=1;i<=n;++i)
	{
		/*int bj=-1;
		for(int j=i;j<=n;++j) if(mtx[j][i]) {bj=j;break;}
		if(i!=bj) swap(mtx[i],mtx[bj]);*/
		int inv=ksm(mtx[i][i],mod-2);
		for(int j=1;j<=n;++j)
		{
			if(i==j) continue;
			int p=(ll)inv*mtx[j][i]%mod;
			for(int k=i;k<=n+1;++k) mtx[j][k]=MOD(mtx[j][k]-(ll)mtx[i][k]*p%mod);
		}
	}
	for(int i=1;i<=n;++i) printf("%lld ",(ll)mtx[i][n+1]*ksm(mtx[i][i],mod-2)%mod);
	return 0;
}