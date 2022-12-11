#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vvi R(n, vi(m, 0));
    vvpi T(n, vpi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            T[i][j] = pi(i, j);
        }
    }
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 3) {
            int x, y, k;
            cin >> x >> y >> k;
            --x;
            --y;
            R[T[x][y].first][T[x][y].second] = k;
        }
        else if (t == 1) {
            int r;
            cin >> r;
            --r;
            for (int j = 0; j < m - 1; ++j) {
                swap(T[r][j], T[r][j + 1]);
            }
        }
        else {
           int r;
            cin >> r;
            --r;
            for (int j = 0; j < n - 1; ++j) {
                swap(T[j][r], T[j + 1][r]);
            } 
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            cout << R[i][j];
        }
        cout << endl;
    }
}