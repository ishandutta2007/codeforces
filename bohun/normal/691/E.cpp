#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int mod=1e9+7;
long long k;
struct matrix{
	int t[102][102];
	matrix ()
	{
		memset(t,0,sizeof(t));
	}
	matrix operator * (const matrix a)
	{
		matrix res=matrix();
		for(int i=1;n>=i;i++)
		for(int k=1;n>=k;k++)
		for(int j=1;n>=j;j++)
		res.t[i][j]=(res.t[i][j]+(long long)t[i][k]*a.t[k][j]%mod)%mod;
		return res;
	}
};
long long tab[105];
int licz(long long x)
{
	int res=0;
	for(int i=0;60>=i;i++)
	{
		if((1LL<<i)&x)
  		res++;
	}
	return res;
}    
matrix pot(matrix x,long long y)
{
	matrix res=matrix();
	for(int i=1;n>=i;i++)
			res.t[i][i]=1;
	while(y>0)
	{
		if(y%2==1)
		res=res*x;
		x=x*x;
		y/=2;
	}
	return res;
}
int main() {
	matrix A,B;
	A=B=matrix();
	cin>>n>>k;
	for(int i=1;n>=i;i++)
	cin>>tab[i];
	for(int i=1;n>=i;i++)
			for(int j=1;n>=j;j++)
			{
				if(licz(tab[i]^tab[j])%3==0)
				{
				A.t[1][i]++;
				B.t[j][i]=1;
			 	}
				
	 		}
	if(k==1)
	{
	 	cout<<n;
		return 0;
	}
		B=pot(B,k-2);
		A=A*B;
		ll ans=0;
		for(int i=1;n>=i;i++)
		ans+=A.t[1][i];
		cout<<ans%mod;
		return 0;
}