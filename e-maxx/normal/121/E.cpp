#pragma comment (linker, "/STACK:200000000")
#define _CRT_SECURE_NO_DEPRECATE
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


const int MAXN = 110000;
const int SQ = 350;
const int NUM = 10001;

int n, m, a[MAXN];
vector<int> good;
bool is_good[NUM];


struct bl {
        int idx, left, right, add;
        int arr[SQ], sz;
        int cnt[NUM];

        bl() { }

        bl (int idx) : idx(idx) {
                left = SQ * idx;
                right = left + SQ - 1;

                sz = 0;
                add = 0;
                memset (cnt, 0, sizeof cnt);
        }

        void flush() {
                if (add) {
                        forn(i,sz) {
                                --cnt[arr[i]];
                                arr[i] += add;
                                ++cnt[arr[i]];
                        }
                        add = 0;
                }
        }

        void add_tupo (int l, int r, int add) {
                flush();
                l -= left,  r -= left;
                for (int i=l; i<=r; ++i) {
                        --cnt[arr[i]];
                        arr[i] += add;
                        ++cnt[arr[i]];
                }
        }

        int calc_tupo (int l, int r) {
                flush();
                l -= left,  r -= left;
                int ans = 0;
                for (int i=l; i<=r; ++i)
                        if (is_good[arr[i]])
                                ++ans;
                return ans;
        }

        int calc() {
                int ans = 0;
                forn(i,good.size()) {
                        int old = good[i] - add;
                        if (old >= 0)
                                ans += cnt[old];
                }
                return ans;
        }
};

bl b[SQ];


bool read() {
        if (! (cin >> n >> m))
                return false;
        forn(i,n)
                scanf ("%d", &a[i]);
        return true;
}


void do_add (int l, int r, int add) {
        int li = l / SQ,
                ri = r / SQ;
        if (li == ri)
                b[li].add_tupo (l, r, add);
        else {
                b[li].add_tupo (l, b[li].right, add);
                b[ri].add_tupo (b[ri].left, r, add);
                for (int i=li+1; i<ri; ++i)
                        b[i].add += add;
        }
}

int calc (int l, int r) {
        int li = l / SQ,
                ri = r / SQ;
        int ans = 0;
        if (li == ri)
                ans += b[li].calc_tupo (l, r);
        else {
                ans += b[li].calc_tupo (l, b[li].right);
                ans += b[ri].calc_tupo (b[ri].left, r);
                for (int i=li+1; i<ri; ++i)
                        ans += b[i].calc();
        }
        return ans;
}


void solve() {
        forn(i,SQ)
                b[i] = bl (i);
        forn(i,n) {
                int j = i / SQ;
                b[j].arr[ b[j].sz++ ] = a[i];
                ++b[j].cnt[ a[i] ];
        }

        forn(i,m) {
                char buf[20];
                int l, r;
                scanf (" %s %d %d", buf, &l, &r);
                --l, --r;

                if (buf[0] == 'a') {
                        int add;
                        scanf ("%d", &add);
                        do_add (l, r, add);
                }
                else
                        printf ("%d\n", calc (l, r));
        }
}


void rec (int num, int pos, int len) {
        if (pos == len)
                good.pb (num);
        else {
                rec (num * 10 + 4, pos + 1, len);
                rec (num * 10 + 7, pos + 1, len);
        }
}


int main() {
        for (int i=1; i<=4; ++i)
                rec (0, 0, i);
        forn(i,good.size())
                is_good[ good[i] ] = true;

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