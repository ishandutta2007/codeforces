#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

double l, d, v, g, r;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> d >> v >> g >> r;
    double t = d / v;
    if (t < g) {
        printf("%.10f\n", t + (l - d) / v);
        return 0;
    }
    pair<double, double> time[11111];
    time[0] = make_pair(0, g);
    for (int i = 1; i < 11111; ++i) {
        if (i % 2 == 1) {
            time[i].first = time[i - 1].second;
            time[i].second = time[i].first + r;
            if (t >= time[i].first && t < time[i].second) {
                t = time[i].second;
                break;
            }
        } else {
            time[i].first = time[i - 1].second;
            time[i].second = time[i].first + r;
            if (t >= time[i].first && t < time[i].second) {
                break;
            }
        }
    }
    printf("%.10f\n", t + (l - d) / v);
    return 0;
}