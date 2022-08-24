#include <bits/stdc++.h>
#define int long long

using namespace std;

#define TASKNAME ""

const int N = 1007;

vector <vector <int> > gr;

bitset <N> all[N];

const int INF = 1e9 + 7;

int n;

bool check(vector <vector <int> > tree) {
    vector <vector <int> > gr1(n, vector <int> (n, 0));
    for (int v = 0; v < n; v++) {
        for (int u : tree[v]) {
            gr1[v][u] = 1;
            for (int x : tree[u]) {
                gr1[v][x] = 1;
            }
        }
    }
    return gr == gr1;
}

/*
5

*/

signed main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    gr.resize(n, vector <int> (n, 0));
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            v--;
            gr[i][v] = 1;
            all[i][v] = 1;
        }
    }
    vector <pair <int, int> > res;
    vector <bool> used(n, false);
    for (int v = 0; v < n; v++) {
        bitset <N> now, s;
        for (int i = 0; i < N; i++) {
            now[i] = 1;
        }
        s = now;
        int cnt = 0;
        for (int u = 0; u < n; u++) {
            if (!gr[u][v]) continue;
            now &= all[u];
            cnt++;
        }
        if (cnt != now.count()) continue;
        if (cnt == n) {
            for (int j = 2; j <= n; j++) {
                cout << 1 << " " << j << "\n";
            }
            exit(0);
        }
        int ban = -1;
        for (int u = 0; u < n; u++) {
            if (gr[u][v]) continue;
            auto nowt = all[u] & now;
            if (!nowt.count()) continue;
            if (nowt.count() > 2) {
                assert(false);
            }
            if (nowt.count() == 2) {
                s &= nowt;
            } else {
                if (ban != -1) continue;
                for (int k = 0; k < N; k++) {
                    if (nowt[k]) {
                        ban = k;
                        break;
                    }
                }
            }
        }
        vector <int> t;
        for (int j = 0; j < N; j++) {
            if (s[j]) {
                t.push_back(j);
            }
        }
        int need = 0;
        //cout << v << " " << need << "\n";
        assert(s.count() < 3);
        if (t.size() == 1) {
            need = t[0];
        } else {
            if (ban != -1) {
                need = t[0] + t[1] - ban;
            } else {
                need = t[0];
            }
        }
        bitset <N> masks[N];
        vector <int> p(n, -1);
        queue <int> q;
        res.push_back({need, v});
        p[need] = v;
        masks[v] = now;
        masks[need] = now;
        for (int j = 0; j < n; j++) {
            if (now[j]) {
                used[j] = true;
                if (j == v || j == need) continue;
                res.push_back({j, need});
                q.push(j);
                p[j] = need;
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            bitset <N> ones;
            for (int j = 0; j < N; j++) {
                ones[j] = 1;
            }
            int sons = 0;
            for (int j = 0; j < n; j++) {
                if (!gr[j][x] || !gr[j][p[x]] || gr[j][p[p[x]]]) continue;
                auto kek = masks[p[x]] & all[j];
                if (kek.count() != 2) continue;
                ones &= all[j];
                sons++;
            }
            if (sons > 1) {
                assert(sons == ones.count() - 2);
                for (int j = 0; j < n; j++) {
                    if (!ones[j] || j == x || j == p[x]) continue;
                    q.push(j);
                    p[j] = x;
                    res.push_back({j, x});
                }
                masks[x] = ones;
            } else if (sons == 1) {
                bitset <N> mask;
                for (int j = 0; j < N; j++) {
                    mask[j] = 0;
                }
                mask[x] = 1;
                mask[p[x]] = 1;
                int last = -1;
                for (int j = 0; j < n; j++) {
                    if (!gr[j][x] || !gr[j][p[x]] || !gr[j][p[p[x]]]) continue;
                    auto kek = all[j] & ones;
                    if (kek.count() == 3) {
                        for (int k = 0; k < n; k++) {
                            if (kek[k] && k != x && k != p[x]) {
                                last = k;
                                break;
                            }
                        }
                        break;
                    }
                }
                assert(last != -1);
                mask[last] = 1;
                masks[x] = mask;
                p[last] = x;
                q.push(last);
                res.push_back({last, x});
            }
        }
        for (auto p : res) {
            cout << p.first + 1 << " " << p.second + 1 << "\n";
        }
        exit(0);
    }
}