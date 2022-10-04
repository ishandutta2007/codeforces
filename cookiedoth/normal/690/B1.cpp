#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int x1 = -1, y1 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 4) {
                x1 = i, y1 = j;
                break;
            }
        }
        if (x1 != -1) break;
    }
    int x2 = -1, y2 = -1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 4) {
                x2 = i, y2 = j;
                break;
            }
        }
        if (x2 != -1) break;
    }
    if (x1 == -1 || x2 == -1) {
        cout << "No" << endl;
        return 0;
    }
    vector<vector<int>> b(n, vector<int>(n));
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            b[i][j] = 4;
        }
    }
    if (x1 > 0 && y1 > 0) b[x1 - 1][y1 - 1] = 1;
    if (x2 < n - 1 && y2 < n - 1) b[x2 + 1][y2 + 1] = 1;
    if (x1 > 0 && y2 < n - 1) b[x1 - 1][y2 + 1] = 1;
    if (x2 < n - 1 && y1 > 0) b[x2 + 1][y1 - 1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= y1 && j <= y2 && (i + 1 == x1 || i - 1 == x2)) b[i][j] = 2;
            if (i >= x1 && i <= x2 && (j + 1 == y1 || j - 1 == y2)) b[i][j] = 2;
        }
    }
    if (a == b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}