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
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 310000;


int n, price[MAXN];


bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n)
		scanf("%d", &price[i]);
	return true;
}


void solve() {
	multiset<int> free;
	multiset<pair<int,int>> pairs;
	ford(i, n) {
		int cur = price[i];
		for(;;) {
			int cand1 = 0;
			if (free.size() && *--free.end() > cur)
				cand1 = *--free.end() - cur;
			int cand2 = 0;
			if (pairs.size() && (--pairs.end())->fs > cur)
				cand2 = (--pairs.end())->fs - cur;
			if (!cand1 && !cand2)
				break;
			if (cand1 >= cand2) {
				pairs.insert(mp(cur, *--free.end()));
				free.erase(--free.end());
				cur = -1;
				break;
			} else {
				pair<int,int> p = *--pairs.end();
				pairs.erase(--pairs.end());
				pairs.insert(mp(cur, p.sc));
				cur = p.fs;
			}
		}
		if (cur != -1)
			free.insert(cur);
	}

	int64 ans = 0;
	for (auto p : pairs)
		ans += p.sc - p.fs;
	cout << ans << endl;
}


int main() {
#ifdef EMAXX_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int tt = 0;
	while (read()) {
		cerr << "Case " << ++tt << ": starting..." << endl;
		solve();
	}
    cerr << "Finished.";

	return 0;
}