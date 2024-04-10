#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111111;

int mod, h1, a1, x1, y1, h2, a2, x2, y2, res[2], last[2], num[2][max_n];

void proc(int qqq, int h, int x, int y) {
    for (int i = 1; ; ++i) {
        if (num[qqq][h]) {
            res[qqq] = h;
            break;
        }
        num[qqq][h] = i;
        last[qqq] = h;
        h = (1LL * x * h + y) % mod;
    }
}

void proc2() {
    int w1 = h1, w2 = h2;
    for (int i = 1; i < 5555555; ++i) {
        w1 = (1LL * x1 * w1 + y1) % mod;
        w2 = (1LL * x2 * w2 + y2) % mod;
        if (w1 == a1 && w2 == a2) {
            cout << i << endl;
            exit(0);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> mod >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    proc(0, h1, x1, y1);
    proc(1, h2, x2, y2);
    proc2();
    if (num[0][a1] < num[0][res[0]] || num[1][a2] < num[1][res[1]]) {
        cout << -1 << endl;
        return 0;
    }
    int l1 = num[0][last[0]] - num[0][res[0]] + 1;
    int l2 = num[1][last[1]] - num[1][res[1]] + 1;
    if (num[0][a1] < num[1][a2]) {
        long long ans = num[1][a2] - 1;
        int p = (num[1][a2] - num[0][res[0]]) % l1;
        for (int i = 0; i < 5555555; ++i) {
            if (p == num[0][a1] - num[0][res[0]]) {
                cout << ans << endl;
                return 0;
            }
            p = (p + l2) % l1;
            ans += l2;
        }
        cout << -1 << endl;
        return 0;
    }
    long long ans = num[0][a1] - 1;
    int p = (num[0][a1] - num[1][res[1]]) % l2;
    for (int i = 0; i < 5555555; ++i) {
        if (p == num[1][a2] - num[1][res[1]]) {
            cout << ans << endl;
            return 0;
        }
        ans += l1;
        p = (p + l1) % l2;
    }
    cout << -1 << endl;
    return 0;
}