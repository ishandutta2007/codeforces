#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_n = 1e2;
const int max_m = 1e4;

int n, m;
int a[max_n][max_m], b[max_n][max_m];

int main() {
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            b[i][j] = -1;
    for (int i = 0; i < n; ++i) {
        int bl = -1;
        for (int j = 0; j < m; ++j)
            if (a[i][j]) {
                bl = j;
                break;
            }
        if (bl == -1) continue;
        int br = -1;
        for (int j = m - 1; j >= 0; --j)
            if (a[i][j]) {
                br = j;
                break;
            }
        for (int j = 0; j < m; ++j)
            if (a[i][j])
                b[i][j] = 0;
        for (int j = 1; j < m; ++j)
            if (b[i][j - 1] != -1 && (b[i][j] == -1 || b[i][j - 1] + 1 < b[i][j])) {
                b[i][j] = b[i][j - 1] + 1;
            }
        for (int j = m - 2; j >= 0; --j)
            if (b[i][j + 1] != -1 && (b[i][j] == -1 || b[i][j + 1] + 1 < b[i][j])) {
                b[i][j] = b[i][j + 1] + 1;
            }
        for (int j = 0; j < m; ++j) {
            if (b[i][j] == -1 || m - br + j < b[i][j]) {
                b[i][j] = m - br + j;
            } 
            if (b[i][j] == -1 || bl + m - j < b[i][j]) {
                b[i][j] = bl + m - j;
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < m; ++i) {
        int cans = 0;
        bool fnd = true;
        for (int j = 0; j < n; ++j)
            if (b[j][i] == -1) {
                fnd = false;
                break;
            } else {
                cans += b[j][i];
            }
        if (fnd && (ans == -1 || cans < ans)) {
            ans = cans;
        }
    }
    cout << ans << endl;
    return 0;
}