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

long double l1, l2, l3, v1, v2, v3, v, r, R, h, S, pi;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pi = 2 * acos((long double) (0));
    cin >> l1 >> l2 >> l3;
    v1 = l1 * l1 * l1 * sqrt(2) / 12;
    v2 = l2 * l2 * l2 / 3 / sqrt(2);
    r = sqrt(5) * sqrt(5 + 2 * sqrt(5)) / 10;
    r *= l3;
    R = (sqrt(5) - 1) * r;
    h = sqrt(l3 * l3 - R * R);
    S = l3 * l3 * (5.0 / 4.0) / tan(pi / 5);
    v3 = h * S / 3;
    v = v1 + v2 + v3;
    printf("%.10f\n", (double) v);
    return 0;
}