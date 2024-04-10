#pragma GCC optimize("Ofast")

#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define snd second
#define ins insert
//#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
const int MOD1 = 998244353;
const int MOD = 1'000'000'007;
const int INF = 1e9;
const int MaXN = 150;
const int N = 5e5 + 1000;
const int LOG = 25;
const int FACT = 120;
double ecr = 1e-8;
int order[N];
int a[N], b[N];
bool comp(int i, int j) {
    int p = max(a[i], b[i]);
    int q = max(a[j], b[j]);
    if (p == q) return a[i] < a[j];
    return p < q;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        order[i] = i;
    }
    int cnt = 0;
    sort(order, order + n, comp);
    for (int i = 0; i < n; i++) {
        if (m < a[order[i]] + 1) {
            cnt++;
            m = max(m, b[order[i]]);
        }
    }
    cout << cnt << "\n";
}