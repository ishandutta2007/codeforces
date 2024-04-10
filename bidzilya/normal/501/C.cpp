#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> degree(n), s(n);

    queue<int> q;
    vector<pair<int, int> > ans;

    for (int i = 0; i < n; ++i) {
        cin >> degree[i] >> s[i];
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (degree[v] != 1) {
            continue;
        }

        int u = s[v];

        ans.push_back(make_pair(v, u));
        --degree[u];
        s[u] ^= v;

        if (degree[u] == 1) {
            q.push(u);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    cout.flush();

    return 0;
}