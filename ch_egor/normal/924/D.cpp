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

const int MAX_N = 200 * 1000 + 228;

struct fr
{
	ll a;
	ll b;
};

bool operator<(const fr &a, const fr &b)
{
	return a.a * b.b < b.a * a.b;
}

bool operator==(const fr &a, const fr &b)
{
	return a.a * b.b == b.a * a.b;
}

int n;
ll w;
pair<ll, ll> arr[MAX_N];
vector<pair<fr, fr>> up;
vector<pair<fr, fr>> dw;
ll f[MAX_N];
set<fr> have;
map<fr, int> id;

ll get(ll x)
{
	ll ans = 0;
	for (int i = x; i > -1; i = (i & (i + 1)) - 1) ans += f[i];
	return ans;
}

void upd(int x, ll value)
{
	for (int i = x; i < MAX_N; i = (i | (i + 1))) f[i] += value;
}

bool cmp(const pair<fr, fr> &a, const pair<fr, fr> &b)
{
	return a.first < b.first || (a.first == b.first && b.second < a.second);
}

ll solve(vector<pair<fr, fr>> &now)
{
	memset(f, 0, sizeof(f));

	sort(now.begin(), now.end(), cmp);

	ll ans = 0;
	for (int i = 0; i < (int)now.size(); ++i)
	{
		int cur = id[now[i].second];
		ans += get(MAX_N - 1) - get(cur - 1);
		upd(cur, 1);
	}

	return ans;
}

ll fuck_solve()
{
	memset(f, 0, sizeof(f));

	return 0;
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%lld", &n, &w);
	
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld%lld", &arr[i].first, &arr[i].second);
		
		if (arr[i].first > 0) up.push_back({{arr[i].first, -arr[i].second + w}, {arr[i].first, -arr[i].second - w}});
		else dw.push_back({{-arr[i].first, arr[i].second + w}, {-arr[i].first, arr[i].second - w}});
	}
	
	for (int i = 0; i < (int)up.size(); ++i) have.insert(up[i].first), have.insert(up[i].second);
	for (int i = 0; i < (int)dw.size(); ++i) have.insert(dw[i].first), have.insert(dw[i].second);
	
	int cnt = 0;
	for (auto it = have.begin(); it != have.end(); ++it) id[*it] = cnt++;

	ll ans = 0;
	for (int i = 0; i < (int)dw.size(); ++i) swap(dw[i].first, dw[i].second);
	for (int i = 0; i < (int)dw.size(); ++i) up.push_back(dw[i]);
	ans += solve(up);
//	ans += solve(dw);

//	ans += fuck_solve();

	printf("%lld\n", ans);

	return 0;
}