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


const int MAXN = 310 * 1000;


int n, who[MAXN], where[MAXN];


bool read() {
    if (!(cin >> n))
        return false;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        --x;
        who[i] = x;
        where[x] = i;
    }
	return true;
}


int t[MAXN];

void fenw_upd(int i, int add) {
    for (; i < n; i |= i + 1)
        t[i] += add;
}

int fenw_sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}

void upd(int pos, int tp) {
    if (pos < 0 || pos >= n)
        return;
    if (pos + 1 < n && where[pos] > where[pos + 1])
        fenw_upd(pos, tp);
}

void solve() {
    memset(t, 0, sizeof t);
    forn(i, n)
        upd(i, +1);

    int m;
    cin >> m;
    forn(i, m) {
        int tp, l, r;
        scanf("%d%d%d", &tp, &l, &r);
        --l;
        --r;

        if (tp == 1) {
            int ans = fenw_sum(r - 1) - fenw_sum(l - 1) + 1;
            printf("%d\n", ans);
        }
        else {
            int pl = l,  pr = r;
            l = who[pl];
            r = who[pr];

            int pos[6] = { l-1, l, l+1, r-1, r, r+1 };
            sort(pos, pos+6);
            int poses = int(unique(pos, pos+6) - pos);

            forn(i, poses)
                upd(pos[i], -1);
            
            swap(who[pl], who[pr]);
            swap(where[l], where[r]);
            
            forn(i, poses)
                upd(pos[i], +1);
        }
    }
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