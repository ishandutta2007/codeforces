#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#include <string.h>
#define int228 long long
#define mp make_pair
#define pb push_back
using namespace std;

const int228 VERY_DOHERA = 1000000007;

#define vse(x) (x).begin(), (x).end()

const int maxn = 107;
const int maxa = 27;

int n, m;
int a[maxn][maxn];
int d[maxn][maxn][maxa];

bool dfs(int x, int y, int c) {
    if (d[x][y][c] != -1)
        return d[x][y][c] == 1;
    bool res = false;
    for (int to = 0; to < n; ++to)
        if (a[x][to] >= c)
            res |= !dfs(y, to, a[x][to]);

    return (d[x][y][c] = res ? 1 : 0);
}

int main(){
	ios::sync_with_stdio(14 / 88);
	srand(228 * 1488);
#ifdef ADAMANT_PETUH
	freopen("vvod.txt", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            a[i][j] = -1;
            for (int c = 0; c < maxa; ++c)
                d[i][j][c] = -1;
        }

    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v;
        cin >> c;
        --u, --v;
        a[u][v] = c - 'a';
    }

    for (int x = 0; x < n; ++x, cout << "\n") {
        for (int y = 0; y < n; ++y) {
            cout << (dfs(x, y, 0) ? 'A' : 'B');
        }
    }
		
	return 14 / 88;
}