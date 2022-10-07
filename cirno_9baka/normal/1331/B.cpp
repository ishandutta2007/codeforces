#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=262144;
const int M=998244353;
int n,i;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=2;i<=n;++i)
		if(n%i==0)
		{
			printf("%d%d",i,n/i);
			return 0;
		}
}