#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
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
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
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


const int MAXN = 1100;


int n, x, a[MAXN];


bool read() {
    if (!(cin >> n >> x))
        return false;
    --x;
    forn(i, n) {
        cin >> a[i];
        --a[i];
    }
    return true;
}


bool has_after[MAXN];
bool can[MAXN];


void solve() {
    memset(has_after, 0, sizeof has_after);
    forn(i, n)
        if (a[i] >= 0)
            has_after[a[i]] = true;

    vector<int> v;
    int own_delta = -1;
    forn(i, n)
        if (!has_after[i]) {
            int cur = i,
                cnt = 0;
            bool own = false;
            while (cur != -1) {
                if (cur == x) {
                    own = true;
                    cnt = 0;
                }
                cur = a[cur];
                ++cnt;
            }
            if (own)
                own_delta = cnt;
            else
                v.push_back(cnt);
        }
    if (own_delta == -1)
        throw;

    memset(can, 0, sizeof can);
    can[0] = true;
    forn(i, v.size()) {
        int cnt = v[i];
        ford(i, MAXN - cnt)
            if (can[i])
                can[i + cnt] = true;
    }

    forn(i, MAXN)
        if (can[i])
            cout << i + own_delta << '\n';
}


int main(int argc, char* argv[]) {
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