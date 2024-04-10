#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int f[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    string P;
    cin >> P;
    P = "a" + P;
    for (int i = P.size() - 1; i >= 0; --i) {
        if (P[i] == 'a') f[i] = f[i + 1] + 1; else f[i] = f[i + 1];
    }
    int ans = 0;
    int A = 0;
    for (int i = 0; i < P.size(); ++i) {
        if (P[i] == 'a') ++A;
        ans = max(ans, A);
        int B = 0;
        for (int j = i + 1; j < P.size(); ++j) {
            if (P[j] == 'b') ++B;
            ans = max(ans, A + B + f[j + 1]);
        }
    }
    cout << ans - 1 << endl;


    return 0;
}