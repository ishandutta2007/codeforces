#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26000;
int xx[MAXN];
int yy[MAXN];

int dx[MAXN];
int dy[MAXN];

int ss[MAXN];
double norm_d[MAXN];



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> xx[i] >> yy[i] >> dx[i] >> dy[i] >> ss[i];
        int g = __gcd(dx[i], dy[i]);
        g = llabs(g);
        dx[i] /= g;
        dy[i] /= g;
        norm_d[i] = sqrt(dx[i]*dx[i] + dy[i]*dy[i]);
    }

    double res = 1e18;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int x = xx[i] - xx[j], y = yy[i] - yy[j];
            int det = dx[i]*dy[j] - dx[j]*dy[i];
            if (det == 0) {
                int lambda = x / dx[i];
                if (x != lambda * dx[i] or y != lambda * dy[i]) continue;
                int v = 0;
                if ((x > 0) != (dx[i] > 0)) v += ss[i];
                if ((x > 0) == (dx[j] > 0)) v += ss[j];
                if (v == 0) continue;
                if (lambda < 0) lambda = -lambda;
                res = min(res, (lambda * norm_d[i])/v);
            } else {
                int a = - x * dy[j] + y * dx[j];
                int b = dx[i] * y - dy[i] * x;
                if (a != 0 and (a > 0) != (det > 0)) continue;
                if (b != 0 and (b > 0) != (det > 0)) continue;
                double ris = max((a*norm_d[i]) / (ss[i]*det), (b*norm_d[j]) / (ss[j]*det));
                res = min(res, ris);
            }
        }
    }
    cout.precision(10);
    if (res > 1e17) cout << "No show :(\n";
    else cout << fixed << res << "\n";
}