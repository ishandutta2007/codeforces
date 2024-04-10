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

int fracs[] = { 32, 16, 8, 4, 2, 1 };
int score[] = { 3000, 2500, 2000, 1500, 1000, 500 };
int deg[5];
int borderl[6];
int borderr[6];
int minv[5];
int minp[5];
int cntacc[5];
int n;

bool check_num(int x)
{
	x += n;
	borderl[0] = 0;
	borderr[0] = x / 32;
	borderl[1] = borderr[0] + 1;
	borderr[1] = x / 16;
	borderl[2] = borderr[1] + 1;
	borderr[2] = x / 8;
	borderl[3] = borderr[2] + 1;
	borderr[3] = x / 4;
	borderl[4] = borderr[3] + 1;
	borderr[4] = x / 2;
	borderl[5] = borderr[4] + 1;
	borderr[5] = x;
	x -= n;
	for(deg[0] = 0; deg[0] < 6; deg[0]++)
		for (deg[1] = 0; deg[1] < 6; deg[1]++)
			for (deg[2] = 0; deg[2] < 6; deg[2]++)
				for (deg[3] = 0; deg[3] < 6; deg[3]++)
					for (deg[4] = 0; deg[4] < 6; deg[4]++)
					{
						bool flag = true;
						for (int i = 0; i < 5; i++)
						{
							int minacc = cntacc[i];
							int maxacc = (minv[i] == -1 ? minacc : minacc + x);
							if (max(minacc, borderl[deg[i]]) > min(maxacc, borderr[deg[i]]))
								flag = false;
						}
						if (!flag) continue;
						int vscore = 0;
						int pscore = 0;
						for (int i = 0; i < 5; i++)
						{
							if (minv[i] != -1)
								vscore += (score[deg[i]]) - (score[deg[i]] / 250 * minv[i]);

							if (minp[i] != -1)
								pscore += (score[deg[i]]) - (score[deg[i]] / 250 * minp[i]);
						}
						if (vscore > pscore)
							return true;
					}

	return false;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	forn(i, n)
	{
		forn(j, 5)
		{
			int k;
			cin >> k;
			if (k != -1)
				cntacc[j]++;
			if (i == 0)
				minv[j] = k;
			if (i == 1)
				minp[j] = k;
		}
	}
	for (int i = 0; i < 141; i++)
		if (check_num(i))
		{
			cout << i << endl;
			return 0;
		}
	if (!check_num(MOD))
	{
		puts("-1");
		return 0;
	}
	int l = 140;
	int r = MOD + 1;
	while (r > l + 1)
	{
		int mid = (l + r) >> 1;
		if (check_num(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	return 0;
}