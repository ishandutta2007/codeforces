#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 5e5 + 5;

struct DSU {
    int w[N], t[N];
    vector<int> qr_time[N];
    vector<ll> qr_pref[N];

    DSU() {
        for (int i = 0; i < N; i++) {
            qr_pref[i].push_back(0);
            qr_time[i].push_back(-1);
            w[i] = -1;
        }
    }

    int find_set(int x) {
        return w[x] < 0 ? x : find_set(w[x]);
    }

    void upd(int x, int y, int z) {
        x = find_set(x);
        qr_pref[x].push_back(qr_pref[x].back() + y);
        qr_time[x].push_back(z);
    }

    int get_last_op_time(int node, int x = 0) {
        int ans = (qr_time[node].back() >= x ? qr_time[node].back() : -1);
        if (w[node] >= 0)
            ans = max(ans, get_last_op_time(w[node], t[node]));
        return ans;
    }

    ll get_sum_after_point(int node, int x) {
        int y = max(1, int(lower_bound(all(qr_time[node]), x) - qr_time[node].begin())) - 1;
        ll ans = qr_pref[node].back() - qr_pref[node][y];
        if (w[node] >= 0)
            ans += get_sum_after_point(w[node], max(x, t[node]));
        return ans;
    }

    void mrg(int a, int b, int x) {
        a = find_set(a);
        b = find_set(b);

        if (w[a] > w[b])
            swap(a, b);

        t[b] = x;
        w[a] += w[b];
        w[b] = a;
    }

    int get_size(int node) {
        return -w[find_set(node)];
    }
} dsu1, dsu2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x;
        string type;
        cin >> type >> x;
        x--;

        if (type[0] == 'U') {
            int y;
            cin >> y;
            y--;
            dsu1.mrg(x, y, i);
        }
        else if (type[0] == 'M') {
            int y;
            cin >> y;
            y--;
            dsu2.mrg(x, y, i);
        }
        else if (type[0] == 'A') {
            dsu1.upd(x, dsu1.get_size(x), i);
        }
        else if (type[0] == 'Z') {
            dsu2.upd(x, 0, i);
        }
        else {
            cout << dsu1.get_sum_after_point(x, dsu2.get_last_op_time(x)) << "\n";
        }
    }


    return 0;
}