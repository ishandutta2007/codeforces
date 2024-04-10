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

int n, p, ans, l1, r1, l2, r2;
string s;

int dist(char c1, char c2) {
    if (c1 > c2) swap(c1, c2);
    return min(c2 - c1, c1 - 'a' + 1 + 'z' - c2);
}

int D(int l, int r) {
    if (p <= l) {
        return r - p;
    }
    if (p >= r) {
        return p - l;
    }
    return r - l + min(r - p, p - l);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> p >> s;
    --p;
    l1 = -1;
    for (int i = 0; i < n; ++i) {
        if (i < n - i - 1) {
            int x = dist(s[i], s[n - i - 1]);
            ans += x;
            if (x && l1 == -1) l1 = i;
            if (x) r1 = i;
        }
    }
    if (ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    r2 = n - l1 - 1;
    l2 = n - r1 - 1;
    cout << ans + min(D(l1, r1), D(l2, r2)) << endl;
    return 0;
}