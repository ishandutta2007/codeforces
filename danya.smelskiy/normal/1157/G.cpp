# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;

int n, m;
int a[205][205];
int b[205][205];
int c[205][205];
bool used1[205], used2[205];

void solve(int tp) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] = a[i][j];
            if (tp == 1 && i == 1) b[i][j] = 1 - b[i][j];
        }
    }
    for (int l = 0; l <= m; ++l) {
        for (int i = 1; i <= n; ++i)
            used1[i] = false;
        for (int i = 1; i <= m; ++i)
            used2[i] = false;
        for (int i = 1; i <= m; ++i)
            if (i <= l && b[1][i] == 1) used2[i] = true;
            else if (i > l && b[1][i] == 0) used2[i] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                c[i][j] = b[i][j];
                if (used2[j]) c[i][j] = 1 - c[i][j];
            }
        }
        vector<int> v;
        for (int i = 1; i <= n; ++i) {
            int c1 = 0, c2 = 0;
            for (int j = 1; j <= m; ++j) {
                if (c[i][j]) ++c1;
                else ++c2;
            }
            if (c1 && c2) v.push_back(i);
        }
        if ((int)v.size() > 1) continue;
        if ((int)v.size() == 0) {
            for (int i = 2; i <= n; ++i) {
                if (c[i][1] != c[1][1]) used1[i] = true;
            }
            cout << "YES\n";
            for (int i = 1; i <= n; ++i)
                if (used1[i]) cout << "1";
                else cout << "0";
            cout << '\n';
            for (int i = 1; i <= m; ++i)
                if (used2[i]) cout << "1";
                else cout << "0";
            cout << '\n';
            exit(0);
        }
        bool t1 = false;
        int pos = v[0];
        for (int j = 2; j <= m; ++j)
            if (c[pos][j] < c[pos][j - 1]) t1 = true;
        if (t1) {
            if (pos == 1) continue;
            for (int j = 1; j <= m; ++j)
                c[pos][j] = 1 - c[pos][j];
            used1[pos] = true;
        }
        if (tp == 1) used1[1] = true;

        for (int i = 2; i < pos; ++i) if (c[i][1]) {
            for (int j = 1; j <= m; ++j)
                c[i][j] = 1 - c[i][j];
            used1[i] = true;
        }
        for (int i = pos + 1; i <= n; ++i) if (!c[i][1]) {
            for (int j = 1; j <= m; ++j)
                c[i][j] = 1 - c[i][j];
            used1[i] = true;
        }

        t1 = false;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (j > 1 && c[i][j] < c[i][j - 1]) t1 = true;
                if (i > 1 && j == 1 && c[i][j] < c[i - 1][m]) t1 = true;
            }
        }
        if (t1) continue;
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
            if (used1[i]) cout << "1";
            else cout << "0";
        cout << '\n';
        for (int i = 1; i <= m; ++i)
            if (used2[i]) cout << "1";
            else cout << "0";
        cout << '\n';
        exit(0);
    }
    return;
}


int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 2; ++i)
        solve(i);
    cout << "NO\n";
    return 0;
}