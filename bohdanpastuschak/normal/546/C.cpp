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
const LD EPS = 1e-9;
const LL INF = 1e18;
const LL LINF = 1e18;
const LL mod = 1e9 + 7;
const int MAX = 1 << 17;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	int n, a, b;
	cin >> n;
	queue<int> q1, q2;
	cin >> a;
	VI x1(a);
	FOR(i, 0, a)
		cin >> x1[i];
	cin >> b;
	VI x2(b);
	FOR(i, 0, b)
		cin >> x2[i];

	for (auto i : x1)
		q1.push(i);
	for (auto i : x2)
		q2.push(i);

	int ans = 0;
	while (!q1.empty() && !q2.empty())
	{
		if (ans > 1e5)
		{
			cout << -1 << endl;
			return 0;
		}

		++ans;
		a = q1.front();
		b = q2.front();
		q1.pop();
		q2.pop();

		if (a > b)
		{
			q1.push(b);
			q1.push(a);
		}
		else
		{
			q2.push(a);
			q2.push(b);
		}
	}

	cout << ans << " ";
	if (q1.empty())
		cout << 2;
	else
		cout << 1;

	cout << endl;
	cin >> n;
	return 0;
}