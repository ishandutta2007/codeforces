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

const int modulo = 1e9 + 9;

int n, m, k, ans;

int pw(int base, int p) {
    if (p == 0)
        return 1 % modulo;
    if (p % 2 == 0)
        return pw((1LL * base * base) % modulo, p / 2);
    if (p % 2 == 1)
        return (1LL * base * pw(base, p - 1)) % modulo;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n >> m >> k;
    n -= m;
    if (1LL * n * (k - 1) >= m) {
        cout << m % modulo << endl;
    } else {
        m -= 1LL * n * (k - 1);
        ans = (pw(2, m / k + 1) - 2 + modulo) % modulo;
        ans = (1LL * ans * k) % modulo;
        ans = (1LL * n * (k - 1) + ans) % modulo;
        ans = (ans + m % k) % modulo;
        cout << ans << endl;
    }
    return 0;
}