#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

bool z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    sort(x, x + 3);
    if (x[0] * x[1] + x[1] * x[2] + x[0] * x[2] < 1LL * x[0] * x[1] * x[2]) {
        cout << "NO" << endl;
        return 0;
    }

    for (int t = 0; t < x[0]; ++t) {
        memset(z, 0, sizeof(z));
        for (int i = 0; i < MAXN; i += x[0]) z[i] = true;
        for (int i = t; i < MAXN; i += x[1]) z[i] = true;
        int a = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (!z[i]) {
                a = i;
                break;
            }
        }
        for (int i = a; i < MAXN; i += x[2]) z[i] = true;
        bool flag = true;
        for (int i = 0; i < MAXN; ++i) flag &= z[i];
        if (flag) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}