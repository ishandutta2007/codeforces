#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
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
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define mp  make_pair
#define fs  first
#define sc  second
#define pb  push_back


const int MAXN = 110000;

int n, a[MAXN];
int64 k;

bool read() {
	if (! (cin >> n >> k))  return false;
	forn(i,n)
		scanf ("%d", &a[i]);
	return true;
}


pair<int,int> b[MAXN];

void solve() {
	if (k == 0) {
		forn(i,n)
			printf ("%d ", i+1);
		puts("");
		return;
	}

	forn(i,n)
		b[i] = mp (a[i], i);
	sort (b, b+n);

	set<int> q;
	forn(i,n)
		q.insert (i);

	int prev = 0;
	forn(i,n) {
		int cur = b[i].fs;
		int64 cur_ans = (cur - prev) * 1ll * (int) q.size();
		if (k <= cur_ans) {
			int cnt = (int) q.size();
			int who = (k - 1) % cnt;
			
			vector<int> pref, suf;
			forn(i,who+1) {
				pref.pb (*q.begin());
				q.erase (q.begin());
			}
			suf.assign (all (q));

			forn(j,pref.size()) {
				int v = pref[j];
				int when = int ((k-1) / cnt);
				if (prev + when + 1 < a[v])
					suf.pb (v);
				if (prev + when + 1 > a[v])
					throw;
			}

			forn(i,suf.size())
				printf ("%d ", suf[i]+1);
			puts("");
			return;
		}
		k -= cur_ans;
		prev = cur;

		while (i < n && b[i].fs == cur) {
			int who = b[i].sc;
			q.erase (who);
			++i;
		}
		--i;
	}
	puts ("-1");
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}