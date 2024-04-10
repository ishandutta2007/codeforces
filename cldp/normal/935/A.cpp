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
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        if (N % (i + 1) == 0) ++ans;
    }
    cout << ans << endl;
    return 0;
}