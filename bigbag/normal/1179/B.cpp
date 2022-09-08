#include <bits/stdc++.h>

using namespace std;

#define x1 qwe
#define y1 qwer
#define x2 qwert
#define y2 qwerty

void solve(int n, int m) {
    vector<int> ansx(n * m), ansy(n * m);
    vector<vector<int>> a(n, vector<int> (m));
    int cnt = 0;
    int x1 = 0, y1 = 0, x2 = n - 1, y2 = m - 1;
    int d1 = 0, d2 = n - 1 + m - 1;
    while (cnt < n * m) {
        a[x1][y1] = cnt++;
        if (cnt == n * m) {
            break;
        }
        a[x2][y2] = cnt++;

        if (x1 && y1 + 1 < m) {
            --x1;
            ++y1;
        } else {
            ++d1;
            x1 = min(n - 1, d1);
            y1 = d1 - x1;
            //cout << "$" << x1 << " " << y1 << endl;
        }
        if (x2 + 1 < n && y2) {
            ++x2;
            --y2;
        } else {
            --d2;
            y2 = m - 1;
            x2 = d2 - y2;
            if (x2 < 0) {
                y2 += x2;
                x2 -= x2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //cout << a[i][j] << " ";
            ansx[a[i][j]] = i;
            ansy[a[i][j]] = j;
        }
        //cout << endl;
    }
    if (0) {
        set<pair<int, int>> q;
        for (int i = 0; i + 1 < n * m; ++i) {
            q.insert({ansx[i + 1] - ansx[i], ansy[i + 1] - ansy[i]});
        }
        assert(q.size() == n * m - 1);
    } else {
        for (int i = 0; i < n * m; ++i) {
            printf("%d %d\n", ansx[i] + 1, ansy[i] + 1);
        }
    }
}

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (1) {
        scanf("%d%d", &n, &m);
        solve(n, m);
        return 0;
    }
    for (int n = 1; n <= 10; ++n) {
        for (int m = 1; m <= 10; ++m) {
            cout << n << " " << m << endl;
            solve(n, m);
        }
    }
    return 0;
}