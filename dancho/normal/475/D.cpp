#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int n;
int a[100020];

typedef pair<int, int> pii;

vector<pii> gcds;

map<int, long long> mp;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		vector<pii> ne;
		ne.push_back(make_pair(a[i], i));
		for (int j = 0; j < (int) gcds.size(); ++j)
		{
			//~ printf("%d %d\n", gcd(a[i], gcds[j].first), gcd(a[i], gcds[j].first));
			//~ printf("%d\n", ne.back().first);
			if (gcd(a[i], gcds[j].first) != ne.back().first)
			{
				ne.push_back(make_pair(gcd(a[i], gcds[j].first), gcds[j].second));
			}
		}
		for (int j = 0; j < (int) ne.size(); ++j)
		{
			int nx;
			if (j + 1 < (int) ne.size())
				nx = ne[j + 1].second;
			else
				nx = n;
			mp[ne[j].first] += (long long) (nx - ne[j].second);
		}

		gcds = ne;
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", mp[x]);
	}
	
	
	return 0;
}