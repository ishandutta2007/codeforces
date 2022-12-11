#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef priority_queue<pi> pqi;

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    pqi Q;
    vpi V(m);
    for (int i = 0; i < m; ++i) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());
    V.push_back(pi(d, 0));
    Q.push(pi(0,0));
    ll res = 0;
    ll lastdist = 0;
    for (int i = 0; i <= m; ++i) {
        ll nextdist = V[i].first;
        while (lastdist < nextdist) {
            if (Q.empty()) {
                cout << -1 << endl;
                return 0;
            }
            if (Q.top().second + n > lastdist and Q.top().second + n <= nextdist) {
                res -= (Q.top().second + n - lastdist)*Q.top().first;
                lastdist = Q.top().second + n;
                Q.pop();
            }
            else if (Q.top().second + n > lastdist) {
                res -= (nextdist - lastdist)*Q.top().first;
                lastdist = nextdist;
            }
            else Q.pop();
        }
        Q.push(pi(-V[i].second, V[i].first));
    }
    cout << res << endl;
}