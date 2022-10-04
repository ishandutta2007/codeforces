#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <string>
#include <cstring>
#include <functional>
#include <numeric>
#include <random>
#include <cassert>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>

#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
    while (begin != end) {
        out << (*begin) << " ";
        begin++;
    }
    out << endl;
}

template<class T> void output(T &x, ostream& out = cerr) {
    output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> int chkmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return 1;
    }
    return 0;
}

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int mx = 1010;
int n, m;
int a[mx][mx], l1[mx][mx], r1[mx][mx], l2[mx][mx], r2[mx][mx];

int main() {
    fast_io();
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<int> v;
        for (int j = 0; j < m; ++j) {
            v.push_back(a[i][j]);
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        int sz = v.size();
        for (int j = 0; j < m; ++j) {
            int pos = lower_bound(all(v), a[i][j]) - v.begin();
            l1[i][j] = pos;
            r1[i][j] = sz - 1 - pos;
        }
    }

    for (int i = 0; i < m; ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            v.push_back(a[j][i]);
        }
        sort(all(v));
        v.erase(unique(all(v)), v.end());
        int sz = v.size();
        for (int j = 0; j < n; ++j) {
            int pos = lower_bound(all(v), a[j][i]) - v.begin();
            l2[j][i] = pos;
            r2[j][i] = sz - 1 - pos;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int res = max(l1[i][j], l2[i][j]) + max(r1[i][j], r2[i][j]) + 1;
            cout << res << " ";
        }
        cout << endl;
    }
}