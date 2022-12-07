#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxN = 333333;

int n;
int posp[maxN], posq[maxN], p[maxN], q[maxN];
int val[maxN * 4], tag[maxN * 4];

void push(int id)
{
	if (tag[id] != 0)
	{
		tag[id * 2] += tag[id];
		val[id * 2] += tag[id];
		tag[id * 2 + 1] += tag[id];
		val[id * 2 + 1] += tag[id];
		tag[id] = 0;
	}
}
void modify(int id, int l, int r, int x, int y, int v)
{
	if (y < l || x > r)
		return;
	if (x <= l && r <= y)
	{
		tag[id] += v;
		val[id] += v;
	}
	else
	{
		push(id);
		int mid = (l + r) / 2;
		modify(id * 2, l, mid, x, y, v);
		modify(id * 2 + 1, mid + 1, r, x, y, v);
		val[id] = max(val[id * 2], val[id * 2 + 1]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		posp[p[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> q[i];
	}
	int ans = n;
	cout << ans;
	modify(1, 1, n, 1, posp[n], 1);
	for (int i = 1; i < n; i++)
	{
		modify(1, 1, n, 1, q[i], -1);
		while (val[1] <= 0)
		{
			ans -= 1;
			modify(1, 1, n, 1, posp[ans], 1);
		}
		cout << " " << ans;
	}
}