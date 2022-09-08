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

const int max_n = 222, inf = 1011111111;

int a[max_n], cnt[max_n];
string s, q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    q = "Bulbasaur";
    cin >> s;
    for (int i = 0; i < q.length(); ++i) {
        ++a[q[i]];
    }
    for (int i = 0; i < s.length(); ++i) {
        ++cnt[s[i]];
    }
    int ans = inf;
    for (int i = 0; i < q.length(); ++i) {
        ans = min(ans, cnt[q[i]] / a[q[i]]);
    }
    cout << ans << endl;
    return 0;
}