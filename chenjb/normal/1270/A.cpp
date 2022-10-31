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
int main()
{	
	int T;
	cin>>T;
	while (T--)
	{
		int n,k1,k2;
		scanf("%d%d%d",&n,&k1,&k2);
		int max1=0,max2=0;
		for(int i=1;i<=k1;i++){ int x; scanf("%d",&x); max1=max(max1,x); }
		for(int i=1;i<=k2;i++){ int x; scanf("%d",&x); max2=max(max2,x); }
		if (max1>max2)puts("YES"); else puts("NO");
	}
	return 0;
}