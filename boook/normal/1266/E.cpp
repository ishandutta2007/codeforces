#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10
#define int long long

int n, m, x[maxn], c[maxn];
int sum = 0;
void Remove(int s, int t, int u) {
    if (c[u] <= x[u]) sum ++;
    c[u] --;
}
void Add(int s, int t, int u) {
    c[u] ++;
    if (c[u] <= x[u]) sum --;
}
int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i];

    for (int i = 1; i <= n; ++ i) sum += x[i];

    cin >> m;
    
    map<pair<int, int>, int> cc;
    while (m --) {
        int s, t, u;
        cin >> s >> t >> u;
        if (cc.find(make_pair(s, t)) != cc.end()) {
            Remove(s, t, cc[{s, t}]);
            cc.erase(make_pair(s, t));
        }
        if (u != 0) {
            Add(s, t, u);
            cc[{s, t}] = u;
        }
        cout << sum << endl;
    }
    return 0;
}