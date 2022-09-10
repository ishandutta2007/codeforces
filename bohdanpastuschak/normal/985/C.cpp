#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>
#include <cassert>
#include <string.h>
#include <cstdio>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

typedef double LD;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LD, LD> PDD;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define next fake_next

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, t) FOR(i, 0, t)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const LD PI = acos(-1.0);
const LD EPS = 1e-8;
const LL INF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const LL MAX = 1 << 17;

int n, m, k, l;
int a[MAX];
LL ans = 0;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	
	cin >> n >> k >> l;
	m = n * k;
	FOR(i, 0, m)
		cin >> a[i];

	sort(a, a + m);
	if (a[n - 1] - a[0] > l)
	{
		cout << 0 << endl;
		return 0;
	}

	ans = a[0];
	int last = m;
	RFOR(i, m, 0)
	{
		if (a[i] - a[0] <= l)
		{
			last = i;
			break;
		}
	}

	int she = n - 1;
	int ost = 0;
	FOR(i, 1, last + 1)
	{
		if (i - ost == k && she)
		{
			ans += a[i];
			ost = i;
			--she;
			continue;
		}

		if (last - i < she)
		{
			ans += a[i];
			ost = i;
			--she;
			continue;
		}
	}


	
	cout << ans << endl;
	cin >> n;
	return 0;
}