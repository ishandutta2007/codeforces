#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    int mx = *min_element(x.begin(), x.end());
    int my = *min_element(y.begin(), y.end());
    for (int i = 0; i < n; ++i) {
        x[i] -= mx;
        y[i] -= my;
    }
    double res = 0;
    bool isY = false;
makeY:
trap:
    int MX = *max_element(x.begin(), x.end());
    vector<int> count(MX + 1);
    for (int i = 0; i < n; ++i) {
        int x1 = x[i];
        int x2 = x[(i+1) % n];
        int y1 = y[i];
        int y2 = y[(i+1) % n];

        if (x1 == x2) {
            continue;
        }
        if (x1 < x2) {
            if (x2 == MX) count[x2] += y2;
            for (int X = 0; X + x1 < x2; ++X) {
                count[x1 + X] += y1;
                if (y1 <= y2) {
                    count[x1 + X] += 1LL * (y2 - y1) * X / (x2 - x1);
                } else {
                    count[x1 + X] -= (1LL * (y1 - y2) * X + (x2 - x1) - 1) / (x2 - x1);
                }
            }
        } else {
            if (x2 == 0) count[0] -= y2 - 1;
            for (int X = 1; X + x2 <= x1; ++X) {
                count[x2 + X] -= y2;
                if (y1 >= y2) {
                    count[x2 + X] -= (1LL * (y1 - y2) * X) / (x1 - x2);
                    if ((1LL * (y1 - y2) * X) % (x1 - x2) == 0)
                        count[x2 + X]++;
                } else {
                    count[x2 + X] += 1LL * (y2 - y1) * X / (x1 - x2) + 1;
                }            
            }
        }
    }

    if (*min_element(count.begin(), count.end()) < 0) {
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        goto trap;
    }
/*
    for (int i = 0; i <= MX; ++i)
        cerr << count[i] << ' ';
    cerr << endl;
*/
    double sumX = 0;
    double sumXS = 0;
    double cnt = 0;

    for (int i = 0; i <= MX; ++i) {
        res += count[i] * (sumXS - sumX * 2 * i + 1.0 * i * i * cnt);
        sumXS += 1.0 * count[i] * i * i;
        sumX += 1.0 * count[i] * i;
        cnt += count[i];
    }

    if (isY == false) {
        isY = true;
        for (int i = 0; i < n; ++i) swap(x[i], y[i]);
        goto makeY;
    }

    res /= cnt * (cnt - 1) / 2;

    printf("%.10lf\n", res / 2);

    return 0;
}