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
int n,k;
long long a[110000],b[110000];
long long suma,sumb;
int main()
{
	cin>>n;
	suma=sumb=0;
	rep(i,n){ scanf("%lld",&a[i]); suma+=a[i]; } sort(a+1,a+n+1); reverse(a+1,a+n+1);
	rep(i,n){ scanf("%lld",&b[i]); sumb+=b[i]; } sort(b+1,b+n+1); reverse(b+1,b+n+1);

	int x=1,y=1;
	for(int i=1;i<=2*n;i++)
	{
		if (i%2==1)
		{
			if (y>n){ x++; continue; }
			if (x>n){ sumb-=b[y++]; continue; }
			if (a[x]>=b[y])x++; else sumb-=b[y],y++;
		}
		if (i%2==0)
		{
			if (x>n){ y++; continue; }
			if (y>n){ suma-=a[x++]; continue; }
			if (b[y]>=a[x])y++; else suma-=a[x++];
		}
		//cout<<suma<<" "<<sumb<<endl;
	}
	cout<<suma-sumb<<endl;
}