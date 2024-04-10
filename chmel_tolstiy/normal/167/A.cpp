#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

typedef pair<int, double> pid;

double f[1 << 17];

void solve() {
    int n, a, d;
    cin >> n >> a >> d;

    for (int i = 0; i < n; i++) {
        int t, v;
        scanf("%d%d", &t, &v);
        double ta = (double)v / a;
        double S = ta*ta*a/2;

        double f0 = t;

        if (S > d) {
            f0 = t + sqrt(2.*d/a);
        } else {
            f0 = t + ta + (d - S) / v;
        }

        f[i] = f0;
        if (i && f[i] < f[i-1]) f[i] = f[i-1];
    }

    for (int i = 0; i < n; i++) {
        printf("%.10lf\n", f[i]);
    }
}

int main() {
    solve();

    return 0;
}