#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> comp(MAXN);
vector<long long> bit(MAXN);
vector<int> bit1(MAXN);
vector<pair<int, int>> point(MAXN);

long long query(int i)
{
	long long res = 0;
	for(; i; i -= i &- i)
		res += bit[i];
	return res;
}

int query1(int i)
{
	int res = 0;
	for(; i; i -= i &- i)
		res += bit1[i];
	return res;
}

long long tot = 0;
void update0(int i, long long v)
{
	tot += v;
	for (; i <= comp.size(); i += i &- i)
		bit[i] += v;
}

int cnt = 0;
void update1(int i, int v)
{
	cnt += v;
	for(; i <= comp.size(); i += i &- i)
		bit1[i] += v;
}

void update(int i, long long v, int d)
{
	update0(i, v * d);
	update1(i, d);
}

int main()
{
	int n;
	scanf("%i", &n);
	for (int x = 0; x < n; x++)
		scanf("%i", &point[x].first);
	for (int x = 0; x < n; x++)
	{
		scanf("%i", &point[x].second);
		comp[x] = point[x].second;
	}
	sort(point.begin(), point.begin() + n);
	sort(comp.begin(), comp.begin() + n);
	comp.erase(unique(comp.begin(), comp.begin() + n), comp.end());
	for (int x = 0; x < n; x++)
		update(lower_bound(comp.begin(), comp.end(), point[x].second) - comp.begin() + 1, point[x].first, 1);
	long long ans = 0;
	for (int x = 0; x < n; x++)
	{
		int y = lower_bound(comp.begin(), comp.end(), point[x].second) - comp.begin() + 1;
		update(y, point[x].first, -1);
		ans += tot - query(y - 1) - (long long)(cnt - query1(y - 1)) * point[x].first;
	}
	printf("%lli\n", ans);
}