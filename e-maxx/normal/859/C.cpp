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


const int MAXN = 51;


int n, a[MAXN];


bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n)
		cin >> a[i];
	return true;
}


int d[MAXN][2], sum[MAXN];

int get_d(int cur, int who) {
	if (cur == n)
		return 0;

	int &my = d[cur][who];
	if (my != -1)
		return my;
	my = -INF;

	my = max(my, a[cur] + sum[cur+1] - get_d(cur+1, 1-who));
	my = max(my, get_d(cur+1, who));

	return my;
}

void solve() {
	sum[n] = 0;
	ford(i, n)
		sum[i] = sum[i+1] + a[i];

	memset(d, -1, sizeof d);
	int ans = get_d(0, 0);
	cout << sum[0] - ans << ' ' << ans << endl;
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