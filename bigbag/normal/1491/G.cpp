/**
 *  created: 29/03/2021, 13:28:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

void proc(vector<pair<int, int>> &ans, vector<int> c1, vector<int> c2) {
    if (c1.size() < c2.size()) {
        c1.swap(c2);
    }
    if (c1.size() == 1) {
        return;
    }
    for (int i = 0; i < c2.size(); ++i) {
        ans.push_back({c1[c1.size() - c2.size() + i], c2[c2.size() - 1 - i]});
    }
    for (int i = 0; i <= c1.size() - c2.size(); ++i) {
        ans.push_back({c1[i], c2[0]});
    }
    for (int i = 1; i < c2.size(); ++i) {
        ans.push_back({c1[c1.size() - c2.size() + i], c2[c2.size() - i]});
    }
}

void proc_one(vector<pair<int, int>> &ans, vector<int> c) {
    if (c.size() == 3) {
        ans.push_back({c[0], c[1]});
        ans.push_back({c[1], c[2]});
        ans.push_back({c[0], c[2]});
        ans.push_back({c[0], c[1]});
    } else {
        ans.push_back({c[0], c[1]});
        ans.push_back({c[1], c[2]});
        ans.push_back({c[2], c[3]});
        ans.push_back({c[1], c[3]});
        for (int i = 4; i < c.size(); ++i) {
            ans.push_back({c[2], c[i]});
        }
        ans.push_back({c[0], c[2]});
    }
}

vector<pair<int, int>> solve(vector<int> v) {
    vector<vector<int>> cycles;
    vector<int> used(v.size());
    for (int i = 0; i < v.size(); ++i) {
        if (!used[i]) {
            int pos = i;
            vector<int> cycle;
            while (!used[pos]) {
                used[pos] = 1;
                cycle.push_back(pos);
                pos = v[pos];
            }
            if (cycle.size() > 1) {
                cycles.push_back(cycle);
            }
        }
    }
    vector<pair<int, int>> ans;
    while (cycles.size() >= 2) {
        proc(ans, cycles.back(), cycles[cycles.size() - 2]);
        cycles.pop_back();
        cycles.pop_back();
    }
    if (cycles.size() == 1) {
        if (cycles[0].size() == 2) {
            int pos = -1;
            for (int i = 0; i < v.size(); ++i) {
                if (i != cycles[0][0] && i != cycles[0][1]) {
                    pos = i;
                    break;
                }
            }
            proc(ans, {pos}, cycles[0]);
        } else {
            proc_one(ans, cycles[0]);
        }
    }
    auto cv = v;
    for (auto p : ans) {
        swap(v[p.first], v[p.second]);
    }
    for (int i = 0; i < v.size(); ++i) {
        assert(v[i] == i);
    }
    return ans;
}

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    auto ans = solve({a, a + n});
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
    return 0;
}