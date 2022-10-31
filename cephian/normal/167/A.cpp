#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
double a, d;
double mt[1000005];

int main() {
    // ios::sync_with_stdio(0);
    scanf("%d %lf %lf", &n, &a, &d);
    for(int i = 0; i < n; ++i) {
        double t, v;
        scanf("%lf %lf", &t, &v);
        double d1 = v*v / (2*a);
        if(d1 > d)
            mt[i] = t + sqrt(2*d/a);
        else
            mt[i] = t + v/a + (d - d1)/v;
    }
    double tim = 0;
    for(int i = 0; i < n; ++i) {
        tim = max(tim, mt[i]);
        // cout << tim << endl;
        printf("%.15lf\n", tim);
    }

    return 0;
}