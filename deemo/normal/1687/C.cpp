#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN];
ll p[MAXN];
int tl[MAXN], tr[MAXN];
vector<int> vec[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] -= x;
        p[i+1] = p[i] + a[i];
    }
    
    for (int i = 0; i <= n; i++)
        vec[i].clear();
    for (int i = 0; i < m; i++)
        cin >> tl[i] >> tr[i], tl[i]--, vec[tl[i]].push_back(i), vec[tr[i]].push_back(i);

    set<int> z, nz;
    for (int i = 0; i <= n; i++)
        if (!p[i])
            z.insert(i);
        else
            nz.insert(i);

    while (z.size()) {
        int x = *z.begin();
        z.erase(z.begin());
        for (int seg: vec[x])
            if (!p[tl[seg]] && !p[tr[seg]])
                while (true) {
                    auto it = nz.lower_bound(tl[seg]);
                    if (it != nz.end() && *it < tr[seg]) {
                        p[*it] = 0;
                        z.insert(*it);
                        nz.erase(it);
                    } else break;
                }
    }

    if (nz.empty())
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        solve();
    }
    return 0;
}