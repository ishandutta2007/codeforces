#include<bits/stdc++.h>
using namespace std;

const int N = 110000;
set<int> S[N];
int cnt[N], id[N], to[N];

int main() {
    int n, m; cin >> n >> m;
    set<int> G, L;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cnt[i] = x;
        sum += x;
        for (int j = 1; j <= x; j++) {
            int y; cin >> y;
            S[i].insert(y);
        }
    }
    for (int i = 1; i <= n; i++) id[i] = i;
    sort(id + 1, id + n + 1, [](int i, int j) {
         return cnt[i] < cnt[j];
    });
    for (int i = 1; i <= n; i++) to[id[n - i + 1]] = sum / n + (i <= sum % n);
    for (int i = 1; i <= n; i++) {
        if (to[i] > cnt[i]) L.insert(i);
        if (to[i] < cnt[i]) G.insert(i);
    }
    vector<tuple<int, int, int>> V;
    while (G.size()) {
        if(L.empty()) break;
        int x = *G.begin();
        G.erase(x);
        while (cnt[x] > to[x]) {
            int y = *L.begin();
            vector<int> era;
            assert(cnt[y] < to[y]);
            assert(cnt[x] > to[x]);
            int flg = 0;
            for (int t : S[x]) {
                if (S[y].count(t)) continue;
                S[y].insert(t);
                V.emplace_back(x, y, t);
                cnt[y]++;
                cnt[x]--;
                era.push_back(t);
                if (cnt[x] == to[x]) {
                    flg = 1;
                    break;
                }
                if (cnt[y] == to[y]) {
                    flg = 1;
                    break;
                }
            }
            assert(flg);
            for (int t : era) S[x].erase(t);
            if (cnt[y] == to[y]) L.erase(y);
        }
    }
    assert(!L.size());
    cout << V.size() << endl;
    for (auto t : V) {
        int a, b, c;
        tie(a, b, c) = t;
        cout << a << ' ' << b << ' ' << c << endl;
    }
}