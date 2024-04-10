#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010000;
const int INF = 1000000007;
const double PI = acos(-1.0);

int g[MAXN];
int sum[10][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i < 10; ++i) g[i] = i;
    for (int i = 10; i <= 1000000; ++i) {
        int a = i;
        while (a > 9) {
            int b = 1;
            while (a > 0) {
                if (a % 10 == 0) {
                    a /= 10;
                } else {    
                    b *= a % 10;
                    a /= 10;
                }
            }
            a = b;
        }
        g[i] = a;
    }
    for (int i = 1; i <= 1000000; ++i) {
        for (int j = 1; j < 10; ++j) sum[j][i] = sum[j][i - 1];
        ++sum[g[i]][i];
    }
    int N, a, b, c;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        cout << sum[c][b] - sum[c][a - 1] << endl;
    }
    return 0;
}