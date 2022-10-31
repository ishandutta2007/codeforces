#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long LL;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define MX 100005

#define pb push_back

#define X first
#define Y second
vi con[MX];
int n, m;
pii g[MX];

int main() {

    scanf("%d%d", &n, &m);
    int res = 0;
    int sz;
    int i, a, j;
    for (i = 0; i < MX; i++) g[i] = pii(-1, -1);
    for (i = 0; i < m; i++) {
        scanf("%d", &sz);
        while (sz--) {
            scanf("%d", &a);
            g[a] = pii(i, con[i].size());
            con[i].push_back(a);
        }
    }
    pii tmp = g[1];
    int id = tmp.X, pos = tmp.Y;
    for (i = 1; i < con[id].size(); i++) if (con[id][i] != con[id][i - 1] + 1) break;
    int _i = con[id][i - 1];
    for (; i < con[id].size(); i++) g[con[id][i]] = pii(-1, -1), res++;
    for (i = _i + 1; i <= n;) {
        if (g[i].X == -1) {
            res++, i++;
        } else {
            int id = g[i].X, pos = g[i].Y;
            res++;
            for (j = pos + 1; j < con[id].size(); j++) g[con[id][j]] = pii(-1, -1), res++;
            i++;
        }
    }
    cout << res << endl;
    return 0;
}