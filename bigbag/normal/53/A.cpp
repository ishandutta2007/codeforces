#include <map>
#include <set>
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

const int max_n = 111, inf = 111111111;

int n;
string s, ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    ans = s;
    for (int i = 0; i < max_n; ++i) {
        ans = ans + "z";
    }
    int f = 0;
    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        if (a.length() >= s.length() && s == a.substr(0, s.length())) {
            if (/*ans.length() > a.length() || ans.length() == a.length() && */ans > a) {
                ans = a;
                f = 1;
            }
        }
    }
    if (f == 0) {
        cout << s << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}