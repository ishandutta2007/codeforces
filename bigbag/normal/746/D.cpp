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

const int max_n = 111111, inf = 1011111111;

int n, k, a, b;

void solve(int x, int y, char c1, char c2) {
    string s = "";
    for (int i = 0; i < n; ++i) {
        s += " ";
    }
    for (int i = k - 2; i < n; i += k) {
        s[i] = c1;
        --x;
        if (i + 1 < n) {
            s[i + 1] = c2;
            --y;
        }
    }
    //cout << s << " " << x << " " << y << endl;
    if (x < 0 || y < 0) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            if (x) {
                s[i] = c1;
                --x;
            } else {
                s[i] = c2;
                --y;
            }
        }
    }
    cout << s << endl;
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> a >> b;
    ++k;
    solve(a, b, 'G', 'B');
    solve(b, a, 'B', 'G');
    cout << "NO" << endl;
    return 0;
}