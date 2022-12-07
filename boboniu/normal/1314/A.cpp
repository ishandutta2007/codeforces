#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
mt19937 rnd(random_device{}());

int n, a[300000], p[300000], order[300000];
i64 ans, s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
	{
		order[i] = i;
	}
	sort(order, order + n, [&](int x, int y) {
		return a[x] < a[y];
	});
	priority_queue<int> q;
	int t = 0, x = 0;
	while (x < n || !q.empty())
	{
		if (q.empty())
		{
			t = a[order[x]];
		}
		while (x < n && a[order[x]] == t)
		{
			s += p[order[x]];
			q.push(p[order[x]]);
			x += 1;
		}
		s -= q.top();
		q.pop();
		ans += s;
		t += 1;
	}
	cout << ans << endl;
}