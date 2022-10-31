#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n,s;
long long a[210000];
int main()
{
	cin>>n>>s;
	rep(i,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n/2;i++)if (a[i]>s)ans+=(a[i]-s);
	ans+=abs(s-a[(n+1)/2]);
	for(int i=n/2 + 2;i<=n;i++)if (a[i]<s)ans+=(s-a[i]);
	cout<<ans<<endl;
	return 0;
}