#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN], y[MAXN], S[MAXN];
int cz[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        y[i] = x[i];
        S[i] = -1;
    }
    sort(y, y + N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (cz[j] || x[i] != y[j]) continue;
            cz[j] = true;
            S[i] = j;
            break;
        }
    }

    int z[MAXN];
    int k = 0;
    while (k < N && y[k] == y[0]) ++k;
    for (int i = k; i < N; ++i) z[i - k] = y[i];
    for (int i = 0; i < k; ++i) z[N - k + i] = y[i];

    bool flag = true;
    for (int i = 1; i < (1 << N) - 1; ++i) {
        long long A = 0, B = 0;
        for (int j = 0; j < N; ++j) {
            if ((1 << j) & i) {
                A += y[j];
                B += z[j];
            }
        }
        if (A == B) {
            flag = false;
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < N; ++i) cout << z[S[i]] << " ";
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}