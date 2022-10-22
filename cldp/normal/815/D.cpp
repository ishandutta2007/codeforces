#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 500010;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<pair<int, int> > X[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, P, Q, R;
    cin >> N >> P >> Q >> R;
    for (int i = 0; i < N; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        X[a].push_back(make_pair(Q, c));
        X[a].push_back(make_pair(b, R));
        X[P].push_back(make_pair(b, c));
    }
    set<pair<int, int> > S;
    S.insert(make_pair(Q, 0));
    S.insert(make_pair(0, R + 1));
    long long ans = 0, cnt = 0;
    for (int i = P; i >= 1; --i) {
        for (int j = 0; j < X[i].size(); ++j) {
            pair<int, int> cur = X[i][j]; 
            auto it = S.lower_bound(make_pair(cur.first, -1));
            if (it->second >= cur.second) continue;
            while (true) {
                pair<int, int> tmp = *it;
                if (it->second > cur.second) break;
                --it;
                cnt += 1LL * (min(tmp.first, cur.first) - it->first) * (cur.second - tmp.second);
                if (tmp.first <= cur.first) S.erase(tmp);
            }
            S.insert(cur);
        }
        ans += 1LL * Q * R - cnt;
    }
    cout << ans << endl;

    return 0;
}