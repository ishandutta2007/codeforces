#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#define LL long long 
using namespace std;
int main()
{
	LL n,k;
	LL a[110000];
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int flag=1;
	LL ans=0;
	for(int i=2;i<=n;i++)
		if ((a[i]-a[1])%k!=0){flag=0; break;}
		else ans+=((a[i]-a[1])/k);
	if (!flag )ans=-1;
	cout<<ans<<endl;
	return 0;
}