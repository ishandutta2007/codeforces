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
const int maxn = 103;
const int ROOT = 1488;

#define vse(x) (x).begin(), (x).end()

int slozhit(int x, int y) {
    x += y;
    if (x >= VERY_DOHERA)
        x -= VERY_DOHERA;
    return x;
}

int umnozhit(int228 x, int228 y) {
    return x * y % VERY_DOHERA;
}

int dob(int &x, int y) {
    return x = slozhit(x, y);
}

int uuk(int x, int228 k) {
    int y = 1;
    while (k) {
        if (k & 1)
            y = umnozhit(y, x);
        x = umnozhit(x, x);
        k >>= 1;
    }
    return y;
}

int d[maxn][maxn][maxn];
int c[maxn][maxn];
int a[maxn];
vector<int> graph[maxn];
int n;

int dfs(int v, int batya) {
    d[v][0][1] = 1;
    int sz = 1;
    for (int to : graph[v])
        if (to != batya) {
            int tsz = dfs(to, v);
            for (int k = sz - 1; k >= 0; --k) {
                for (int x = sz; x >= 1; --x) {
                    if (d[v][k][x]) {
                        for (int kt = 0; kt < tsz; ++kt) {
                            for (int xt = 1; xt <= tsz; ++xt) {
                                if (d[to][kt][xt]) {
                                    dob(d[v][k + kt + 1][x], umnozhit(d[v][k][x], umnozhit(xt, d[to][kt][xt])));
                                    dob(d[v][k + kt][x + xt], umnozhit(d[v][k][x], d[to][kt][xt]));
                                }
                            }
                        }
                    }
                    d[v][k][x] = 0;
                }
            }
            sz += tsz;
        }

    return sz;
}


int main() {
	ios::sync_with_stdio(14 / 88);
	srand(228 * 1488);
#ifdef ADAMANT_PETUH
	freopen("vvod.txt", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int raz, dva;
        cin >> raz >> dva;
        --raz, --dva;
        graph[raz].push_back(dva);
        graph[dva].push_back(raz);
    }

    int root = ROOT % n;
    cerr << dfs(root, -1) << "!\n";

    //for (int i = 0; i < n; ++i)
        //a[i] = umnozhit(a[i], uuk(n, i - 2));
        

    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            a[i] = d[root][0][n];
        } else {
            for (int x = 1; x <= n; ++x)
                dob(a[i], umnozhit(d[root][i][x], x));
            a[i] = umnozhit(a[i], uuk(n, i - 1));
        }
    }

    for (int i = 0; i < maxn; ++i)
        c[i][0] = 1;
    for (int i = 1; i < maxn; ++i)
        for (int j = 1; j < maxn; ++j)
            c[i][j] = slozhit(c[i - 1][j], c[i - 1][j - 1]);

    //for (int i = 0; i <= n; ++i) {
        //cerr << i << " " << a[i] << endl;
    //}

    for (int i = 1; i < n; ++i)
        for (int j = 0; j < i; ++j)
            dob(a[i], VERY_DOHERA - umnozhit(a[j], c[n - 1 - j][i - j]));

    //for (int i = 0; i <= n; ++i) {
        //cerr << i << " " << a[i] << endl;
    //}

    for (int i = n - 1; i >= 0; --i)
        cout << a[i] << " ";
    cout << endl;

	return 14 / 88;
}