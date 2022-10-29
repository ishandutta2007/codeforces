#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
int n,p;
int get(int x)
{
	int cnt=0;
	for (int i=62;i>=0;i--) cnt+=((x>>i)&1);
	return cnt;
}
signed main()
{
	scanf("%lld%lld",&n,&p);
	for (int i=1;i<=63;i++)
	{
		int x=n-i*p;
		if (x<=0) break;
		if (get(x)<=i && x>=i)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	printf("-1\n");
}