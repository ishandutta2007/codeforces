#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1100;
const int INF = 2000000000;

int x[MAXN];


int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> x[i];
    sort(x, x+n);
    int m;
    cin >> m;
    int ans = 0;
    if (m > n) {
        for (int i = 0; i < n; ++i) ans += x[i];
        ans -= k * (m-n);
    } else {
        for (int i = 0; i < m; ++i) ans += x[i];
    }
    cout << ans << endl;
    
    
    return 0;
}