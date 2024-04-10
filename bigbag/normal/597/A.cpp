#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

long long a, b, k, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k >> a >> b;
    if (a <= 0 && 0 <= b) {
        ++ans;
    }
    if (b > 0) {
        ans += b / k;
        if (a > 0) {
            ans -= (a - 1) / k;
        } else {
            ans += (-a) / k;
        }
    } else {
        ans += (-a) / k;
        if (b != 0) {
            ans -= (-b - 1) / k;
        }
    }
    cout << ans << endl;
    return 0;
}