#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <deque>
//#include "grader.h"
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll mod = 1000000007, cc = 8;
const ld eps = 1e-10;
int n, m, a[400][400], use[400], a1, b1, k;
queue<int> pp;
int main() {
    iostream::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    forn (i, n)
        a[i][i] = -1;
    forn (i, m) {
        cin >> a1 >> b1;
        a1--; b1--;
        a[a1][b1] = a[b1][a1] = 1;
    }
    if (a[0][n - 1] == 0) k = 1;
    else k = 0;
    pp.push(0);
    use[0] = 1;
    while (!pp.empty()) {
        int nu = pp.front();
        pp.pop();
        forn (j, n)
            if (use[j] == 0 && a[nu][j] == k) {
                use[j] = use[nu] + 1;
                pp.push(j);
            }
    }
    if (use[n - 1] == 0) cout << -1;
    else cout << use[n - 1] - 1;
    re 0;
}