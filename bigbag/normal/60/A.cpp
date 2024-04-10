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

const int max_n = 1111, inf = 111111111;

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    int l = n, r = 1;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        int x;
        cin >> s1 >> s1 >> s1 >> s2 >> x;
        if (s1 == "left") {
            l = min(l, x - 1);
        } else {
            r = max(r, x + 1);
        }
    }
    if (l < r) {
        cout << -1 << endl;
    } else {
        cout << l - r + 1 << endl;
    }
    return 0;
}