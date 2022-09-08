#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;
const int dx[] = {1, 1, 1, 2};
const int dy[] = {-1, 0, 1, 0};

int n;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '.') {
                if (i + 2 >= n || j == 0 || j + 1 == n) {
                    cout << "NO" << endl;
                    return 0;
                }
                for (int k = 0; k < 4; ++k) {
                    if (s[i + dx[k]][j + dy[k]] == '#') {
                        cout << "NO" << endl;
                        return 0;
                    }
                    s[i + dx[k]][j + dy[k]] = '#';
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}