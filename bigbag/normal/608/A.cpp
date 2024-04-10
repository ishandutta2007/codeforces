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

const int max_n = 1111, inf = 1111111111;

int n, s, ans, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    while (n--) {
        int x, y;
        cin >> x >> y;
        a[x] = max(a[x], y);
    }
    int t = 0;
    while (s != 0) {
        t = max(t, a[s]);
        --s;
        ++t;
    }
    cout << t << endl;
    return 0;
}