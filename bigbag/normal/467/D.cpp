#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 100001, inf = 1111111111;

int get_r(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'r') {
            ++res;
        }
    }
    return res;
}

void norm(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
}

int n, m, cnt, a[max_n], r[6 * max_n], f[6 * max_n], len[6 * max_n], nums[max_n];
int used[6 * max_n], num2[6 * max_n], r2[6 * max_n], len2[6 * max_n];
pair<int, int> dp[6 * max_n];
string s, s1, s2;
map<string, int> num;
vector<int> g[6 * max_n], gt[6 * max_n], g2[6 * max_n], order, comp;

void dfs1(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            dfs1(g[v][i]);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    used[v] = 1;
    comp.push_back(v);
    for (int i = 0; i < gt[v].size(); ++i) {
        if (used[gt[v][i]] == 0) {
            dfs2(gt[v][i]);
        }
    }
}

pair<int, int> get_dp(int v) {
    //cout << v << endl;
    if (f[v]) {
        return dp[v];
    }
    pair<int, int> res(r2[v], len2[v]);
    for (int i = 0; i < g2[v].size(); ++i) {
        res = min(res, get_dp(g2[v][i]));
    }
    f[v] = 1;
    dp[v] = res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        norm(s);
        if (!num.count(s)) {
            num[s] = cnt;
            len[cnt] = s.length();
            r[cnt] = get_r(s);
            ++cnt;
        }
         nums[i] = num[s];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s1 >> s2;
        norm(s1);
        norm(s2);
        if (!num.count(s1)) {
            num[s1] = cnt;
            len[cnt] = s1.length();
            r[cnt] = get_r(s1);
            ++cnt;
        }
        if (!num.count(s2)) {
            num[s2] = cnt;
            len[cnt] = s2.length();
            r[cnt] = get_r(s2);
            ++cnt;
        }
        g[num[s1]].push_back(num[s2]);
        gt[num[s2]].push_back(num[s1]);
    }
    for (int i = 0; i < cnt; ++i) {
        if (used[i] == 0) {
            dfs1(i);
        }
    }
    memset(used, 0, sizeof(used));
    cnt = 0;
    int kkk = order.size();
    for (int i = order.size() - 1; i >= 0; --i) {
        if (used[order[i]] == 0) {
            comp.clear();
            dfs2(order[i]);
            r2[cnt] = inf;
            len2[cnt] = inf;
            for (int j = 0; j < comp.size(); ++j) {
                int v = comp[j];
                num2[v] = cnt;
                if ((r2[cnt] > r[v]) || (r2[cnt] == r[v] && len2[cnt] > len[v])) {
                    r2[cnt] = r[v];
                    len2[cnt] = len[v];
                }
            }
            ++cnt;
        }
    }
    for (int i = 0; i < kkk; ++i) {
        for (int k = 0; k < g[i].size(); ++k) {
            if (num2[i] != num2[g[i][k]]) {
                g2[num2[i]].push_back(num2[g[i][k]]);
            }
        }
    }
    long long ans1 = 0, ans2 = 0;
    for (int i = 0; i < n; ++i) {
        pair<int, int> p = get_dp(num2[nums[i]]);
        //cout << p.first << " " << p.second << endl;
        ans1 += p.first;
        ans2 += p.second;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}