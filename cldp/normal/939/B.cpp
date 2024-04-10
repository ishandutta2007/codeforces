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
    long long N;
    int K;
    cin >> N >> K;

    long long ans1 = 0, ans2 = 0, ans3 = 1;
    for (int i = 0; i < K; ++i) {
        long long a;
        cin >> a;
        long long b = N / a;
        if (b * a > ans1 * ans2) {
            ans1 = a;
            ans2 = b;
            ans3 = i + 1;
        }
    }
    cout << ans3 << " " << ans2 << endl;
    return 0;
}