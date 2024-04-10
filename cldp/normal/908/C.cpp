#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-8;

double x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    double R;
    cin >> N >> R;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        y[i] = R;
        for (int j = 0; j < i; ++j) {
            if (fabs(x[i] - x[j]) < R + R + EPS) {
                double D = fabs(x[i] - x[j]);
                y[i] = max(y[i], y[j] + sqrt(4 * R * R - D * D));
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << setprecision(9) << fixed << y[i] << " ";
    }
    cout << endl;
    return 0;
}