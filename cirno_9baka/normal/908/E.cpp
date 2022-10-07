#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,m,i,j;
long long f[1005][1005],ans=1,a[1005];
map<long long,int> mp;
char c[55][1005];
int main()
{
	scanf("%d %d",&m,&n);
	f[0][0]=1;
	for(i=1;i<=1000;++i)
		for(j=1;j<=i;++j)
			f[i][j]=(f[i-1][j]*j+f[i-1][j-1])%M;
	for(i=1;i<=1000;++i)
		for(j=1;j<=i;++j)
			a[i]=(a[i]+f[i][j])%M;
	for(i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	for(i=1;i<=m;++i)
	{
		long long s=0;
		for(j=1;j<=n;++j)
			s|=1ll*(c[j][i]-'0')<<j;
		++mp[s];
	}
	for(auto it:mp)
		ans=ans*a[it.second]%M;
	cout<<(ans%M+M)%M;
}