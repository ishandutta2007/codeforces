#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int max_n = 100;

int n, x;
int c[max_n];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) { 
        cin >> c[i];
        c[i] = c[i] * (n - i);
    }
    sort(c, c + n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (x >= c[i]) {
            ++ans;
            x -= c[i];
        }
    cout << ans << endl;
    return 0;
}