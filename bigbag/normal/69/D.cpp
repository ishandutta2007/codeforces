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

const int max_n = 22, inf = 111111111;

int n;
double x, y, d, dx[max_n], dy[max_n];
map<pair<double, double>, bool> m;

double dist(double x, double y) {
    return x * x + y * y;
}

bool game(double x, double y) {
    if (dist(x, y) > d) {
        return false;
    }
    pair<double, double> p = make_pair(x, y);
    if (m.count(p)) {
        return m[p];
    }
    for (int i = 0; i < n; ++i) {
        double a = x + dx[i], b = y + dy[i];
        if (game(a, b)) {
            m[p] = false;
            return false;
        }
    }
    m[p] = true;
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> x >> y >> n >> d;
    d *= d;
    for (int i = 0; i < n; ++i) {
        cin >> dx[i] >> dy[i];
    }
    if (!game(x, y)) {
        cout << "Anton" << endl;
    } else {
        cout << "Dasha" << endl;
    }
    return 0;
}