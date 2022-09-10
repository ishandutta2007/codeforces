#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include <set>
#include <bitset>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<char> VCH;
typedef vector<VI> VVI;
typedef vector<VLL> VVLL;
typedef vector<VCH> VVCH;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<LD, LD> PDD;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;

#define SZ(a) (LL)(a.size())
#define ALL(a) a.begin(), a.end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define MP make_pair
#define X first
#define Y second
#define next fake_next
#define left fake_left
#define right fake_right

const LD PI = acos(-1.0);
const LL MAXN = 1001;
const LL mod = 1000000007;
const LL INF = 1e9;

int comp(VI a, VI b)
{
	return SZ(a) > SZ(b);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n;
	cin >> n;
	VI p(1 + n);
	FOR(i, 1, 1 + n)
		cin >> p[i];

	set<int> petli;
	VCH used(n + 1, 0);
	FOR(i, 1, n + 1)
		if (p[i] == i)
			petli.insert(i), used[i] = 1;

	VVI cycly;
	VI cycl;
	
	FOR(i,1,n+1)
		if (used[i] == 0)
		{
			cycl.clear();
			int t = i;
			do
			{
				cycl.push_back(t);
				used[t] = 1;
				t = p[t];
			} while (t != i);

			cycly.push_back(cycl);
		}

	LL ans = 0;
	if (SZ(cycly) == 0)
	{
		if (n == 1)
			cout << 1;
		else
			cout << n + 2;
		return 0;
	}

	if (SZ(cycly) == 1)
	{
		if (SZ(petli) == 0)
		{
			ans = n * 1LL * n;
		}
		else
		{
			ans = SZ(petli) - 1;
			ans += (SZ(cycly[0]) + 1) * 1LL * (SZ(cycly[0]) + 1);
		}
	}
	else
	{
		ans = SZ(petli);
		sort(ALL(cycly), comp);
		LL to_add = 0;
		to_add += (SZ(cycly[0]) + SZ(cycly[1])) * 1LL * (SZ(cycly[0]) + SZ(cycly[1]));
		FOR(i, 2, SZ(cycly))
			to_add += SZ(cycly[i]) * 1LL * SZ(cycly[i]);
		ans += to_add;
	}

	cout << ans;
	//cin >> n;
	return 0;
}