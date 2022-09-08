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

int ans, a[5];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> s;
    for (int i = 0; i < s.length(); ++i) {
        ans += a[s[i] - '0'];
    }
    cout << ans << endl;
    return 0;
}