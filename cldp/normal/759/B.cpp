#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;
const int INF = 1000000009;
const double PI = acos(-1.0);

long long T[MAXN];
int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int A = 0, B = 0;
    long long TT = 0;
    T[0] = T[1] - 10000;
    for (int i = 1; i <= N; ++i) cin >> T[i];
    f[0] = 0;
    for (int i = 1; i <= N; ++i) {
        f[i] = f[i - 1] + 20;
        int j = lower_bound(T, T + i, T[i] - 89) - T;
      //  cout << " 1 -> " << j << endl;
        f[i] = min(f[i], f[j - 1] + 50);
        j = lower_bound(T, T + i, T[i] - 1439) - T;
       // cout << " 2 -> " << j << endl;
        f[i] = min(f[i], f[j - 1] + 120);
    }

    for (int i = 1; i <= N; ++i) {
        cout << f[i] - f[i - 1] << endl;
    }
    return 0;
}