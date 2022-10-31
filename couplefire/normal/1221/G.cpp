#include <bits/stdc++.h>

using namespace std;

const int N = 40;
const int M = 20;

long long incident_mask[N];
vector<int> g[N];
int n, m;
long long ans = 0;
long long cntmask[1 << M];

long long binpow(long long x, long long y)
{
	long long z = 1;
	while(y > 0)
	{
		if(y % 2 == 1) z *= x;
		x *= x;
		y /= 2;
	}
	return z;
}

int used[N];

void dfs(int x, int c)
{
	if(used[x])
		return;
	used[x] = c;
	for(auto y : g[x])
		dfs(y, 3 - c);
}

long long countIsolated()
{
	long long ans = 0;
	for(int i = 0; i < n; i++)
		if(g[i].empty())
			ans++;
	return ans;
}

long long countComponents()
{
	memset(used, 0, sizeof used);
	long long ans = 0;
	for(int i = 0; i < n; i++)
		if(!used[i])
		{
			ans++;
			dfs(i, 1);
		}
	return ans;
}

bool bipartite()
{
	memset(used, 0, sizeof used);
	for(int i = 0; i < n; i++)
		if(!used[i])
			dfs(i, 1);
	for(int i = 0; i < n; i++)
		for(auto j : g[i])
			if(used[i] == used[j])
				return false;
	return true;
}

long long countIndependentSets()
{
	int m1 = min(n, 20);
	int m2 = n - m1;
	//cerr << m1 << " " << m2 << endl;
	memset(cntmask, 0, sizeof cntmask);
	for(int i = 0; i < (1 << m1); i++)
	{
		long long curmask = 0;
		bool good = true;
		for(int j = 0; j < m1; j++)
		{
			if((i & (1 << j)) == 0)
				continue;
			if(curmask & (1 << j))
				good = false;
			curmask |= ((1 << j) | incident_mask[j]);
		}
		if(good)
		{
			cntmask[curmask >> m1]++;
		}
	}	
	for(int i = 0; i < m2; i++)
		for(int j = 0; j < (1 << m2); j++)
			if(j & (1 << i))
				cntmask[j] += cntmask[j ^ (1 << i)];
	long long ans = 0;
	for(int i = 0; i < (1 << m2); i++)
	{
		long long curmask = 0;
		bool good = true;
		for(int j = m1; j < n; j++)
		{
			if((i & (1 << (j - m1))) == 0)
				continue;
			if(curmask & (1ll << j))
				good = false;
			curmask |= (1ll << j) | incident_mask[j];
		}
		if(good)
		{
			//cerr << i << endl;
			ans += cntmask[(i ^ ((1 << m2) - 1))];
		}
	}
	return ans;
}

long long calc(int mask)
{
	if(mask == 0)
		return binpow(2, n);
	if(mask == 1 || mask == 4)
		return countIndependentSets();
	if(mask == 2)
		return binpow(2, countComponents());
	if(mask == 3 || mask == 6)
		return binpow(2, countIsolated());
	if(mask == 5)
		return (bipartite() ? binpow(2, countComponents()) : 0);
	if(mask == 7)
		return (m == 0 ? binpow(2, n) : 0);
	return 0;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x].push_back(y);
		g[y].push_back(x);
		incident_mask[x] ^= (1ll << y);
		incident_mask[y] ^= (1ll << x);
	}
	for(int i = 0; i < 8; i++)
	{
		//cerr << i << " " << calc(i) << endl;
		if(__builtin_popcount(i) % 2 == 0)
			ans += calc(i);
		else
			ans -= calc(i);
	}
	cout << ans << endl;
    return 0;
}