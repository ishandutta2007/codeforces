#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <list>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "m"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgashqt
#define free afdshjioeyqtw
#define next qpowityqwopqw

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll INF64 = 1e18;
const ld EPS = 1e-16;
const int N = 200100;
const int M = 1001;

ll n, m, nn;
vector < int > g[N];
ll sum = 0;
bool mark[N];

void dfs(int v) {
    mark[v] = 1;
    sum += sz(g[v]);
    nn++;
    for (int u : g[v])
        if (!mark[u])
            dfs(u);
}

int main() {
    cin >> n >> m;
    forn(i, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int v = 1; v <= n; v++)
        if (!mark[v]) {
            sum = 0; nn = 0;
            dfs(v);
            sum /= 2;
            if (sum != nn * (nn - 1) / 2) {
                cout << "NO" << endl;
                exit(0);
            }
        }
    cout << "YES" << endl;
    return 0;
}



/*



*/