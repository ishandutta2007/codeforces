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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x;
        cin >> n >> m >> x;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (int i = 1; i <= m; i++)
            pq.push({0, i});
        cout << "YES\n";
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            auto [hei, idx] = pq.top(); pq.pop();
            cout << idx << " \n"[i == n];
            pq.push({hei + a, idx});
        }
    }
}