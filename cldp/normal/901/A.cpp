#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i <= N; ++i) cin >> x[i];

    bool flag = false;
    for (int i = 0; i < N; ++i) {
        if (x[i] != 1 && x[i + 1] != 1) flag = true;
    }
    if (!flag) {
        cout << "perfect" << endl;
        return 0;
    }

    cout << "ambiguous" << endl;
    int M = 2;
    y[0] = 1;
    cout << 0;
    for (int i = 1; i <= N; ++i) {
        y[i] = M;
        for (int j = 0; j < x[i]; ++j) {
            cout << " " << y[i - 1];
            ++M;
        }
    }
    cout << endl;

    y[0] = 1;
    M = 2;
    cout << 0;
    flag = false;
    for (int i = 1; i <= N; ++i) {
        y[i] = M;
        if (!flag && x[i - 1] != 1 && x[i] != 1) {
            cout << " " << y[i - 1] << " " << y[i - 1] + 1;
            M += 2;
            for (int j = 2; j < x[i]; ++j) {
                cout << " " << y[i - 1];
                ++M;
            }
        } else {
            for (int j = 0; j < x[i]; ++j) {
                cout << " " << y[i - 1];
                ++M;
            }
        }
    }
    cout << endl;

    return 0;
}