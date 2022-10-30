#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
using namespace std;
int a[11000];
int main()
{
	int n;
	cin>>n;
	rep(i,n)scanf("%d",&a[i]);
	int ans=0;
	int now=0;
	for(int i=1;i<=n;)
	{
		ans++;
		now=max(now,a[i]);
		while (i<now)i++,now=max(now,a[i]);
		i++;
	}
	cout<<ans<<endl;
	return 0;
}