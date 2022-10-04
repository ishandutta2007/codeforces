#include <iostream>

using namespace std;

const long long mx = 1000;

long long n, s, m[mx][mx], ii, jj, sr;

bool check() {
    long long i, j, t;
    for (i = 0; i<n; i++) {
        t = 0;
        for (j = 0; j<n; j++) {
            t += m[i][j];
        }
        if (t!=s) return 0;
    }
    for (j = 0; j<n; j++) {
        t = 0;
        for (i = 0; i<n; i++) {
            t += m[i][j];
        }
        if (t!=s) return 0;
    }
    t = 0;
    for (i = 0; i<n; i++) {
        t += m[i][i];
    }
    if (t!=s) return 0;
    t = 0;
    for (i = 0; i<n; i++) {
        t += m[i][n-i-1];
    }
    if (t!=s) return 0;
    return 1;
}

int main()
{
    cin >> n;
    long long i, j;
    for (i = 0; i<n; i++) {
        for (j = 0; j<n; j++) {
            cin >> m[i][j];
            if (m[i][j] == 0) {
                ii = i;
                jj = j;
            }
        }
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (i = 0; i<n; i++) {
        s = 0;
        for (j = 0; j<n; j++) {
            s += m[i][j];
            if (m[i][j] == 0) {
                s = 0;
                break;
            }
        }
        if (s > 0) break;
    }
    sr = 0;
    for (j = 0; j<n; j++) {
        sr += m[ii][j];
    }
    if (sr >= s) {
        cout << -1;
        return 0;
    }
    m[ii][jj] = s - sr;
    if (check() == 1) {
        cout << m[ii][jj];
    }
    else {
        cout << -1;
    }
    return 0;
}