#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 3e5 + 5;
int a[MAXn];
int b[MAXn];

int dis[MAXn][2]; // 0 = before slip, 1 = after slip
pii pi[MAXn][2];
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 0; i <= n; i++)
        dis[i][0] = dis[i][1] = INF;

    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(st.end(), i);

    dis[n][0] = dis[n][1] = 0;
    deque<pii> dq;
    dq.push_back({n, 1});
    while (SZ(dq)) {
        auto [x, tp] = dq.front(); dq.pop_front();
        if (x == 0) {
            cout << dis[0][0] << endl;
            pii now = {0, 0};
            vector<int> his;
            while (now.X != n) {
                if (now.Y == 0)
                    his.pb(now.X);
                now = pi[now.X][now.Y];
            }
            reverse(ALL(his));
            for (ll x : his)
                cout << x << " ";
            cout << endl;
            return 0;
        }
        if (tp == 0) {
            int y = x + b[x];
            if (dis[y][1] > dis[x][tp])
                dis[y][1] = dis[x][tp], dq.push_front({y, 1}), pi[y][1] = {x, tp};
        }
        else {
            while (1) {
                auto it = st.lower_bound(x - a[x]);
                if (it == st.end() || (*it) > x)
                    break;
                int y = *it;
                st.erase(it);
                if (dis[y][0] > dis[x][tp] + 1)
                    dis[y][0] = dis[x][tp] + 1, dq.push_back({y, 0}), pi[y][0] = {x, tp};
            }
        }
    }
    cout << -1 << endl;
}