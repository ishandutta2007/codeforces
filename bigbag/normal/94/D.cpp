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

const int max_n = 55, inf = 1111111111;
const double eps = 1e-9;

int n, m, cnt[max_n];
double w, r;
double q1[max_n], q2[max_n];
vector<pair<int, double> > ans[max_n];

bool bad(double x, double y) {
    return fabs(x - y) > eps;
}

bool good() {
    for (int i = 0; i < n; ++i) {
        if (bad(q1[i], 0)) {
            return false;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (bad(q2[i], r)) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> w >> m;
    r = (n * w) / m;
    for (int i = 0; i < n; ++i) {
        q1[i] = w;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; q1[i] > eps && j < m && cnt[i] < 2; ++j) {
            if (q2[j] + eps < r) {
                ++cnt[i];
                double value = min(r - q2[j], q1[i]);
                q2[j] += value;
                q1[i] -= value;
                ans[j].push_back(make_pair(i + 1, value));
            }
        }
    }
    if (!good()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            printf("%d %.10llf ", ans[i][j].first, ans[i][j].second);
        }
        cout << endl;
    }
    return 0;
}