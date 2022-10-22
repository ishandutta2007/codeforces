#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<pair<int, long long> > x[MAXN];
long long ans[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        x[a].push_back(make_pair(b, c));
        x[b].push_back(make_pair(a, c));
    }
    set<pair<long long, int> > S;
    for (int i = 1; i <= N; ++i) {
        cin >> ans[i];
        S.insert(make_pair(ans[i], i));
    }
    while (!S.empty()) {
        long long D = S.begin()->first;
        int a = S.begin()->second;
        S.erase(S.begin());
        if (D > ans[a]) continue;
        for (int i = 0; i < x[a].size(); ++i) {
            if (D + x[a][i].second * 2 >= ans[x[a][i].first]) continue;
            S.insert(make_pair(D + x[a][i].second * 2, x[a][i].first));
            ans[x[a][i].first] = D + x[a][i].second * 2;
        }
    }
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}