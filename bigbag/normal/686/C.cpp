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

const int max_n = 1, inf = 1111111111;

int n, m, len, ans, N, M, used[11];
vector<int> a, b;

void rec(int poz, int x, int y) {
    if (poz == len) {
        if (x < N && y < M) {
            //cout << x << " " << y << endl;
            ++ans;
        }
        return;
    }
    for (int i = 0; i < 7; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            int nx = x, ny = y;
            if (poz < a.size()) {
                nx = nx * 7 + i;
            } else {
                ny = ny * 7 + i;
            }
            rec(poz + 1, nx, ny);
            used[i] = 0;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    N = n;
    M = m;
    --n;
    --m;
    if (n == 0) {
        a.push_back(0);
    }
    if (m == 0) {
        b.push_back(0);
    }
    while (n) {
        a.push_back(n % 7);
        n /= 7;
    }
    while (m) {
        b.push_back(m % 7);
        m /= 7;
    }
    if (a.size() + b.size() > 7) {
        cout << 0 << endl;
        return 0;
    }
    len = a.size() + b.size();
    rec(0, 0, 0);
    cout << ans << endl;
    return 0;
}