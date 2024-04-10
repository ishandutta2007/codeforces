#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 300010;
const int INF = 1000000007;
const double PI = acos(-1.0);


long long x[MAXN];
int y[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> x[i];
    set<pair<long long, int> > S;
    long long ans = 0, sum = 0;
    for (int i = 0; i < K; ++i) {
        S.insert(make_pair(x[i], i));
        sum += x[i];
        ans += sum;
    }
    for (int i = K; i < N; ++i) {
        S.insert(make_pair(x[i], i));
        set<pair<long long, int> >::iterator iter = S.end();
        --iter;
        sum -= iter->first;
        y[iter->second] = i;
        S.erase(iter);
        sum += x[i];
        ans += sum;
    }
    for (int i = 0; i < K; ++i) {
        set<pair<long long, int> >::iterator iter = S.end();
        --iter;
        sum -= iter->first;
        y[iter->second] = N + i;
        S.erase(iter);
        ans += sum;
    } 
    cout << ans << endl;
    for (int i = 0; i < N; ++i) cout << y[i] + 1 << " ";
    cout << endl;
    return 0;
}