#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
using namespace std;

const int MAXN = 101;
const int MAXM = 200001;
const int zero = 100000;
const int INF = 1000000000;

int A[MAXN], B[MAXN];
int f[MAXN][MAXM];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    for (int i = 0; i < n; ++i) {
        B[i] = A[i] - B[i] * k;
    }
    
    f[0][zero + B[0]] = A[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < MAXM; ++j) f[i][j] = f[i-1][j];
        for (int j = max(0, -B[i]); j < min(MAXM, MAXM-B[i]); ++j) {
            if (f[i-1][j] > 0 || j == zero)
                f[i][j+B[i]] = max(f[i-1][j+B[i]], f[i-1][j] + A[i]);
        }
    }
    
    if (f[n-1][zero] > 0) {
        cout << f[n-1][zero] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}