#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int n;
long long a[510000];
int main()
{
	cin>>n;

	rep(i,n)scanf("%lld",&a[i]);
		if (n==1){ cout<<a[1]<<endl; return 0; }
	int allneg=1,allpos=1;
	long long minpos=2147483647,maxneg=-2147483647;
	long long sum1=0; rep(i,n)if (a[i]>=0)allneg=0,sum1+=a[i],minpos=min(minpos,a[i]);
	long long sum2=0; rep(i,n)if (a[i]<=0)allpos=0,sum2-=a[i],maxneg=max(maxneg,a[i]);

	if (!allneg && !allpos)cout<<sum1+sum2<<endl;
	else if (allneg)cout<<sum2+2*maxneg<<endl;
	else cout<<sum1-2*minpos<<endl;
}