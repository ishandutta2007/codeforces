#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
#define inf 998244353
using namespace std;
int n,k;
long long a[210000];
vector<int> pos;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	long long sum=0,ans=1;
	for(int i=1;i<=n;i++)
		if (a[i]>=n-k+1)sum+=a[i],pos.pb(i);
	for(int i=1;i<k;i++)
		ans=ans*(long long)(pos[i]-pos[i-1])%inf;
	cout<<sum<<" "<<ans<<endl;
}
/*
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		scanf("%d",&n);
		if (n==1){ puts("-1"); continue; }
		int opt=2*(n-1)%3;
		if (opt==0)
		{
			for(int i=1;i<=n-2;i++)putchar('2');
			puts("33");
		}
		else
		{
			for(int i=1;i<=n-1;i++)putchar('2');
			puts("3");
		}
	}
	return 0;
}
*/