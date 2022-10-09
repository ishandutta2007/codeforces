#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>

typedef long long li;
typedef pair<int, int> pt;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sqr(a) ((a) * (a))
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sz(a) (int(a.size()))
#define all(a) a.begin(), a.end()

const int INF = int(1e9);
const li INF64 = INF * 1ll * INF;
const ld PI = acosl(-1.0);
const int MOD = INF + 7;
const ld EPS = 1e-9;

vector<li> a;
int n;
int cntdeg[60];

int maxdeg(li x)
{
	int ans = 0;
	while (x)
	{
		
		x = ((x == 1 ? x : x + 1)) / 2;
		if (x) ans++;
	}
	return ans;
}

bool check(int x)
{
	forn(i, 60) cntdeg[i] = 0;
	int cntlast = x;
	int cntcur = 0;
	li deglast = 1;
	int curdeg = 0;
	vector<li> rem;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == deglast)
		{
			if (cntcur == cntlast)
			{
				rem.push_back(a[i]);
			}
			else
			{
				cntcur++;
			}
		}
		else if (a[i] > deglast)
		{
			deglast <<= 1ll;
			if (a[i] > deglast)
				return false;
			cntdeg[curdeg] = cntcur;
			cntlast = cntcur;
			curdeg++;
			cntcur = 0;
			if (a[i] == deglast && cntcur < cntlast)
				cntcur++;
			else
				rem.push_back(a[i]);
		}
		else
		{
			rem.push_back(a[i]);
		}
	}
	cntdeg[curdeg] = cntcur;
	cntlast = cntcur;
	curdeg++;
	cntcur = 0;
	int lastcnt = 0;
	for (int i = 1; i < 60; i++)
		cntdeg[i - 1] -= cntdeg[i];
	for (auto z : rem)
	{
		while (lastcnt < 60 && (cntdeg[lastcnt] == 0 || maxdeg(z) > lastcnt + 1))
			lastcnt++;
		if (lastcnt == 60)
			return false;
		cntdeg[lastcnt]--;
	}
	return true;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	a.resize(n);
	forn(i, n)
		scanf("%lld", &a[i]);
	int cnt1 = 0;
	forn(i, n)
		if (a[i] == 1)
			cnt1++;
	if (!check(cnt1))
	{
		puts("-1");
		return 0;
	}
	int l = 0;
	int r = cnt1;
	while (r > l + 1)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	for (int i = r; i <= cnt1; i++)
		printf("%d ", i);
	return 0;
}