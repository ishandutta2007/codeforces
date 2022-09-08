#include <bits/stdc++.h>

using namespace std;

const int max_n = 500555, inf = 1000111222;

int n, ans[2 * max_n], h[max_n], hup[max_n];
vector<int> g[max_n];

void dfs(int v, int p) {
    h[v] = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        h[v] = max(h[v], h[to] + 1);
    }
}

void dfs2(int v, int p) {
    if (p != -1) {
        hup[v] = max(hup[v], hup[p] + 1);
        //cout << v << ": " << hup[v] << endl;
    }
    int mxh = 0, mxh2 = 0;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        if (mxh < h[to] + 1) {
            mxh2 = mxh;
            mxh = h[to] + 1;
        } else if (mxh2 < h[to] + 1) {
            mxh2 = h[to] + 1;
        }
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        hup[to] = mxh;
        if (h[to] + 1 == mxh) {
            hup[to] = mxh2;
        }
        ++hup[to];
        dfs2(to, v);
    }
}

vector<int> allh;
vector<pair<int, int>> diff[max_n];

void dfs3(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs3(to, v);
    }
    allh.clear();
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        allh.push_back(h[to] + 1);
    }
    if (p != -1) {
        allh.push_back(hup[v]);
    }
    sort(allh.begin(), allh.end());
    reverse(allh.begin(), allh.end());
    for (int i = 0; i < allh.size(); ++i) {
        int h = allh[i];
        int pos = h * 2 - 1;
        int val = i + 1;
        ans[pos + 1] = max(ans[pos + 1], val); // even
        if (i + 1 < allh.size() && allh[i + 1] >= allh[i] - 1) {
            ++val;
        }
        /*if (v == 2) {
            cout << pos << " " << val << "$" << endl;
        }*/
        ans[pos] = max(ans[pos], val);
        if (i + 1 < allh.size() && allh[i] > allh[i + 1]) {
            int pos = (allh[i + 1] + 1) * 2 - 1;
            int val = i + 2;
            ans[pos] = max(ans[pos], val);
        }
    }
    for (int i = 0; i < allh.size(); ) {
        int pos = i;
        while (i < allh.size() && allh[pos] == allh[i]) {
            ++i;
        }
        diff[v].push_back({allh[pos], i - pos});
    }
}

void dfs4(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs4(to, v);
    }
    if (p == -1) {
        return;
    }
    allh.clear();
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        allh.push_back(h[to] + 1);
    }
    sort(allh.begin(), allh.end());
    reverse(allh.begin(), allh.end());
    int del = h[v] + 1;

    int pos1 = -1, pos2 = -1, cnt = 0, h = inf;
    while (pos1 + 1 < allh.size() || pos2 + 1 < diff[p].size()) {
        if (pos1 + 1 == allh.size()) {
            ++pos2;
            cnt += diff[p][pos2].second;
            h = diff[p][pos2].first;
            cnt -= (h == del);
        } else if (pos2 + 1 == diff[p].size()) {
            ++pos1;
            h = allh[pos1];
        } else if (allh[pos1 + 1] > diff[p][pos2 + 1].first) {
            ++pos1;
            h = allh[pos1];
        } else {
            ++pos2;
            cnt += diff[p][pos2].second;
            h = diff[p][pos2].first;
            cnt -= (h == del);
        }
        //cout << v + 1 << ": " << h << ", val = " << cnt + pos1 + 1 << "   " << cnt << " " << pos1 << endl;
        ans[h * 2] = max(ans[h * 2], cnt + pos1 + 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        ans[1] = max(ans[1], (int) g[i].size() + 1);
    }
    dfs(0, -1);
    dfs2(0, -1);
    dfs3(0, -1);
    dfs4(0, -1);
    for (int i = n - 2; i >= 1; --i) {
        ans[i] = max(ans[i], ans[i + 2]);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    puts("");
    return 0;
}