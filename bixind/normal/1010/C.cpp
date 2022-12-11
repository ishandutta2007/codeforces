#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b > a)
        swap(a, b);
    while (b > 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

void solve(istream &cin = cin, ostream &cout = cout) {
    int n, k;
    cin >> n >> k;
    int g = k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        g = gcd(g, a);
    }
    cout << k / g << endl;
    for (int i = 0; i < k / g; ++i) {
        cout << i * g << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    solve();
    return 0;
}