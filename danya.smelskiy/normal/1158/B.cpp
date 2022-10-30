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

unsigned long long p[100007], h[100007];

int solve(string s) {
    h[0] = 0;
    for (int i = 1; i <= n; ++i) {
        h[i] = h[i - 1] + (s[i - 1] - '0' + 1) * p[i];
    }
    int l = 1;
    int r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        vector<unsigned long long > v;
        for (int i = mid; i <= n; ++i) {
            unsigned long long cur = h[i] - h[i - mid];
            cur *= p[n + 1 - (i - mid + 1)];
            v.push_back(cur);
        }
        sort(v.begin(), v.end());
        bool tt = false;
        if ((int)v.size() == 1) tt = true;
        else {
            if (v[0] != v[1]) tt = true;
            if (v[(int)v.size() - 2] != v.back()) tt = true;
            for (int i = 1; i < (int)v.size() - 1; ++i)
                if (v[i] != v[i - 1] && v[i] != v[i + 1]) tt = true;
        }
        if (tt) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n + 1; ++i)
        p[i] = p[i - 1] * 31;
    if (n == m) {
        for (int i = 1; i <= n; ++i)
            cout << "0";
        cout << '\n';
        return 0;
    }
    if (n == 2) {
        cout << "01\n";
        return 0;
    }
    if (n == 3) {
        cout << "110\n";
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i < n; ++i)
            cout << "1";
        cout << "0";
        cout << '\n';
        return 0;
    }
    int l = (n - m) / 2;
    string s = "1";
    for (int i = 1; i < n; ++i)
        if (i % (l + 1) == 0) s += "1";
        else s += "0";
    while (solve(s) != m) s = "0" + s;
    for (int i = 1; i <= n; ++i)
        cout << s[i - 1];
    cout << '\n';
    return 0;
}