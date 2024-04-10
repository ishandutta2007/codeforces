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

const int max_n = 111111, inf = 1111111111;

int n;
string s, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    ans = s;
    for (int i = 0; i < n; ++i) {
        string q = s;
        int x = q[0] - '0';
        x = 10 - x;
        if (x == 10) {
            x = 0;
        }
        for (int j = 0; j < n; ++j) {
            q[j] += x;
            if (q[j] > '9') {
                q[j] -= 10;
            }
        }
        //cout << q << endl;
        ans = min(ans, q);
        char c = s[n - 1];
        for (int i = n - 1; i > 0; --i) {
            s[i] = s[i - 1];
        }
        s[0] = c;
    }
    cout << ans << endl;
    return 0;
}