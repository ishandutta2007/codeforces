#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

long long a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (b == 1) {
        cout << 0 << endl;
        return 0;
    }
    long long ans = 0, sum = 0, x = b;
    for (int k = 1; k < b; ++k) {
        sum = (sum + k) % mod;
    }
    for (int k = 1; k <= a; ++k) {
        ans = (ans + sum * (x + 1)) % mod;
        x = (x + b) % mod;
    }
    cout << ans << endl;
    return 0;
}