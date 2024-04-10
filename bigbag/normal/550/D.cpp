#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 1111111111;

int k, n, a[max_n];
vector<int> u, v;

void proc(int st) {
    for (int i = 1; i < k; ++i) {
        ++n;
        a[i] = n;
        u.push_back(st);
        v.push_back(a[i]);
    }
    for (int i = 0; i < k / 2; ++i) {
        ++n;
        for (int j = 1; j < k; ++j) {
            u.push_back(a[j]);
            v.push_back(n);
        }
        u.push_back(n);
        v.push_back(n + 1);
        ++n;
        for (int j = 1; j < k; ++j) {
            u.push_back(a[j]);
            v.push_back(n);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    if (k % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    n = 1;
    proc(1);
    ++n;
    u.push_back(1);
    v.push_back(n);
    proc(n);
    cout << n << " " << u.size() << endl;
    for (int i = 0; i < u.size(); ++i) {
        cout << u[i] << " " << v[i] << endl;
    }
    return 0;
}