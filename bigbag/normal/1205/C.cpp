#include <bits/stdc++.h>

using namespace std;

const int max_n = 51, inf = 1000111222;

const bool debug = false;

bool A[max_n][max_n], DP[max_n][max_n][max_n][max_n];

int n;
bool a[2][max_n][max_n];
bool dp[2][max_n][max_n][max_n][max_n];

bool query(int x1, int y1, int x2, int y2) {
    if (debug) {
        cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cout << DP[x1][y1][x2][y2] << endl;
        return DP[x1][y1][x2][y2];
    }
    ++x1;
    ++y1;
    ++x2;
    ++y2;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    bool res;
    cin >> res;
    return res;
}

void get_dp(bool a[max_n][max_n], bool dp[max_n][max_n][max_n][max_n]) {
    for (int len1 = 0; len1 < n; ++len1) {
        for (int len2 = 0; len2 < n; ++len2) {
            for (int i = 0; i + len1 < n; ++i) {
                for (int j = 0; j + len2 < n; ++j) {
                    int x = i + len1, y = j + len2;
                    //cout << i << " " << j << " " << x << " " << y << endl;
                    if (i == x && j == y) {
                        dp[i][j][x][y] = 1;
                        continue;
                    }
                    if (a[i][j] == a[x][y]) {
                        if (len1 + len2 == 1) {
                            dp[i][j][x][y] = 1;
                        } else {
                            for (int f1 = 0; f1 < 2; ++f1) {
                                for (int f2 = 0; f2 < 2; ++f2) {
                                    int ni = i + f1, nj = j + 1 - f1;
                                    int nx = x - f2, ny = y - 1 + f2;
                                    if (ni <= nx && nj <= ny && dp[ni][nj][nx][ny]) {
                                        dp[i][j][x][y]= 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    /*if (dp[i][j][x][y]) {
                        cout << "$ " << i << " " << j << " " << x << " " << y << endl;
                    } else {
                        //cout << "        " << i << " " << j << " " << x << " " << y << endl;
                    }*/
                }
            }
        }
    }
}

int solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = i; x < n; ++x) {
                for (int y = j; y < n; ++y) {
                    if (x - i + y - j < 2) {
                        continue;
                    }
                    if (dp[0][i][j][x][y] != dp[1][i][j][x][y]) {
                        bool f = query(i, j, x, y);
                        if (f == dp[0][i][j][x][y]) {
                            return 0;
                        }
                        return 1;
                    }
                }
            }
        }
    }
    exit(228);
    return 0;
    exit(228);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> A[i][j];
            }
        }
        /*n = 49;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = rand() % 2;
            }
        }*/
        get_dp(A, DP);
        //cout << "!!! " << DP[0][0][1][1] << endl;
        //return 0;
    } else {
        cin >> n;
    }
    a[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j < 2) {
                continue;
            }
            bool tp = (i % 2) ^ (j % 2);
            int x, y;
            if (j >= 2) {
                x = i;
                y = j - 2;
                if (tp == 1 && j == 2) {
                    x = i - 1;
                    y = j - 1;
                }
            } else {
                if (tp == 0) {
                    if (j == 1) {
                        x = i - 1;
                        y = j - 1;
                    } else {
                        x = i - 2;
                        y = j;
                    }
                } else {
                    if (j == 1) {
                        x = i - 2;
                        y = j;
                    } else {
                        continue;
                    }
                }
            }
            a[0][i][j] = a[0][x][y] ^ 1 ^ query(x, y, i, j);
            /*if (tp == 1) {
                cout << "              " << i << " " << j << ": " << a[0][i][j] << endl;
            }*/
        }
    }
    for (int i = n - 2; i >= 1; i -= 2) {
        int x = i + 1, y = 1;
        a[0][i][0] = a[0][x][y] ^ 1 ^ query(i, 0, x, y);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[1][i][j] = a[0][i][j];
            bool tp = (i % 2) ^ (j % 2);
            if (tp) {
                a[1][i][j] ^= 1;
            }
        }
    }
    get_dp(a[0], dp[0]);
    get_dp(a[1], dp[1]);
    int ans = solve();
    cout << "!" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[ans][i][j];
            //assert(a[ans][i][j] == A[i][j]);
        }
        cout << endl;
    }
    return 0;
}