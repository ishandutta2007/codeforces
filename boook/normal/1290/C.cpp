/*input
19 5
1001001001100000110
2
2 3
2
5 6
2
8 9
5
12 13 14 15 16
1
19
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 900000 + 10

set<int> cc[maxn];

vector<int> v[maxn];
int n, k, x[maxn], cost[maxn];
string s;

struct djs{
    int x[maxn];
    void init(){ for (int i = 0; i < maxn; ++ i) x[i] = i; }
    int Find(int a){ return a == x[a] ? a : x[a] = Find(x[a]); }
    void Union(int a , int b){ x[Find(a)] = Find(b); }
    int operator[](int a){ return Find(a); }
} ds;

int main() {
    cin.tie(0), cout.sync_with_stdio(0);

    cin >> n >> k >> s;

    for (int i = 0; i < s.size(); ++ i)
        x[i + 1] = s[i] - '0';

    for (int i = 1; i <= k; ++ i) {
        int nn, in;
        cin >> nn;
        for (int j = 0; j < nn; ++ j) {
            cin >> in;
            cc[i].insert(in);
            v[in].emplace_back(i);
        }
        cost[i] = 1;
    }
    ds.init();
    int ans = 0;
    for (int i = 1; i <= n; ++ i) {
        vector<int> tmp;
        for (auto to : v[i]) if (cc[ds[to]].find(i) != cc[ds[to]].end())
            tmp.emplace_back(ds[to]);
        v[i] = tmp;
        if (x[i] == 0) {
            if (v[i].size() == 1) {
                int idx = ds[v[i][0]];
                for (auto to : cc[idx])
                    x[to] ^= 1;
                ans += cost[idx];
                cost[idx] = n * 2;
                cc[idx].clear();
            }
            else {
                int v1 = ds[v[i][0]], v2 = ds[v[i][1]];
                if (cost[v1] != cost[v2]) {
                    if (cost[v1] < cost[v2]) swap(v1, v2);
                }
                else if (cc[v1].size() < cc[v2].size())
                    swap(v1, v2);
                ans += cost[v2];
                cost[v1] -= cost[v2];
                cost[v2] = 0;
                ds.Union(v2, v1);
                for (auto to : cc[v2]) {
                    x[to] ^= 1;
                    if (cc[v1].find(to) != cc[v1].end())
                        cc[v1].erase(to);
                    else cc[v1].insert(to);
                }
                cc[v2].clear();
            }
        }
        else if (v[i].size() == 1) {
            int idx = ds[v[i][0]];
            cost[idx] = n * 2;
            cc[idx].clear();
        }
        else if (v[i].size() == 2) {
            int v1 = ds[v[i][0]], v2 = ds[v[i][1]];
            if (cc[v1].size() < cc[v2].size())
                swap(v1, v2);
            cost[v1] += cost[v2];
            cost[v2] = 0;
            ds.Union(v2, v1);
            for (auto to : cc[v2]) {
                if (cc[v1].find(to) != cc[v1].end())
                    cc[v1].erase(to);
                else cc[v1].insert(to);
            }
            cc[v2].clear();
        }
        cout << ans << "\n";
        // cout << "i = " << i << endl;
        // for (int j = 1; j <= n; ++ j) cout << x[j] ; cout << endl;
        // for (int j = 1; j <= k; ++ j) {
        //     cout << "idx = " << j << " $ = " << cost[j] << " - ";
        //     for (auto to : cc[j]) cout << to << " " ; cout << endl;
        // }
    }
    return 0;
}