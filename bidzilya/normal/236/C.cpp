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

ll n, ans;

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
    if (n == 1) {
        cout << 1 << endl;
    } else {
        ans = 0;
        for (ll n1 = n; n1 >= max(1LL, n - 100); --n1)
            for (ll n2 = n; n2 >= max(1LL, n - 100); --n2)
                for (ll n3 = n; n3 >= max(1LL, n - 100); --n3)
                    ans = max(ans, n1 * n2 * n3 / gcd(n1, n2) / gcd(n1, n3) / gcd(n2, n3));
        cout << ans << endl;
    }
    return 0;
}