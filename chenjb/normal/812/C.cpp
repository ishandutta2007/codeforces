#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
using namespace std;
int n;
LL s;
int a[110000];
LL b[110000];
LL get(int tot)
{
	LL ans=0;
	for(int i=1;i<=n;i++)b[i]=(LL)(a[i])+(LL)(i)*(LL)(tot);
	sort(b+1,b+n+1);
	for(int i=1;i<=tot;i++)
	{
		ans+=b[i];
		if (ans>s+1)return s*2;
	}
	return ans;
}
int main()
{	
	cin>>n>>s;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0;
	int r=n;
	while (l<r)
	{
		int mid=(l+r)/2  + 1;
		if (get(mid)<=s)l=mid;
		else r=mid-1;
	}
	cout<<l<<" "<<get(l)<<endl;
	return 0;
}