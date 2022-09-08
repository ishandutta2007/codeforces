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

int n;
string s, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (i + 3 <= n && s.substr(i, 3) == "ogo") {
            ans += "***";
            i += 3;
            while (i + 2 <= n && s.substr(i, 2) == "go") {
                i += 2;
            }
            --i;
        } else {
            ans += s[i];
        }
    }
    cout << ans << endl;
    return 0;
}