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

const int max_n = 222, inf = 1111111111;

int n, a[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    if (n > 26) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        ++a[s[i]];
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        ans += max(0, a[c] - 1);
    }
    cout << ans << endl;
    return 0;
}