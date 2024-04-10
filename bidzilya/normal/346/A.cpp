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

ll n, k = 0, mx = 0;

ll gcd(ll a, ll b) {
    while (a > 0 && b > 0)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return (a + b);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        k = gcd(k, a);
        mx = max(mx, a);
    }
    k = mx / k - n;
    if (k % 2 == 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    return 0;
}