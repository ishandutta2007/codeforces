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
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for (int i = 1; i <= A + B; ++i) {
        if (A / i + B / i >= N) ans = i;
    }
    ans = min(ans, min(A, B));
    cout << ans << endl;
    return 0;
}