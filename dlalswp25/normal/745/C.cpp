#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int par[1005];
bool gov[1005];
int size[1005];
vector<int> nation;

int parent(int x)
{
	if(par[x] == x)	return x;
	return par[x] = parent(par[x]);
}

int main()
{
	int n, m, k;	scanf("%d %d %d", &n, &m, &k);

	for(int i = 0; i < k; i++)
	{
		int x;	scanf("%d", &x);
		gov[x] = true;
	}
	for(int i = 1; i <= n; i++)	par[i] = i;
	for(int i = 1; i <= n; i++)	size[i] = 1;
	for(int i = 0; i < m; i++)
	{
		int a, b;	scanf("%d %d", &a, &b);
		if(parent(a) != parent(b))
		{
			size[par[b]] += size[par[a]];
			par[par[a]] = par[b];
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(!gov[i])	continue;
		nation.push_back(size[parent(i)]);
	}

	int sum = 0;
	for(int i = 0; i < nation.size(); i++)	sum += nation[i];
	sort(nation.begin(), nation.end());
	int sz = nation.size();
	nation[sz - 1] += (n - sum);


	int ans = 0;
	for(int i = 0; i < nation.size(); i++)
	{
		int x = nation[i];
		ans += (x - 1) * x / 2;
	}
	printf("%d", ans - m);
	return 0;
}