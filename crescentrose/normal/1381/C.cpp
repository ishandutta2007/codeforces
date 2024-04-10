#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 10;
int n, cnt_x, cnt_y;
int T, sp;
int ans[N];
vector<int> g[N];

#include <assert.h>
int main() {
    scanf("%d", &T);
    while (T -- ) {
        scanf("%d %d %d", &n, &cnt_x, &cnt_y);
        for (int i = 1; i <= n; i ++) {
            int x;
            scanf("%d", &x);
            g[x].push_back(i);
        }
        priority_queue<pair<int, int> > q;
        for (int i = 1; i <= n + 1; i ++)
            if (!g[i].size()) sp = i;
            else {
                q.push({g[i].size(), i});
            }
        for (int i = 1; i <= n; i ++)
            ans[i] = sp;
        cnt_y -= cnt_x;
        while (cnt_x --) {
            auto u = q.top();
            q.pop();
            ans[g[u.second][g[u.second].size() - 1]] = u.second;
            g[u.second].pop_back();
            u.first --;
            if (u.first)
                q.push(u);
        }
        vector<pair<pair<int, int>, pair<int, int> > > d;
        vector<pair<int, int> > tri;
        while (q.size() > 1) {
            auto u = q.top();
            q.pop();
            auto v = q.top();
            q.pop();
            d.push_back({{g[u.second][u.first - 1], u.second},
                         {g[v.second][v.first - 1], v.second}});
            g[u.second].pop_back();
            g[v.second].pop_back();
            u.first--;
            v.first--;
            if (u.first) q.push(u);
            if (v.first) q.push(v);
        }
        if (q.size() && d.size()) {
            auto u = q.top();
            for (int i = 0; i < d.size(); i ++)
                if (d[i].first.second != u.second && d[i].second.second != u.second) {
                    tri.push_back(d[i].first);
                    tri.push_back(d[i].second);
                    tri.push_back({g[u.second][u.first - 1], u.second});
                    swap(d[i], d[d.size() - 1]);
                    d.pop_back();
                    break;
                }
        }
        int mxsum = d.size() * 2 + tri.size();
        if (mxsum < cnt_y) {
            puts("NO");
            for (int i = 1; i <= n + 1; i ++)
                g[i].clear();
            continue;
        }
        if (cnt_y == 1) {
            if (d.size())
            {
                ans[d[0].first.first] = d[0].second.second;
            } else {
                ans[tri[0].first] = tri[1].second;
            }
        } else {
            if (cnt_y & 1) {
                if (tri.empty()) {
                    auto u = d[d.size() - 1];
                    d.pop_back();
                    for (int i = 0; i < d.size(); i ++) {
                        if (d[i].first.second != u.first.second && d[i].first.second != u.second.second) {
                            tri.push_back(u.first);
                            tri.push_back(u.second);
                            tri.push_back(d[i].first);
                            swap(d[i], d[d.size() - 1]);
                            ans[tri[0].first] = tri[1].second;
                            ans[tri[1].first] = tri[2].second;
                            ans[tri[2].first] = tri[0].second;
                            d.pop_back();
                            break;
                        }
                        if (d[i].second.second != u.first.second && d[i].second.second != u.second.second) {
                            tri.push_back(u.first);
                            tri.push_back(u.second);
                            tri.push_back(d[i].second);
                            ans[tri[0].first] = tri[1].second;
                            ans[tri[1].first] = tri[2].second;
                            ans[tri[2].first] = tri[0].second;
                            swap(d[i], d[d.size() - 1]);
                            d.pop_back();
                            break;
                        }
                        ans[d[i].first.first] = d[i].second.second;
                        ans[d[i].second.first] = d[i].first.second;
                        ans[u.second.first] = u.first.second;
                        swap(d[i], d[d.size() - 1]);
                        d.pop_back();
                        break;
                    }
                } else {
                    ans[tri[0].first] = tri[1].second;
                    ans[tri[1].first] = tri[2].second;
                    ans[tri[2].first] = tri[0].second;
                }
                cnt_y -= 3;
            }
            for (auto u:d)
                if (cnt_y) {
                    cnt_y -= 2;
                    ans[u.first.first] = u.second.second;
                    ans[u.second.first] = u.first.second;
                }
            if (cnt_y) {
                assert(cnt_y == 2);
                ans[tri[0].first] = tri[1].second;
                ans[tri[1].first] = tri[0].second;
            }
        }
        puts("YES");
        for (int i = 1; i <= n ; i ++)
            printf("%d%c", ans[i], " \n"[i == n]);
        for (int i = 1; i <= n + 1; i ++)
            g[i].clear();
    }
    return 0;
}