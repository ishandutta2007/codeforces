#include <cassert>
#include <iomanip>
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

double fac[55];
int a[55];
double dp[55][55][55];
int n, m;

void setup() {
    fac[0] = 1;
    for(int i=1; i<55; ++i) {
        fac[i] = fac[i-1]*i;
    }
}

inline double choose(int n, int m) {
    return fac[n]/fac[m]/fac[n-m];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<=n; ++i) {
        for(int k=0; k<55; ++k) {
            dp[i][1][k] = max((i+a[1]-1)/a[1], k);
        }
    }
    for(int j=2; j<=m; ++j) {
        for(int i=0; i<=n; ++i) {
            for(int k=0; k<55; ++k) {
                dp[i][j][k] = 0;
                for(int x=0; x<=i; ++x) {
                    dp[i][j][k] += choose(i, x)*pow(1./j, x)*pow(1-1./j, i-x)*dp[i-x][j-1][max((x+a[j]-1)/a[j], k)];
                }
            }
        }
    }
    cout << fixed << setprecision(20) << dp[n][m][0] << endl;
    return 0;
}