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
    int N, K;
    cin >> N >> K;
    int ans = INF;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (K % a == 0) ans = min(ans, K / a);
    }
    cout << ans << endl;
    
    return 0;
}