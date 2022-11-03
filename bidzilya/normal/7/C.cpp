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

ll a, b, c;

ll phi(ll x) {
    ll res = x;
    for (int i = 2; i <= sqrt(x); ++i) 
        if (x % i == 0) {
            while (x % i == 0) 
                x /= i;
            res -= res / i;
        }
    if (x > 1)
        res -= res / x;
    return res;
}

ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) 
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

ll bin_pow(ll base, ll pw, ll modulo) {
    if (pw == 0)
        return 1 % modulo;
    if (pw % 2 == 0)
        return bin_pow((base * base) % modulo, pw / 2, modulo);
    return (base * bin_pow(base, pw - 1, modulo)) % modulo;
}

void norm(ll& a, ll& b, ll& c) {
    ll g = gcd(abs(a), abs(b));
    g = gcd(g, abs(c));
    a /= g;
    b /= g;
    c /= g;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> a >> b >> c;
    if (b == 0) {
        if (c % a == 0) {
            cout << -c / a << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    if (a == 0) {
        if (c % b == 0) {
            cout << 0 << " " << -c / b << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    norm(a, b, c);
    if (b < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }
    if (gcd(abs(a), abs(b)) > 1) {
        cout << -1 << endl;
        return 0;
    }
    ll ta, tc;
    ta = a; tc = -c;
    if (ta < 0) {
        ta *= -1;
        tc *= -1;
    }
    ll tx = (tc * bin_pow(ta, phi(b) - 1, b)) % b;
    ll ty = ((-a) * tx - c) / b;
    cout << tx << " " << ty << endl;
    return 0;
}