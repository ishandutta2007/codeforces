#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 200010;

long long A[MAXN];
long long f[MAXN][20], g[MAXN][20], h[MAXN][20];
vector<int> X[MAXN];
int Q[MAXN];
bool Z[MAXN];
long long ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 2; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        f[i][0] = a;
        g[i][0] = b;
        X[a].push_back(i);
    }
       
    f[1][0] = 1;
    for (int i = 1; i < 20; ++i) {
        for (int j = 1; j <= N; ++j) {
            f[j][i] = f[f[j][i - 1]][i - 1];
            g[j][i] = g[j][i - 1] + g[f[j][i - 1]][i - 1];
        }
    }
    
    for (int k = 1; k <= N; ++k) {
        long long temp = A[k];
        int j = k;
        while (temp > 0 && j != 1) {
            bool flag = true;
            for (int i = 19; i >= 0; --i) {
                if (g[j][i] <= temp) {
                    ++h[j][i];
                    temp -= g[j][i];
                    j = f[j][i];
                    flag = false;
                    break;
                }
            }
            if (flag) break;
        }
    }
    
    int L = 0, R = 1;
    Q[0] = 1;
    Z[1] = true;
    while (L < N) {
        int a = Q[L];
        ++L;
        for (int i = 0; i < X[a].size(); ++i) {
            if (Z[X[a][i]]) continue;
            Q[R] = X[a][i];
            Z[X[a][i]] = true;
            ++R;
        }
    }
    
    for (int i = N - 1; i >= 0; --i) {
        int a = Q[i];
        for (int j = 0; j < 20; ++j) {
            ans[f[a][0]] += h[a][j];
            int b = f[a][0];
            for (int k = j - 1; k >= 0; --k) {
                if (b == 1) break;
                h[b][k] += h[a][j];
                b = f[b][k];
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}