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

vector<strhash> ans[MAXN];

struct state {
	int len, link, cnt, dcnt;
	map<char,int> next;
    vector<int> ilink;
};

state st[MAXR][MAXN*2];
int sz, last;

void sa_init(int idx) {
	sz = last = 0;
	st[idx][0].len = 0;
	st[idx][0].link = -1;
	++sz;
	for (int i=0; i<MAXN*2; ++i) {
        st[idx][i].cnt = 0;
        st[idx][i].dcnt = -1;
		st[idx][i].next.clear();
        st[idx][i].ilink.clear();
    }
}

int get_cnt(int idx, int v) {
    int & my = st[idx][v].dcnt;
    if (my != -1)
        return my;
    my = st[idx][v].cnt;
    forn(i, st[idx][v].ilink.size())
        my += get_cnt(idx, st[idx][v].ilink[i]);
    return my;
}

void sa_extend (int idx, char c) {
    state* st = ::st[idx];

	int cur = sz++;
	st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
	int p;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = sz++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}


void solve() {
    forn(i, n) {
        sa_init(i);
        forn(j, p[i].length())
            sa_extend(i, p[i][j]);
        forn(j, sz) {
            int l = st[i][j].link;
            if (l != -1)
                st[i][l].ilink.push_back(j);
        }
    }

    forn(i, MAXN)
        ans[i].clear();
    forn(l, s.length()) {
        strhash h;
        int v[MAXR] = { 0 };
        fore(r, l, s.length()) {
            h.add_char(s[r]);
            bool ok = true;
            forn(i, n) {
                if (v[i] != -1)
                    if (st[i][v[i]].next.count(s[r]))
                        v[i] = st[i][v[i]].next[s[r]];
                    else
                        v[i] = -1;
                int c = v[i]==-1 ? 0 : get_cnt(i, v[i]);
                if (c < minc[i])
                    goto end;
                if (!(minc[i] <= c && c <= maxc[i]))
                    ok = false;
            }
            if (ok)
                ans[r - l + 1].push_back(h);
        }
        end:;
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