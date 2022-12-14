#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;

int n, s, l;
int a[1 << 17];

int mx[1 << 19];
int mn[1 << 19];

void it_add(int nd, int nl, int nr, int p, int v)
{
	if (nl > p || p > nr)
		return;
	if (nl == p && nr == p)
	{
		mx[nd] = mn[nd] = v;
		return;
	}
	it_add(2 * nd, nl, (nl + nr) / 2, p, v);
	it_add(2 * nd + 1, (nl + nr) / 2 + 1, nr, p, v);
	mn[nd] = min(mn[2 * nd], mn[2 * nd + 1]);
	mx[nd] = max(mx[2 * nd], mx[2 * nd + 1]);
}

void it_add(int p, int v)
{
	return it_add(1, 1, (1 << 17), p, v);
}

int it_mx(int nd, int nl, int nr, int le, int ri)
{
	if (nl > ri || le > nr)
	{
		return -1000000100;
	}
	if (le <= nl && nr <= ri)
		return mx[nd];
	return max(it_mx(2 * nd, nl, (nl + nr) / 2, le, ri),
			   it_mx(2 * nd + 1, (nl + nr) / 2 + 1, nr, le, ri));
}

int it_mn(int nd, int nl, int nr, int le, int ri)
{
	if (nl > ri || le > nr)
	{
		return 1000000100;
	}
	if (le <= nl && nr <= ri)
		return mn[nd];
	return min(it_mn(2 * nd, nl, (nl + nr) / 2, le, ri),
			   it_mn(2 * nd + 1, (nl + nr) / 2 + 1, nr, le, ri));
}

int it_get(int le, int ri)
{
	return it_mx(1, 1, (1 << 17), le, ri) - it_mn(1, 1, (1 << 17), le, ri);
}

int dp[1 << 17];
typedef pair<int, int> pii;

deque<pii> st;

int main()
{
	scanf("%d %d %d", &n, &s, &l);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		it_add(i, a[i]);
	}
	
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	//~ st.push(make_pair(dp[0], 0));
	for (int i = 1; i <= n; ++i)
	{
		// add i - l
		if (i - l >= 0)
		{
			if (dp[i - l] != dp[n + 1])
			{
				while (st.size() && dp[i - l] <= st[st.size() - 1].first)
				{
					st.pop_back();
				}
				st.push_back(make_pair(dp[i - l], i - l));
			}
		}
		while (st.size() && it_get(st[0].second + 1, i) > s)
		{
			st.pop_front();
		}
		if (st.size() && st[0].second <= i - l)
		{
			dp[i] = st[0].first + 1;
		}
	}
	
	if (dp[n] == dp[n + 1])
		printf("-1\n");
	else
		printf("%d\n", dp[n]);
	
	return 0;
}