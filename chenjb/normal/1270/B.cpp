#include <cstdio>
#include <iostream>	
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long 
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 gtmshb
#define x1 gtmjtjl
#define y0 gtmsub
#define y1 gtmsf
int n,a[210000];
int main()
{	
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans1=-1,ans2=-1;
		for(int i=1;i<n;i++)
			if (abs(a[i+1]-a[i])>=2)ans1=i,ans2=i+1;
		if (ans1==-1)puts("NO"); 
		else printf("YES\n%d %d\n",ans1,ans2);
	}
	return 0;
}