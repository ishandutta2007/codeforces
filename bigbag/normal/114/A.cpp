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

long long a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    long long x = 1, ans = -1;
    while (x < b) {
        x *= a;
        ++ans;
    }
    if (x == b) {
        cout << "YES" << endl << ans << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}