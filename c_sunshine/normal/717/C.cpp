#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int M=10007;
int a[100005],n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+(a[i]%M)*(a[n-i+1]%M))%M;
	}
	printf("%d\n",ans);
	return 0;
}