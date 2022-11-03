#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

ll gcd(ll x, ll y) {
    while (x > 0 && y > 0) 
        if (x >= y)
            x %= y;
        else
            y %= x;
    return (x + y);
}

void norm(ll& x, ll& y) {
    ll g = gcd(x, y);
    x /= g;
    y /= g;
}

int main() {
    ios_base::sync_with_stdio(false); 
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    norm(x, y);
    ll l = 1, r = min(a, b), a1 = 0, b1 = 0;
    while (l <= r) {
        ll m = (l + r) >> 1;
        if (m * x <= a && m * y <= b) {
            a1 = m * x;
            b1 = m * y;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    cout << a1 << " " << b1 << endl;
    return 0;
}