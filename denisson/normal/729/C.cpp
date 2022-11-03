#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/
//

int n, k, s, t;
pair<int, int> a[2 * 100007];
int g[2 * 100007];
int q[2 * 100007];
ll pref[2 * 100007];

ll get(int l, int r) {
	if (l > r)
		return 0;
	if (l == 0)
		return pref[r];
	return pref[r] - pref[l - 1];
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("input.txt", "w", stdout);
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	scanf("%d %d %d %d", &n, &k, &s, &t);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].YY, &a[i].XX);
	}
	sort(a, a + n);
	for (int i = 0; i < k; i++)
		scanf("%d", &g[i]);
	sort(g, g + k);

	int ma = 0;
	int last = 0;
	for (int i = 0; i < k; i++) {
		q[i] = g[i] - last;
		last = g[i];
	}
	q[k] = s - last;
	k++;
	for (int i = 0; i < k; i++) {
		ma = max(ma, q[i]);
	}
	sort(q, q + k);
	pref[0] = q[0];
	for (int i = 1; i < k; i++) {
		pref[i] = pref[i - 1] + (ll)q[i];
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		if (a[i].XX < ma)
			continue;
		int l = -1, r = k;
		while (l + 1 < r) {
			int m = (l + r) / 2;
			if ((ll)3 * (ll)q[m] - (ll)a[i].XX >= (ll)q[m])
				r = m;
			else
				l = m;
		}
		ll now = 0;
		now += get(0, l);
		int ost = k - l - 1;
		now += (ll)3 * get(r, k - 1) - (ll)ost * (ll)a[i].XX;
		if ((ll)now <= (ll)t)
			ans = min(ans, a[i].YY);
		//cout << now << endl;
	}
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}