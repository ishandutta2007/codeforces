#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1e5 + 100;

string s;
int m;
int n;
int l, r;   
int x[max_n], y[max_n], z[max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; ++i) {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        z[i] = z[i - 1];
        if (s[i - 1] == 'x') ++x[i];
        if (s[i - 1] == 'y') ++y[i];
        if (s[i - 1] == 'z') ++z[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int cz, cx, cy;
        cz = z[r] - z[l - 1];
        cy = y[r] - y[l - 1];
        cx = x[r] - x[l - 1];
        int len = r - l + 1;
        if (len < 3) {
            cout << "YES" << endl;
            continue;
        }
        int first = (len - 1) / 3 + 1;
        int second = 0;
        if (len >= 2) {
            second = 1 + (len - 2) / 3;
        }
        int third = 0;
        if (len >= 3) {
            third = 1 + (len - 3) / 3;
        }
        if ((cz == first && cy == second && cx == third) ||
            (cx == first && cz == second && cy == third) ||
            (cy == first && cx == second && cz == third)) {
                cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}