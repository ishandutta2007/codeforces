#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000010;
const int INF = 1000000007;

int x[MAXN], L[MAXN], R[MAXN];
stack<pair<int, int> > S;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x[i];
    S.push(make_pair(-1, 0));
    for (int i = 1; i <= N; ++i) {
        while (S.top().first > x[i]) S.pop();
        L[i] = S.top().second;
        S.push(make_pair(x[i], i));
    }
    S.push(make_pair(-1, N + 1));
    for (int i = N; i >= 1; --i) {
        while (S.top().first >= x[i]) S.pop();
        R[i] = S.top().second;
        S.push(make_pair(x[i], i));
    }
    long long ans1 = 0;
    for (int i = 1; i <= N; ++i) ans1 += 1LL * x[i] * (i - L[i]) * (R[i] - i);

  //  for (int i = 1; i <= N; ++i) cout << i << " " << L[i] << " " << R[i] << endl;
    //    cout << ans1 << endl;
    S.push(make_pair(INF, 0));
    for (int i = 1; i <= N; ++i) {
        while (S.top().first < x[i]) S.pop();
        L[i] = S.top().second;
        S.push(make_pair(x[i], i));
    }
    S.push(make_pair(INF, N + 1));
    for (int i = N; i >= 1; --i) {
        while (S.top().first <= x[i]) S.pop();
        R[i] = S.top().second;
        S.push(make_pair(x[i], i));
    }
    long long ans2 = 0;
    for (int i = 1; i <= N; ++i) ans2 += 1LL * x[i] * (i - L[i]) * (R[i] - i);
    cout << ans2 - ans1 << endl;

    return 0;
}