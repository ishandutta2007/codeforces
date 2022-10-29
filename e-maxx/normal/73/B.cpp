#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int MAXN = 100000;

int n, m;
pair<string,int> a[MAXN];
string me;
int my;
int b[MAXN];


bool read() {
        if (! (cin >> n))  return false;
        for (int i=0; i<n; ++i) {
                char buf[100];
                scanf (" %s %d", buf, &a[i].second);
                a[i].first = buf;
        }
        cin >> m;
        for (int i=0; i<m; ++i)
                scanf ("%d", &b[i]);
        cin >> me;
        return true;
}


inline bool cmp (const pair<string,int> & a, const pair<string,int> & b) {
        return make_pair (-a.second, a.first) < make_pair (-b.second, b.first);
}

inline bool better (const string & sa, int ca, const string & sb, int cb) {
    return ca > cb || ca == cb && sa < sb;
}

inline bool can_less (int cnt) {
        int us = a[my].second + b[m-1];
        for (int i=n-1, c=0; c<cnt; --i) {
                if (i == my)  continue;
                int give = b[cnt-1-c];
                if (better (a[i].first, a[i].second+give, me, us))
                        return false;
                ++c;
        }
        return true;
}

inline bool can_more (int cnt) {
        int us = a[my].second + b[0];
        for (int i=0, c=0; c<cnt; ++i) {
                if (i == my)  continue;
                int give = b[m-cnt+c];
                if (better (me, us, a[i].first, a[i].second+give))
                        return false;
                ++c;
        }
        return true;
}

void solve() {
        sort (a, a+n, cmp);
        for (int i=0; i<n; ++i)
                if (a[i].first == me)
                        my = i;
        
        while (m < n)
                b[m++] = 0;
        sort (b, b+m);

        int lt = 0,  rt = n-1;
        while (lt < rt) {
                int mid = (lt + rt + 1) / 2;
                if (can_less (mid))
                        lt = mid;
                else
                        rt = mid-1;
        }
        int ans_max = n - lt;

        lt = 0,  rt = n-1;
        while (lt < rt) {
                int mid = (lt + rt + 1) / 2;
                if (can_more (mid))
                        lt = mid;
                else
                        rt = mid-1;
        }
        int ans_min = lt + 1;

        cout << ans_max << ' ' << ans_min << endl;
}


int main() {
#ifndef ONLINE_JUDGE
        freopen ("input.txt", "rt", stdin);
        freopen ("output.txt", "wt", stdout);
#endif

        while (read())
                solve();

}