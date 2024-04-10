#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define fi first
#define se second
#define l1 l11
#define l2 l22
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
using namespace std;
const ll mod = 1000000007;
int n, a[10000];
vector<vector<pii> > qq;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    cin >> n;
    qq.resize(n);
    forn (i, n) {
        qq[i].resize(n);
        forn (i, n + 1) a[i] = 0;
        bool ok = false;
        forn (j, n) {
            cin >> qq[i][j].fi;
            if (qq[i][j].fi == 0) qq[i][j].fi = n;
            a[qq[i][j].fi]++;
            if (a[qq[i][j].fi] > 1) ok = true;
        }
        if (!ok) {
            forn (j, n)
                cout << qq[i][j].fi << " ";
            re 0;
        }
    }
    //sort(qq.begin(), qq.end());
    return 0;
}