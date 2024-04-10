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

const int max_n = 111111, inf = 111111111;
const double eps = 1e-9;

long long n;
double a, d;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> d >> n;
    for (int i = 1; i <= n; ++i) {
        double len = (i * d) - (4 * a * ((long long) ((i * d) / (4 * a))));
        int poz = (len - eps) / a;
        if (poz == 0) {
            printf("%.5f %.5f\n", len, 0.0);
        }
        if (poz == 1) {
            printf("%.5f %.5f\n", a, len - a);
        }
        if (poz == 2) {
            printf("%.5f %.5f\n", 3 * a - len, a);
        }
        if (poz == 3) {
            printf("%.5f %.5f\n", 0.0, 4 * a - len);
        }
    }
    return 0;
}