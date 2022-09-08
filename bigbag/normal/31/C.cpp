#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5555, inf = 111111111;

int n, l[max_n], r[max_n];
vector <int> g[max_n];

bool per(int l1, int r1, int l2, int r2) {
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (l2 < r1) {
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (per(l[i], r[i], l[j], r[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector <int> v;
    int cnt = 0, poz;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 1) {
            cnt++;
            poz = i;
        }
        if (g[i].size() == 1) {
            v.push_back(i);
        }
    }
    if (cnt > 1) {
        cout << 0 << endl;
        return 0;
    }
    if (cnt == 0) {
        if (v.size() > 2) {
            cout << 0 << endl;
            return 0;
        }
        if (v.size() == 0) {
            cout << n << endl;
            for (int i = 1; i <= n; ++i) {
                cout << i << ' ';
            }
            return 0;
        }
        cout << 2 << endl << v[0] + 1 << ' ' << v[1] + 1 << endl;
    }
    if (cnt == 1) {
        for (int i = 0; i < v.size(); ++i) {
            if (g[v[i]][0] != poz) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << 1 << endl << poz + 1 << endl;
    }
    return 0;
}