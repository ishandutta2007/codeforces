#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second

string a, b;
int p[26];
bool vis[26];
ve<ii> ans;

ii sii(int u, int v) { if (u > v) return ii(v, u); return ii(u,v);}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    memset(p, -1, sizeof(p));
    cin >> a >> b;
    for (int i = 0; i < sz(a); i ++) {
        char u = a[i] - 'a', v = b[i] - 'a';
        if (p[u] == -1 and p[v] == -1) p[u] = v, p[v] = u, ans.push_back(ii(u, v));
        else if (p[u] != v or p[v] != u) {
            cout << -1;
            exit(0);
        }
    }

    sort((ans).begin(), (ans).end());
    ans.resize(unique((ans).begin(), (ans).end()) - ans.begin());

    for (int i = 0; i < sz(ans);) {
        if (ans[i].xx != ans[i].yy) ++i;
        else {
            ans.erase(ans.begin() + i);
        }
    }

    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); ++i) {
        cout << char(ans[i].xx + 'a') << ' ' << char(ans[i].yy + 'a') << '\n';
    }

    return 0;
}