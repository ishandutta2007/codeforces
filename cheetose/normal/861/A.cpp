#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
ll pow(int n)
{
	ll c = 1;
	for (int i = 0; i < n; i++)
		c *= 10;
	return c;
}
int main()
{
	ll n;
	int k;
	scanf("%I64d%d", &n, &k);
	ll t = pow(k), m = n;
	while (1)
	{
		if (m%t == 0)break;
		m += n;
	}
	printf("%I64d", m);
}