#include <bits/stdc++.h>
using namespace std;

int main()
{
  //  freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    swap(n, m);
    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<char> > b(m, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[j][n - i - 1] = a[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        reverse(b[i].begin(), b[i].end());
    }
    for (int i = 0; i < m; ++i) {
        for (int itr = 0; itr < 2; ++itr) {
            for (int j = 0; j < n; ++j) {
                cout << b[i][j] << b[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}