#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int x[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int K = INF;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        if (x[i] < K) K = x[i];
    }
    vector<int> S;
    for (int i = 0; i < N; ++i) {
        if (x[i] == K) S.push_back(i);
    }
    int ans = N + 1;
    for (int i = 1; i < S.size(); ++i) ans = min(ans, (int)S[i] - S[i - 1]);
    cout << ans << endl;
    return 0;
}