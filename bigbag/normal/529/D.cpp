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

const int max_n = 44444, inf = 1111111111;

int n, m, t, a[max_n], w[max_n], e[max_n];
vector<pair<int, pair<int, int> > > v;
vector<int> ans;
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> t;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a[i] = ((s[0] - '0') * 10 + s[1] - '0') * 3600 + ((s[3] - '0') * 10 + s[4] - '0') * 60 + (s[6] - '0') * 10 + s[7] - '0';
        v.push_back(make_pair(a[i], make_pair(0, i)));
        v.push_back(make_pair(a[i] + t - 1, make_pair(1, i)));
    }
    sort(v.begin(), v.end());
    int MX = 0, cnt = 0, last = 0, mx = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].second.first == 0) {
            ++cnt;
        } else {
            if (e[ans[v[i].second.second]] == v[i].second.second) --cnt;
        }
        MX = max(MX, cnt);
        if (v[i].second.first == 0) {
            if (cnt <= m) {
                ++mx;
                ans.push_back(mx);
            } else {
                --cnt;
                pair<int, int> p = *q.rbegin();
                ans.push_back(p.second);
                q.erase(p);
                p.first = v[i].first;
                q.insert(p);
            }
            w[ans[v[i].second.second]] = v[i].first;
            e[ans[v[i].second.second]] = v[i].second.second;
        }
        if (v[i].second.first == 0) {
            q.insert(make_pair(v[i].first, ans.back()));
        } else {
            if (e[ans[v[i].second.second]] == v[i].second.second) {
                q.erase(make_pair(w[ans[v[i].second.second]], ans[v[i].second.second]));
            }
        }
    }
    if (MX < m) {
        cout << "No solution" << endl;
        return 0;
    }
    cout << mx << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}