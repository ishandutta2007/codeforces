#include <bits/stdc++.h>
using namespace std;
#define maxn 100090

int t, n, x[maxn][3], u[maxn], ba[maxn];
queue<pair<int, int>> qu;
vector<int> sec;

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        
        cin >> n;
        for (int i = 1; i <= n - 2; ++ i)
            cin >> x[i][0] >> x[i][1] >> x[i][2];
        map<pair<int, int>, vector<int>> cc;
        
        for (int i = 1; i <= n + 10; ++ i) u[i] = 0, ba[i] = 0;

        int ok = 0;
        for (int i = 1; i <= n - 2; ++ i) {
            sort(x[i], x[i] + 3);
            if (ok == 0) {
                ok = 1;
                ba[x[i][0]] = x[i][1];
                ba[x[i][1]] = x[i][2];
                ba[x[i][2]] = x[i][0];
                sec.emplace_back(i);
                qu.push(make_pair(x[i][0], x[i][1]));
                qu.push(make_pair(x[i][1], x[i][2]));
                qu.push(make_pair(x[i][2], x[i][0]));
            }
            else {
                cc[make_pair(x[i][0], x[i][1])].emplace_back(i);
                cc[make_pair(x[i][1], x[i][2])].emplace_back(i);
                cc[make_pair(x[i][0], x[i][2])].emplace_back(i);
            }
        }

        while (qu.size()) {
            pair<int, int> now = qu.front(); qu.pop();
            pair<int, int> ord = make_pair(min(now.first, now.second), max(now.first, now.second));
        
            if (cc.find(ord) != cc.end()) {
                while (cc[ord].size() && u[cc[ord].back()] == 1) cc[ord].pop_back();
                if (cc[ord].size() == 0) cc.erase(ord);
                else {
                    int idx = cc[ord].back(), three = x[idx][0] ^ x[idx][1] ^ x[idx][2] ^ now.first ^ now.second;
                    u[idx] = 1;
                    sec.emplace_back(idx);
                    qu.push(make_pair(now.first, three));
                    qu.push(make_pair(three, now.second));
                    ba[three] = ba[now.first];
                    ba[now.first] = three;
                }
            }
        }
        
        int point = 1;
        for (int i = 1; i <= n; ++ i)
            cout << point << " \n"[i == n], point = ba[point];
        for (int i = int(sec.size()) - 1; i >= 0; -- i)
            cout << sec[i] << " \n"[i == 0];
        
        sec.clear();
    }
    return 0;
}