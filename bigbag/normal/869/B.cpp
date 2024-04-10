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

const int max_n = 1, inf = 1011111111;

long long a, b, ans = 1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    if (b - a <= 1111LL) {
        for (long long i = a + 1; i <= b; ++i) {
            ans *= i % 10;
            ans %= 10;
        }
    } else {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}