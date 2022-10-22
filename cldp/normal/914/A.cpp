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
    int N;
    cin >> N;
    int ans = -10000000;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a < 0) {
            ans = max(ans, a);
            continue;
        }
        int b = sqrt(a);
        if (a == b * b) continue;
        --b;
        if (a == b * b) continue;
        b += 2;
        if (a == b * b) continue;
        ans = max(ans, a);
    }
    cout << ans << endl;
    return 0;
}