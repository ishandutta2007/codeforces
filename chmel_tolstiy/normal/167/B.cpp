#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>

using namespace std;

typedef pair<int, double> pid;

double f[256][256];
double d[256][256];

double p[256];
double z[256];

void solve() {
    int n, l, k;
    cin >> n >> l >> k;

    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        p[i] /= 100.0;
    }

    vector<double> priz;
    vector<pid> sumka;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x < 0) {
            priz.push_back(p[i]);
        } else {
            sumka.push_back(make_pair(x, p[i]));
        }
    }

    f[0][0] = 1;
    
    for (int i = 0; i < (int)sumka.size(); ++i) {
        for (int a = 254; a >= 0; a--) for (int b = 255; b >= 0; b--) {
            f[a+1][min(255, b+sumka[i].first)] += f[a][b] * sumka[i].second;
            f[a][b] *= 1 - sumka[i].second;
        }
    }

    z[0] = 1;
    for (int i = 0; i < (int)priz.size(); ++i) {
        for (int j = 254; j >= 0; j--) {
            z[j+1] += z[j] * priz[i];
            z[j] *= 1 - priz[i];
        }
    }

    double ans = 0;

    for (int pz = 0; pz <= (int)priz.size(); ++pz)
        for (int sm = 0; sm <= (int)sumka.size(); ++sm)
            for (int ad = 0; ad <= 255; ++ad)
                if (pz + sm >= l)
                    if (ad + k >= pz)
                        ans += z[pz] * f[sm][ad];

    printf("%.10lf\n", ans);
}

int main() {
    solve();

    return 0;
}