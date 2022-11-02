#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10
#define PII pair<int, int>
#define int long long
int n, m, x[maxn];

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> x[i];
    map<int, int> cc;
    for (int i = 1; i <= n; ++ i) cc[x[i]] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> pq;

    for (int i = 1; i <= n; ++ i) {
        if (cc[x[i] - 1] == 0) pq.push(make_pair(1, x[i] - 1));
        if (cc[x[i] + 1] == 0) pq.push(make_pair(1, x[i] + 1));
    }
    long long sum = 0;
    vector<int> ans;
    while (pq.size()) {
        PII now = pq.top(); pq.pop();
        int pos = now.second;
        if (cc[pos] == 0) {
            sum += now.first;
            cc[pos] = 1, ans.emplace_back(pos);
            if (cc[pos + 1] == 0)
                pq.push(make_pair(now.first + 1, pos + 1));
            if (cc[pos - 1] == 0)
                pq.push(make_pair(now.first + 1, pos - 1));

        }
        if (ans.size() == m) break;
    }
    cout << sum << endl;
    for (auto to : ans) cout << to << " " ; cout << endl;
    return 0;
}