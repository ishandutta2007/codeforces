#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 200;

int x[MAXN], y[MAXN];
bool z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) cin >> x[i];
    for (int i = 2; i <= M; ++i) {
        if (y[x[i - 1]] > 0 && x[i] % N != (x[i - 1] + y[x[i - 1]]) % N) {
            cout << -1 << endl;
            return 0;
        }
        y[x[i - 1]] = (x[i] + N - x[i - 1]) % N;
        if (y[x[i - 1]] == 0) y[x[i - 1]] = N;
    }
    for (int i = 1; i <= N; ++i) {
        if (y[i] == 0) continue;
        if (z[y[i]]) {
            cout << -1 << endl;
            return 0;
        }
        z[y[i]] = true;
    }

    int j = 1;
    for (int i = 1; i <= N; ++i) {
        if (y[i] == 0) {
            while (z[j]) ++j;
            y[i] = j;
            ++j;
        }
        cout << y[i] << " ";
    }
    cout << endl;

    return 0;
}