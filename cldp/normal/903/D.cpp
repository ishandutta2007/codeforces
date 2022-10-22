#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> x[i];
    unsigned long long ans1 = 0, ans2 = 0;
    int temp = 1 - N;
    map<int, int> S;
    for (int i = 0; i < N; ++i) {
        if (temp > 0) ans1 += 1LL * temp * x[i]; else ans2 += -1LL * temp * x[i];
        temp += 2;
        ++S[x[i]];
        int cnt = 0;
        if (S.find(x[i] + 1) != S.end()) cnt += S[x[i] + 1];
        if (S.find(x[i] - 1) != S.end()) cnt -= S[x[i] - 1];
        if (cnt >= 0) ans1 += cnt; else ans2 += -cnt;
        if (ans1 > ans2) {
            ans1 -= ans2; 
            ans2 = 0;
        } else {
            ans2 -= ans1;
            ans1 = 0;
        }
    }
    if (ans1 >= ans2) cout << ans1 - ans2 << endl; else cout << "-" << ans2 - ans1 << endl;
    return 0;
}