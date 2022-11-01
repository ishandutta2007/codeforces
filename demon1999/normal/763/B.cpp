//#include "grader.h"
#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)


typedef int ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
//const int ma = 128 * 1024, mal = 8;
const int MAXN = 2 * 100 * 1000;
const ll mod = ll(1e9) + 7;

int n, cl[MAXN], cnt[MAXN], can[4][MAXN];
vector<pair<pii, pii> > pnt;
vector<int> num, e[MAXN];

map<int, vector<pair<pair<int, int>, int> > > crnd, crnd2;

bool cmp(int i, int j) {
	re pnt[i] < pnt[j];
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	pnt.resize(n);
	cout << "YES\n";
	forn (i, n) {
		forn (j, 4)
			can[j][i] = 1;
		scanf("%d%d%d%d", &pnt[i].fi.fi, &pnt[i].fi.se, &pnt[i].se.fi, &pnt[i].se.se);
		cout << ((pnt[i].fi.fi % 2 + 2)%2) * 2 + (pnt[i].fi.se % 2 + 2) % 2 + 1 << "\n";
	}
}