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

const int max_n = 555;

long long n, a, b, c, ans, f[6];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b >> c;
    long long d = b * b - 4 * a * c;
    long double sq = sqrt(d);
    if (a > 0) {
        printf("%.10f\n", (double) (-b + sq) / (2 * a));
        printf("%.10f\n", (double) (-b - sq) / (2 * a));
    } else {
        printf("%.10f\n", (double) (-b - sq) / (2 * a));
        printf("%.10f\n", (double) (-b + sq) / (2 * a));
    }
    return 0;
}