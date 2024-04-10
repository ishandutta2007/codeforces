#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    string Q;
    cin >> Q;
    int N = Q.size();
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int up = 0, lo = 0;
        for (int j = i; j < N; ++j) {
            if (Q[j] == '(') {
                ++up;
                ++lo;
            }
            if (Q[j] == '?') {
                ++up;
                --lo;
                if (lo < 0) lo += 2;
            }
            if (Q[j] == ')') {
                --up;
                --lo;
                if (lo < 0) lo += 2;
            }
            if (up < 0) break;
            if (up & 1) continue;
            if (lo == 0) ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}