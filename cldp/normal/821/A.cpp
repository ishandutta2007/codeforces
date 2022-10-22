#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> x[i][j];
        }
    }
    bool ans = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (x[i][j] == 1) continue;

            bool flag = false;
            for (int k = 0; k < N; ++k) {
                for (int l = 0; l < N; ++l) {
                    if (x[k][j] + x[i][l] == x[i][j]) flag = true;
                }
            }
            ans = ans && flag;
        }
    }
    if (ans) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}