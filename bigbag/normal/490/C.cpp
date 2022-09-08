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

const int max_n = 1111111, inf = 1111111111;

string s, a1, a2;
long long a, b, dp1[max_n], dp2[max_n], n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> a >> b;
    n = s.length();
    dp1[0] = (s[0] - '0') % a;
    for (int i = 1; i < n; ++i) {
        dp1[i] = (dp1[i - 1] * 10 + s[i] - '0') % a;
    }
    dp2[n - 1] = (s[n - 1] - '0') % b;
    long long pw = 1;
    for (int i = n - 2; i >= 0; --i) {
        pw = (pw * 10) % b;
        dp2[i] = (s[i] - '0') * pw + dp2[i + 1];
        dp2[i] %= b;
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i + 1] != '0' && dp1[i] == 0 && dp2[i + 1] == 0) {
            cout << "YES" << endl;
            a1 = s.substr(0, i + 1);
            a2 = s.substr(i + 1, n - i - 1);
            cout << a1 << endl;
            cout << a2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}