#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

map<int, pair<int, int>> arr;

pair<int, int> restore(int x, int l)
{
	if (x > l)
		return {l, 2 * l - x};
	else
		return {x, l};
}

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 0; x < n; x++)
	{
		int a, b;
		scanf("%i%i", &a, &b);
		int c = max(a, b);
		if (!arr.count(c))
		{
			arr[c].first = INT_MAX;
			arr[c].second = INT_MIN;
		}
		if (b >= a)
		{
			arr[b].first = min(arr[b].first, a);
			arr[b].second = max(arr[b].second, a);
		}
		else
		{
			arr[a].first = min(arr[a].first, 2 * a - b);
			arr[a].second = max(arr[a].second, 2 * a - b);
		}
	}
	long long dpl = 0, dpr = 0;
	int lx = 0, ly = 0, rx = 0, ry = 0;
	for (auto &x : arr)
	{
		int nlx, nly, nrx, nry;
		auto p = restore(x.second.first, x.first);
		nlx = p.first, nly = p.second;
		p = restore(x.second.second, x.first);
		nrx = p.first, nry = p.second;
		long long ndpr = min(dpl + abs(nlx - lx) + abs(nly - ly), dpr + abs(nlx - rx) + abs(nly - ry)) + x.second.second - x.second.first;
		long long ndpl = min(dpl + abs(nrx - lx) + abs(nry - ly), dpr + abs(nrx - rx) + abs(nry - ry)) + x.second.second - x.second.first;
		lx = nlx, ly = nly, rx = nrx, ry = nry;
		dpl = ndpl, dpr = ndpr;
	}
	printf("%lli\n", min(dpl, dpr));
}