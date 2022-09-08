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

const int max_n = 11, inf = 1111111111;

int n, l[max_n], r[max_n];
double c[max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        c[i] = r[i] - l[i] + 1;
    }
    double ans = 0;
    int fin = (1 << n);
    for (int cost = 1; cost <= 10000; ++cost) {
        //double sumv = 0;
        for (int i = 0; i < n; ++i) {
            for (int mask = 1; mask < fin; ++mask) {
                if (get_bit(mask, i)) {
                    continue;
                }
                if (cost + 1 <= r[i]) {
                    double v = (r[i] - max(l[i], cost + 1) + 1) / c[i];
                    for (int j = 0; j < n; ++j) {
                        if (i != j) {
                            if (get_bit(mask, j)) {
                                if (cost > r[j] || cost < l[j]) {
                                    v = 0;
                                    break;
                                }
                                double v2 = 1 / c[j];
                                v *= v2;
                            } else {
                                if (cost - 1 < l[j]) {
                                    v = 0;
                                    break;
                                }
                                double v2 = (min(cost - 1, r[j]) - l[j] + 1) / c[j];
                                v *= v2;
                            }
                        }
                    }
                    //printf("%.10f %d %d += %.10f    mask = %d\n", v, cost, i, cost * v * (r[i] - max(l[i], cost) + 1) / c[i], mask);
                    ans += cost * v;// * (r[i] - max(l[i], cost + 1) + 1) / c[i];
                    //sumv += v * (r[i] - max(l[i], cost + 1) + 1) / c[i];
                }
                if (l[i] <= cost && cost <= r[i]) {
                    double v = 1 / c[i];
                    int cnt = 1;
                    for (int j = 0; j < n; ++j) {
                        if (i != j) {
                            if (get_bit(mask, j)) {
                                ++cnt;
                                if (cost > r[j] || cost < l[j]) {
                                    v = 0;
                                    break;
                                }
                                double v2 = 1 / c[j];
                                v *= v2;
                            } else {
                                if (cost - 1 < l[j]) {
                                    v = 0;
                                    break;
                                }
                                double v2 = (min(cost - 1, r[j]) - l[j] + 1) / c[j];
                                v *= v2;
                            }
                        }
                    }
                    //printf("%.10f %d %d += %.10f    mask = %d\n", v, cost, i, cost * v * (r[i] - max(l[i], cost) + 1) / c[i] / cnt, mask);
                    ans += cost * v / cnt;// / c[i];
                    //sumv += v * 1 / c[i] / cnt;
                }
            }
        }
        //if (sumv > 0) printf("%d - %.10f\n", cost, sumv);

    }
    printf("%.10lf\n", ans);
    return 0;
}