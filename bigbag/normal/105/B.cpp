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

int n, k, x, fin, a[max_n], b[max_n];
double ans;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

void proc(int poz, int k) {
    if (poz == n) {
        double allv = 0;
        for (int mask = 0; mask < fin; ++mask) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += get_bit(mask, i);
            }
            if (cnt > n / 2) {
                double v = 1;
                int B = 0, f = 0;
                for (int i = 0; i < n; ++i) {
                    if (get_bit(mask, i)) {
                        v *= b[i];
                        if (b[i] == 0) {
                            f = 1;
                            break;
                        }
                    } else {
                        if (b[i] == 100) {
                            f = 1;
                            break;
                        }
                        B += a[i];
                        v *= (100 - b[i]);
                    }
                    v /= 100;
                }
                if (f == 0) {
                    allv += v;
                }
            } else {
                double v = 1;
                int B = 0, f = 0;
                for (int i = 0; i < n; ++i) {
                    if (get_bit(mask, i)) {
                        v *= b[i];
                        if (b[i] == 0) {
                            f = 1;
                            break;
                        }
                    } else {
                        if (b[i] == 100) {
                            f = 1;
                            break;
                        }
                        B += a[i];
                        v *= (100 - b[i]);
                    }
                    v /= 100;
                }
                if (f == 0) {
                    allv += v * x / (x + B);
                }
            }
        }
        /*for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << " : " << allv << endl;*/
        ans = max(ans, allv);
        return;
    }
    for (int i = 0; i <= k && b[poz] + i * 10 <= 100; ++i) {
        b[poz] += i * 10;
        proc(poz + 1, k - i);
        b[poz] -= i * 10;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    fin = (1 << n);
    proc(0, k);
    printf("%.10f\n", ans);
    return 0;
}