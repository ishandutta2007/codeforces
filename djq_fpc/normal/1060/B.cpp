#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,ans;
int main()
{
	scanf("%I64d",&n);
	while (n>9)
	{
		n-=9;
		ans+=9;
		ans+=n%10;
		n/=10;
	}
	cout<<ans+n;
}