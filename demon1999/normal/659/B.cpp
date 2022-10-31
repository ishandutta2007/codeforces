#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;

using namespace std;

void my_assert(bool q) {
    if (!q) while(true);
}

int n, m, k, b;
vector<pair<int, string> > a[200000];
string s;
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n >> m;
    forn (i, n) {
        cin >> s >> k >> b;
        k--;
        a[k].push_back(mp(b, s));
    }
    forn (i, m) {
        sort(a[i].begin(), a[i].end());
        reverse(a[i].begin(), a[i].end());
        if (sz(a[i]) <= 2 || a[i][1].fi != a[i][2].fi) {
            cout << a[i][0].se << " " << a[i][1].se << "\n";
        }
        else cout <<"?\n";
    }
    return 0;
}