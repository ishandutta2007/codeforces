#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int MAXN = 2001;
const long long inf = 2000000000000000000;
const double PI = 3.141592653589793;

struct edge {
    int from, to;
    int used;
    int gt;
};

vector<edge> ed;
vector<int> st;
vector<int> val;
vector<int> it;
vector<vector<int> > tr;

vector<int> ans;

void dfs(int v) {
    for (; it[v] < tr[v].size();) {
        ++it[v];
        if (!ed[tr[v][it[v] - 1]].used) {
            int i = tr[v][it[v] - 1];
            ed[i].used = true;
            ed[i ^ 1].used = true;
            dfs(ed[i].to);
            if (val[ed[i].to] % 2 != st[ed[i].to]) {
                ed[i].gt = 1;
                ed[1 ^ i].gt = 1;
                ++val[ed[i].to];
                ++val[ed[i].from];
                ans.push_back(i / 2);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    ed.resize(2 * m);
    st.resize(n);
    val.resize(n, 0);
    it.resize(n, 0);
    tr.resize(n);
    int cnt = 0;
    int pos = -1;
    for (int i = 0; i < n; ++i) {
        cin >> st[i];
        if (st[i] == 1) {
            cnt++;
        }
        if (st[i] == -1)
            pos = i;
    }
    if (cnt % 2 == 1) {
        if (pos == -1) {
            cout << -1 << endl;
            return;
        } else {
            st[pos] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (st[i] == -1)
            st[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ed[2 * i].from = a;
        ed[2 * i].to = b;
        ed[2 * i].used = false;
        ed[2 * i].gt = 0;
        ed[2 * i + 1].to = a;
        ed[2 * i + 1].from = b;
        ed[2 * i + 1].used = false;
        ed[2 * i + 1].gt = 0;
        tr[a].push_back(2 * i);
        tr[b].push_back(2 * i + 1);
    }
    dfs(0);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
}


int main() {
    cout.precision(20);
    cin.tie(0);
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}