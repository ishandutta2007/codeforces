#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
//#include "horses.h"
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll ma = 131072 * 4, mod = 1000000007;
const ld eps = 1e-10;
int n, m, k, ans[100001];
vector<int> q, p, b;

int main() {
    iostream::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    q.resize(n);
    forn (i, n) {
        cin >> q[i];
        ans[i + 1] = max(q[i], ans[i]);
    }
    k = 1;
    m = 1000000000;
    for (int i = n - 1; i > 0; i--) {
        m = min(m, q[i]);
        if (m >= ans[i]) {
            k++;
            m = 1000000000;
        }
    }
    cout << k;
    re 0;
}