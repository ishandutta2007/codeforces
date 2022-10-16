#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> b(n); for (int i = 0; i < n; ++i) cin >> b[i];
    
    vector<long long> P(n + 1);
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < l; ++i)
            P[l] += a[i] * b[i];
    }
    vector<long long> S(n + 1);
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < l; ++i)
            S[l] += a[n - 1 - i] * b[n - 1 - i];
    }
    
    long long result = P[n];
    
    vector< vector<long long> > f(n, vector<long long>(n));
    for (int i = 0; i < n; ++i) f[i][i] = a[i] * b[i];
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i + l <= n; ++i) {
            f[i][i + l - 1] = 
                a[i] * b[i + l - 1] + a[i + l - 1] * b[i] + 
                f[i + 1][i + l - 2];
            result = max(result, P[i] + f[i][i + l - 1] + S[n - i - l]);
        }
    }
    
    cout << result << endl;
    return 0;
}