#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
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
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


int64 n;


bool read() {
	return !!(cin >> n);
}


int64 my_sqrt(int64 x) {
    int64 l = 0, r = min(x, 2ll * INF + INF / 10);
    while (l < r) {
        int64 m = (l + r + 1) / 2;
        if (m * m <= x)
            l = m;
        else
            r = m - 1;
    }
    return l;
}


typedef vector<int64> lnum;

void norm(lnum &n) {
    int64 c = 0;
    forn(i, n.size()) {
        n[i] += c;
        c = n[i] / INF64;
        n[i] %= INF64;
    }
    if (c)
        n.push_back(c);
}

lnum make_lnum(int64 n, int p) {
    lnum res(1, n);
    norm(res);
    while (p) {
        forn(i, res.size())
            res[i] *= 2;
        norm(res);
        --p;
    }
    return res;
}

bool cmp(const lnum &a, const lnum &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    ford(i, a.size())
        if (a[i] != b[i])
            return a[i] < b[i];
    return false;
}

void out(const lnum &n) {
    ford(i, n.size()) {
        if (i == (int)n.size()-1) {
            cout.width(0);
            cout << n[i];
        }
        else {
            cout.width(18);
            cout.fill('0');
        }
    }
    puts("");
}

int f(int p, int64 m) {
    int64 pw = 1ll << p;
    double pwd = (double)pw;

    int64 x = 2 * m - 1;
    double xd = (double)x;

    double vald = xd * ((xd - 1) / 2 + pwd - 1);
    if (vald > 2E18)
        return +1;
    int64 val = x * ((x - 1) / 2 + pw - 1);
    return val==n ? 0 : (val<n ? -1 : +1);
}


void solve() {
    vector<int64> ans;
    forn(p, 62) {
        int64 l = 1,  r = INF + 10;
        while (l < r) {
            int64 m = (l + r + 1) / 2;
            if (f(p, m) <= 0)
                l = m;
            else
                r = m - 1;
        }
        if (f(p, l) == 0) {
            int64 x = 2 * l - 1;
            ans.push_back(x << p);
        }
    }

    sort(all(ans));
    if (ans.empty())
        puts("-1");
    else
        forn(i, ans.size())
            cout << ans[i] << endl;
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}