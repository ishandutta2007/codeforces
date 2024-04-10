#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];
int f[MAXN][MAXN];

int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        f[i][i] = x[i];
    }
    bool one = false;
    for (int i = 0; i < N; ++i) {
        if (x[i] == 1) {
            one = true;
        }
    }
    if (one) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) cnt += x[i] != 1;
        cout << cnt << endl;
        return 0;
    }

    int L = -1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j + i < N; ++j) {
            f[j][j + i] = gcd(x[j], f[j + 1][j + i]);
            if (f[j][j + i] == 1) {
                L = i;
                break;
            }
        }
        if (L != -1) break;
    }

    if (L == -1) {
        cout << L << endl;
        return 0;
    }

    cout << L + N - 1 << endl;
    return 0;
}