#include <set>
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

const int max_n = 11, inf = 111111111;
const double eps = 1e-9;

struct shar {
    double x, v, m;
    void read() {
        cin >> x >> v >> m;
    }
};

void update_v(shar &a, shar &b) {
    double v1, v2;
    v1 = ((a.m - b.m) * a.v + 2 * b.m * b.v) / (a.m + b.m);
    v2 = ((b.m - a.m) * b.v + 2 * a.m * a.v) / (a.m + b.m);
    a.v = v1;
    b.v = v2;
}

int n, t;
shar s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        s[i].read();
    }
    double now_t = 0;
    while (1) {
        double min_t = inf;
        int num1, num2;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int ff = 0;
                if (s[i].x > s[j].x) {
                    swap(s[i], s[j]);
                    ff = 1;
                }
                if (s[i].x < s[j].x) {
                    int f = 0;
                    if (s[i].v < 0 && s[j].v > 0 || s[i].v * s[j].v > 0 && s[i].v < s[j].v) {//s[i].v > 0 && s[j].v > 0 && s[i].v < s[j].v || s[i].v < 0 && s[j].v < 0 && s[i].v < s[j].v
                        f = 1;
                    }
                    if (f == 0) {
                        double v;
                        if (s[i].v > 0 && s[j].v < 0) {
                            v = s[i].v - s[j].v;
                        }
                        if (s[i].v * s[j].v > 0) {
                            v = s[i].v - s[j].v;
                        }
                        double tt = (s[j].x - s[i].x) / v;
                        if (tt < min_t) {
                            min_t = tt;
                            num1 = i;
                            num2 = j;
                        }
                    }
                }
                if (ff == 1) {
                    swap(s[i], s[j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (now_t + min_t < t) {
                s[i].x += s[i].v * min_t;
            } else {
                s[i].x += s[i].v * (t - now_t);
            }
        }
        if (now_t + min_t < t) {
            now_t += min_t;
            //update_v(s[num1], s[num2]);
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    if (fabs(s[i].x - s[j].x) <= eps) {
                        update_v(s[i], s[j]);
                    }
                }
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%.10f\n", s[i].x);
    }
    return 0;
}