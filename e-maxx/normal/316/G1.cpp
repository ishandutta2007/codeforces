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


const int MAXR = 10;
const int MAXN = 2010;
const int PR = 3;
const int B[PR] = { 29, 53, 97 };
const int P[PR] = { 1073676287, 1190494667, 1190494699 };


string s, p[MAXR];
int n, minc[MAXR], maxc[MAXR];


bool read() {
    if (!(cin >> s >> n))
        return false;
    forn(i, n)
        cin >> p[i] >> minc[i] >> maxc[i];
    return true;
}


struct strhash {
    int h[PR];

    strhash() {
        memset(h, 0, sizeof h);
    }

    void add_char(char c) {
        forn(i, PR)
            h[i] = (c - 'a' + h[i] * 1ll * B[i]) % P[i];
    }
    
    bool operator<(const strhash& other) const {
        return memcmp(h, other.h, sizeof h) < 0;
    }

    bool operator==(const strhash& other) const {
        return memcmp(h, other.h, sizeof h) == 0;
    }
};

vector<strhash> substr[MAXR][MAXN];
vector<strhash> ans[MAXN];


void solve() {
    forn(i, n) {
        forn(j, MAXN)
            substr[i][j].clear();
        forn(l, p[i].length()) {
            strhash h;
            fore(r, l, p[i].length()) {
                h.add_char(p[i][r]);
                substr[i][r - l + 1].push_back(h);
            }
        }
        forn(j, MAXN)
            sort(all(substr[i][j]));
    }

    forn(i, MAXN)
        ans[i].clear();
    forn(l, s.length()) {
        strhash h;
        fore(r, l, s.length()) {
            h.add_char(s[r]);
            bool ok = true;
            forn(i, n) {
                vector<strhash>::iterator begin = lower_bound(all(substr[i][r - l + 1]), h);
                vector<strhash>::iterator end = upper_bound(all(substr[i][r - l + 1]), h);
                int c = int(end - begin);
                if (!(minc[i] <= c && c <= maxc[i])) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans[r - l + 1].push_back(h);
        }
    }
    int ansc = 0;
    forn(i, MAXN) {
        sort(all(ans[i]));
        ansc += int(unique(all(ans[i])) - ans[i].begin());
    }
    cout << ansc << endl;
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