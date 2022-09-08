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

const int max_n = 111, inf = 1111111111;

int n, used[max_n];
pair<int, int> p[max_n];

int solve(int napr) {
    memset(used, 0, sizeof(used));
    int x = 0, res = 0;
    while (true) {
        if (napr == 1) {
            int f = -1;
            for (int i = 0; i < n; ++i) {
                if (x < p[i].first && used[i] == 0) {
                    x = p[i].first;
                    used[i] = 1;
                    res += p[i].second;
                    f = 1;
                    break;
                }
            }
            if (f == -1) {
                return res;
            }
        } else {
            int f = -1;
            for (int i = n - 1; i >= 0; --i) {
                if (x > p[i].first && used[i] == 0) {
                    x = p[i].first;
                    used[i] = 1;
                    res += p[i].second;
                    f = 1;
                    break;
                }
            }
            if (f == -1) {
                return res;
            }
        }
        napr ^= 1;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    cout << max(solve(0), solve(1));
    return 0;
}