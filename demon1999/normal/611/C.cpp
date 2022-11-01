#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
using namespace std;

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, m, l, r, k, a[501][501], b[501][501];
string s[500];
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("round.in", "r",  stdin);
    cin >> n >> m;
    forn (i, n) {
        cin >> s[i];
        forn (j, m) {
            int k = 0;
            if (s[i][j] == '#') continue;
            if (i - 1 >= 0 && s[i - 1][j] == '.') a[i + 1][j + 1] = 1;
            if (j > 0 && s[i][j - 1] == '.') b[i + 1][j + 1] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    int x, y, xx, yy;
    cin >> k;
    forn (i, k) {
        cin >> x >> y >> xx >> yy;
        cout << a[xx][yy] - a[x][yy] - a[xx][y - 1] + a[x][y - 1] +
                b[xx][yy] - b[x - 1][yy] - b[xx][y] + b[x - 1][y] << "\n";
    }
    return 0;
}