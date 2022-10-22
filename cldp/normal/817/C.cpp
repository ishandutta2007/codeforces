#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);

long long count(long long S) {
    long long ans = 0;
    while (S > 0) {
        ans += S % 10;
        S /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    long long N, S;
    cin >> N >> S;
    long long SS = S;
    long long ans = 0;
    for (int i = 0; i < 10000; ++i) {
        if (S >= N) break;
        ++S;
        long long Q = count(S);
        if (S - Q >= SS) ++ans;
    }
    if (S > N) S = N;

    ans += N - S;
    cout << ans << endl;
    return 0;
}