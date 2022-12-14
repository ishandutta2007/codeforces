#include <bits/stdc++.h>

using namespace std;

int A[200005];
int S[200005];
int _I[400010];
int * I = _I + 200005;
int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= 2 * n; i++) {
            scanf("%d", &A[i]);
            S[i] = S[i - 1] + (A[i] * 2 - 3);
        }
        for (int i = -2 * n; i <= 2 * n; i++) I[i] = -1;
        for (int i = n; i <= 2 * n; i++) {
            if (I[S[i]] == -1) I[S[i]] = i;
        }
        int ans = 1e9;
        for (int i = 0; i <= n; i++) {
            int j = S[i] + S[2 * n];
            if (-2 * n <= j && j <= 2 * n && I[j] != -1) {
                ans = min(ans, I[j] - i);
            }
        }
        printf("%d\n", ans);
    }
}