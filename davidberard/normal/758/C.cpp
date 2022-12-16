#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

ll n, m, k, x, y;
ll f, g, h;

const int NMAX = 110;

ll amt[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k >> x >> y;
    if(n == 1) {
        h = f = g = k/m;
        if(k%m) {
            f++;
        }
        if(k%m >= y) {
            h++;
        }
        cout << f << " " << g << " " << h << endl;
        return 0;
    }
    ll base = (n-1)*m*2;
    g = k/base;
    for(int i=0;i<m;++i) {
        amt[0][i] = g;
        amt[n-1][i] = g;
        for(int j=1;j<n-1;++j) {
            amt[j][i] = g*2;
        }
    }
    k -= base*g;
    f = g*2;
    for(int i=0; i<n && k; ++i) {
        for(int j=0; j<m && k; ++j) {
            f = max(f, ++amt[i][j]);
            --k;
        }
    }
    for(int i=n-2; i>0 && k; --i) {
        for(int j=0; j<m && k; ++j) {
            f = max(f, ++amt[i][j]);
            --k;
        }
    }
    g = 1e18;
    f = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            g = min(g, amt[i][j]);
            f = max(f, amt[i][j]);
        }
    }
    cout << f << " " << g << " " << amt[x-1][y-1] << endl;
    return 0;
}