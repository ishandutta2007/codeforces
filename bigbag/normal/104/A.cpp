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

int n, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 2; i <= 13; ++i) {
        if (i == 12) {
            continue;
        }
        int sum = min(10, i);
        if (sum + 10 == n) {
            ans += 4;
        }
    }
    if (n == 20) {
        ans += 3;
    }
    if (n == 11 || n == 21) {
        ans += 4;
    }
    cout << ans << endl;
    return 0;
}