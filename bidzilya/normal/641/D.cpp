#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>
using namespace std;

const double EPS = 1e-9;

void Normalize(double& x) {
    if (x < EPS) {
        x = 0.0;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<double> xx(n);
    vector<double> nn(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &xx[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &nn[i]);
    }
    for (int i = 1; i < n; ++i) {
        xx[i] += xx[i - 1];
        nn[i] += nn[i - 1];
    }

    vector<double> fa(n);
    vector<double> fb(n);
    for (int i = 0; i < n; ++i) {
        double d = xx[i] + nn[i];
        d *= d;
        d -= xx[i] * 4.0;
        Normalize(d);
        d = sqrt(d);

        fa[i] = (xx[i] + nn[i] + d) / 2.0;
        fb[i] = (xx[i] + nn[i] - d) / 2.0;
    }

    for (int i = 0; i < n; ++i) {
        double val;
        if (i == 0) {
            val = fa[i];
        } else {
            val = fa[i] - fa[i - 1];
        }
        Normalize(val);
        printf("%.10lf ", val);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        double val;
        if (i == 0) {
            val = fb[i];
        } else {
            val = fb[i] - fb[i - 1];
        }
        Normalize(val);
        printf("%.10lf ", val);
    }
    printf("\n");

    return 0;
}