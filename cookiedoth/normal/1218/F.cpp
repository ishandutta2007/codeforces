/*














 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
 
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { x = (x < y ? y: x);}
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left224
#define right right224
#define rank rank224
#define y1 y1224
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
const string FILENAME = "input";
const int MAXN = 15222;

const int mx = 1e5 + 228;
int n, k, x[mx], a, cnt[mx];
ll c[mx], ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cin >> a;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n; ++i) {
        int diff = x[i] - k;
        if (diff > 0) {
            cnt[i] = (diff - 1) / a + 1;
        }
    }
    int used = 0;
    multiset<ll> costs;
    for (int i = 0; i < n; ++i) {
        costs.insert(c[i]);
        while (used < cnt[i]) {
            if (costs.empty()) {
                cout << -1 << endl;
                exit(0);
            }
            ans += (*costs.begin());
            costs.erase(costs.begin());
            used++;
        }
    }
    cout << ans << endl;
    return 0; 
}