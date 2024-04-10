#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, vb, vs, xu, yu;
double t[max_n], x[max_n];

double len(long double x, long double y, long double xx1, long double yy1) {
    return sqrt((x - xx1) * (x - xx1) + (y - yy1) * (y - yy1));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> vb >> vs;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        t[i] = x[i] / vb;
    }
    cin >> xu >> yu;
    int ans = 1;
    for (int i = 2; i < n; ++i) {
        double t1 = t[ans] + len(x[ans], 0, xu, yu) / vs, t2 = t[i] + len(x[i], 0, xu, yu) / vs;
        if (t2 < t1  || t1 == t2 && len(x[ans], 0, xu, yu) > len(x[i], 0, xu, yu)) {
            ans = i;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}