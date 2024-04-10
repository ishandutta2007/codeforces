#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 200 * 1000 + 5;

//e-maxx code
ll gcd (ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

ll fast_gcd(ll a, ll b)
{
	return b ? fast_gcd(b, a % b) : a;
}

#define div div228

int n;
ll m;
bool used[MAX_N];
ll cnt[MAX_N];
vector<ll> div;
ll dp[MAX_N];
int last[MAX_N];
vector<ll> ans;
vector<ll> mem[MAX_N];
vector<ll> true_ans;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%lld", &n, &m);

	ll x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &x);
		used[x] = true;
	}

	for (ll i = 1; i * i <= m; ++i)
	{
		if (m % i == 0)
		{
			div.push_back(i);
			if (m / i != i) div.push_back(m / i);
		}
	}
	sort(div.begin(), div.end());
	
	for (int i = 0; i < m; ++i)
	{
		if (!used[i])
		{
			++cnt[fast_gcd(i, m)];
			mem[fast_gcd(i, m)].push_back(i);
		}
	}
	
	for (int i = 0; i < (int)div.size(); ++i)
	{
		dp[i] = cnt[div[i]];
		last[i] = -1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (div[i] % div[j] == 0)
			{
				if (dp[j] + cnt[div[i]] > dp[i])
				{
					dp[i] = dp[j] + cnt[div[i]];
					last[i] = j;
				}
			}
		}
	}
	
	int ptr = 0;
	for (int i = 0; i < (int)div.size(); ++i)
	{
		if (dp[ptr] < dp[i])
		{
			ptr = i;
		}
//		cout << dp[i] << " ";
	}
//	cout << endl;
	
	for (; ptr != -1; ptr = last[ptr])
	{
		for (int j = 0; j < (int)mem[div[ptr]].size(); ++j)
			ans.push_back(mem[div[ptr]][j]);
	}

	//for (int i = 0; i < (int)ans.size(); ++i)
	//	cout << ans[i] << " ";
	
	ll y;
	for (int i = (int)ans.size() - 1; i >= 0; --i)
	{
		ll last = 1;
		if (i != (int)ans.size() - 1) last = ans[i + 1];
		gcd(last, m, x, y);
		ll next = (x * ans[i]) / fast_gcd(m, last) % m;
		if (next < 0) next += m;
		true_ans.push_back(next);
	}
	
	printf("%d\n", (int)true_ans.size());
	for (int i = 0; i < (int)true_ans.size(); ++i)
	{
		printf("%lld ", true_ans[i]);
	}
	printf("\n");
	
/*	ll check = 1;
	for (int i = 0; i < (int)true_ans.size(); ++i)
	{
		check = (check * true_ans[i]) % m;
		assert(!used[check]);
		used[check] = true;
		printf("%lld ", check);
	}
	printf("\n");
*/
	return 0;
}