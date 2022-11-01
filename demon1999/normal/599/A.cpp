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
ll n, m, k;

int main() {
    iostream::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    cout << min(min(n + m + k, 2 * m + 2 * n), min(2 * (n + k), 2 * (m + k)));
    re 0;
}