#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long x[MAXN], sum[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, D, B;
    cin >> N >> D >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> x[i];
        sum[i] = sum[i - 1] + x[i];
    }
    int S = 1, T = N;
    int P = 0, Q = N;
    long long sumS = sum[P + D + 1] - sum[P];
    long long sumT = sum[Q] - sum[Q - D - 1];
    P += D + 1;
    Q -= D + 1;
    int cntS = 0, cntT = 0;
    for (int i = 0; i <= N / 2; ++i) {
        if (sumS >= B) sumS -= B; else ++cntS;
        if (sumT >= B) sumT -= B; else ++cntT;
        int R = min(N, P + D + 1);
        sumS += sum[R] - sum[P];
        P = R;
        int L = max(0, Q - D - 1);
        sumT += sum[Q] - sum[L];
        Q = L;
    }
    cout << max(cntS, cntT) << endl;

    return 0;
}