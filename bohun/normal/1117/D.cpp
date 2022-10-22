#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m;
const int mod=1e9+7;
struct matrix
{
	int t[105][105];
	matrix()
	{
		memset(t,0,sizeof(t));
	}
	matrix operator * (const matrix a)
	{
		matrix c=matrix();
		for(int i=1;100>=i;i++)
			for(int k=1;100>=k;k++)
				for(int j=1;100>=j;j++)
					c.t[i][j]=(c.t[i][j]+(ll)t[i][k]*a.t[k][j])%mod;
		return c;
	}
};
matrix dp;
matrix pot(matrix x, ll pot)
{
	pot--;
	matrix ans=x;
	while(pot)
	{
		if(pot%2==1)
			ans=ans*x;
		x=x*x;
		pot/=2;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	dp.t[1][0]=1;
	for(int i=1;100>=i;i++)
	{
		dp.t[1][i]+=dp.t[1][i-1];
		if(i-m>=0)
			dp.t[1][i]+=dp.t[1][i-m];
		dp.t[1][i]%=mod;
	}
	if(n<=100)
	{
		cout<<dp.t[1][n];
		return 0;
	}
	matrix d=matrix();
	for(int i=1;99>=i;i++)
		d.t[i+1][i]=1;
	d.t[100][100]=1;
	d.t[100-m+1][100]=1;
	d=pot(d,n-100);
	dp=dp*d;
	cout<<dp.t[1][100];
	
    return 0;	
}