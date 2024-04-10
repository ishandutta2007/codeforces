#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3010;

typedef long long ll;

ll A[MAXN];
ll B[MAXN];
ll D[2][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        A[i] -= i;
        B[i] = A[i];
    }
    sort(B, B + n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            D[i&1][j] = D[(i&1)^1][j] + abs(B[j] - A[i]);
            if (j) D[i&1][j] = min(D[i&1][j], D[i&1][j - 1]);
        }
    }
    cout << D[(n-1)&1][n-1] << endl;
}