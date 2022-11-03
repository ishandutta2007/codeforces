#include <bits/stdc++.h>
using namespace std;

const double kEps = 1e-9;

int n, m, k;
vector<bool> occ;
vector<vector<int> > g;
vector<bool> cur_ans;
vector<bool> ans;
vector<int> dels;
double ans_value = -1.0;
vector<int> cur_connected;

void Check()
{
    cur_ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cur_ans[i] = !occ[i];
    }
    cur_connected.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        if (cur_ans[i]) {
            for (int j = 0; j < (int) g[i].size(); ++j) {
                int u = g[i][j];
                if (cur_ans[u]) {
                    ++cur_connected[i];
                }
            }
        }
    }

    set<pair<double, int> > q;
    for (int i = 0; i < n; ++i) {
        if (cur_ans[i]) {
            q.insert(make_pair(1.0 * cur_connected[i] / g[i].size(), i));
        }
    }
    while (!q.empty()) {
        const auto& itr = q.begin();
        double cur_d = (*itr).first;
        int v = (*itr).second;

        q.erase(itr);

        double real_d = 1.0 * cur_connected[v] / g[v].size();

        if (abs(real_d - cur_d) > kEps) {
            continue;
        }

        if (ans_value < 0 || cur_d > ans_value) {
            ans_value = cur_d;
            while (!dels.empty()) {
                ans[dels.back()] = false;
                dels.pop_back();
            }
        }

        dels.push_back(v);
        cur_ans[v] = false;
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];

            if (cur_ans[u]) {
                double prev_d = 1.0 * cur_connected[u] / g[u].size();
                --cur_connected[u];
                double new_d = 1.0 * cur_connected[u] / g[u].size();
                q.insert(make_pair(new_d, u));
            }
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    occ.assign(n, false);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        --x;
        occ[x] = true;
    }
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = !occ[i];
    }
    Check();

    vector<int> gans;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            gans.push_back(i);
        }
    }

    cout << gans.size() << endl;
    for (int i = 0; i < (int) gans.size(); ++i) {
        cout << gans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}