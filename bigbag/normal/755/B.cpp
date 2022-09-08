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

const int max_n = 555, inf = 1011111111;

int n, m, x, y, z;
set<string> q;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        q.insert(s);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%s", s);
        if (q.count(s)) {
            ++z;
        } else {
            ++y;
        }
    }
    x = n - z;
    //cout << x << " " << y << " " << z << endl;
    for (int i = 0; ; ++i) {
        if (i % 2 == 0) {
            if (z) {
                --z;
            } else if (x) {
                --x;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if (z) {
                --z;
            } else if (y) {
                --y;
            } else {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    return 0;
}