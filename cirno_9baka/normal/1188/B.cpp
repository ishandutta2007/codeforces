#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=1000000007;
const int N=500005;
long long i,n,p,k,a[N],pu[N],j;
long long ans;
int main()
{
	scanf("%I64d %I64d %I64d",&n,&p,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		pu[i]=((a[i]*a[i]%p*a[i]%p*a[i]-k*a[i])%p+p)%p;
	}
	sort(pu+1,pu+1+n);
	for(i=1;i<=n;)
	{
		for(j=i;pu[i]==pu[j]&&j<=n;j++);
		ans+=1ll*(j-i)*(j-i-1)/2;
		i=j;
	}
	cout<<ans;
}