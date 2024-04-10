#pragma comment(linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

typedef long long int64;
//#define double long double
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i, n)  for (int i = 0; i < int(n); ++i)
#define ford(i, n)  for (int i=int(n) - 1; i >= 0; --i)
#define fore(i, l, r)  for (int i = int(l); i < int(r); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 5;
const int MAXV = 10001;


int n, l[MAXN], r[MAXN];


bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n)
		cin >> l[i] >> r[i];
	return true;
}


double get_exact_prob(int who, int val) {
	return (l[who] <= val && val <= r[who]) ? (1.0 / (r[who] - l[who] + 1)) : 0.0;
}

double get_atgreatest_prob(int who, int val) {
	int len = max(0, val - l[who] + 1);
	len = min(len, r[who] - l[who] + 1);
	return len * 1.0 / (r[who] - l[who] + 1);
}

double get_atleast_prob(int who, int val) {
	int len = max(0, r[who] - val + 1);
	len = min(len, r[who] - l[who] + 1);
	return len * 1.0 / (r[who] - l[who] + 1);
}

void solve() {
	double ans = 0;
	double sum_prob = 0;
	forn(mx2, MAXV) {
		/*
		forn(mask2, (1 << n) - 1) {
			if (mask2 == 0 && mx2)
				continue;

			fore(mx1, mx2 + 1, 100) {
				fore(mask1, 1, 1 << n) {
					if (mask2 & mask1)
						continue;

					double prob = 1.0;
					forn(i, n)
						if (mask2 & (1 << i))
							prob *= get_exact_prob(i, mx2);
						else if (mask1 & (1 << i))
							prob *= get_exact_prob(i, mx1);
						else
							prob *= get_atgreatest_prob(i, mx2 - 1);
					ans += prob * mx2;
					sum_prob += prob;
					if (prob > EPS) {
						prob = prob;
					}
				}
			}
		}
		*/

		fore(mask2, 1, (1 << n) - 1) {
			forn(who1, n) {
				if (mask2 & (1 << who1))
					continue;

				double prob = 1.0;
				forn(i, n)
					if (mask2 & (1 << i))
						prob *= get_exact_prob(i, mx2);
					else if (i == who1)
						prob *= get_atleast_prob(i, mx2 + 1);
					else
						prob *= get_atgreatest_prob(i, mx2 - 1);
				ans += prob * mx2;
				sum_prob += prob;
			}
		}

		forn(mask12, 1 << n) {
			int cnt12 = 0;
			double prob = 1.0;
			forn(i, n)
				if (mask12 & (1 << i)) {
					prob *= get_exact_prob(i, mx2);
					++cnt12;
				} else {
					prob *= get_atgreatest_prob(i, mx2 - 1);
				}
			if (cnt12 > 1) {
				ans += prob * mx2;
				sum_prob += prob;
			}
		}
	}

	printf("%.20lf\n", ans);
	cerr << sum_prob << endl;
}


int main() {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	while (read())
		solve();
#else
	if (!read())
		throw;
	solve();
#endif
}