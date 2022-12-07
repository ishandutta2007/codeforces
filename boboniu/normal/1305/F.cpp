#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 222222, M = 1000000;
mt19937 rnd(random_device{}());
int getRnd(int x)
{
	return rnd() % x;
}
int n;
i64 a[maxN], ans;
bool vis[M + 10];
vector<int> prime;
set<i64> checked;

void check(i64 y)
{
	if (y == 0)
		return;
	vector<i64> p;
	for (auto x : prime)
	{
		if ((i64)x * x > y)
			break;
		if (y % x == 0)
			p.push_back(x);
		while (y % x == 0)
			y /= x;
	}
	if (y != 1)
		p.push_back(y);
	for (auto z : p)
	{
		if (checked.count(z))
			continue;
		checked.insert(z);
		i64 sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < z)
				sum += z - a[i];
			else
			{
				i64 w = a[i] % z;
				sum += min(w, z - w);
			}
			if (sum > ans)
				break;
		}
		ans = min(ans, sum);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	auto start = clock();
	for (int i = 2; i * i <= M; i++)
		if (!vis[i])
		{
			for (int j = i * i; j <= M; j += i)
				vis[j] = 1;
		}
	for (int i = 2; i <= M; i++)
		if (!vis[i])
			prime.push_back(i);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	ans = n;
	random_shuffle(a, a + n, getRnd);
	for (int i = 0; i < n; i++)
	{
		if (clock() - start > 2 * CLOCKS_PER_SEC)
			break;
		check(a[i]);
		check(a[i] - 1);
		check(a[i] + 1);
	}
	cout << ans << endl;
}