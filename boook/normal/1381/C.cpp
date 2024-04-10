#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define maxn 100009

int t, n, x, y, a[maxn], c[maxn], ans[maxn], nxt[maxn];

vector<int> sol[maxn];

void ADD(int now, int addidx) {
    // cout << "addidx: " << addidx << endl;
    int to = nxt[now];
    nxt[now] = addidx;
    nxt[addidx] = to;
}
int Query(int now) {
    // if (nxt[0] == 0) exit(0);
    assert(nxt[0] != 0);
    if (now == 0) return Query(nxt[now]);
    return now;
}

int32_t main() {
    cin.tie(0), cout.sync_with_stdio(0);

    cin >> t;
    while (t --) {
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++ i) cin >> a[i];

        int oth = 0;
        for (int i = 0; i <= n; ++ i) ans[i] = 0, nxt[i] = 0;
        for (int i = 0; i <= n + 1; ++ i) sol[i].clear();
        for (int i = 0; i <= n + 1; ++ i) c[i] = 0;

        for (int i = 1; i <= n; ++ i) c[a[i]] ++;
        for (int i = 1; i <= n + 1; ++ i) if (c[i] == 0) oth = i;
        for (int i = 1; i <= n; ++ i) sol[a[i]].emplace_back(i);

        priority_queue<PII> pq;
        for (int i = 1; i <= n + 1; ++ i) if (c[i] > 0) pq.push(make_pair(c[i], i));
        for (int i = 1; i <= x; ++ i) {
            PII tmp = pq.top();
            int num = tmp.first, idx = tmp.second;
            pq.pop();
            ans[sol[idx].back()] = idx, sol[idx].pop_back();
            if (num) pq.push(make_pair(num - 1, idx));
        }

        int without_big = n - x - pq.top().first;
        int can = without_big + min(without_big, pq.top().first);
        // cout << "without_big: " << without_big << " can: " << can << "\n";
        if (can < y - x) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            // for (int i = 1; i <= n; ++ i) cout << ans[i] << " "; cout << "\n";
            int now = 0, first = 0;
            while (pq.size()) {
                PII tmp = pq.top(); pq.pop();
                int num = tmp.first, idx = tmp.second;
                assert(sol[idx].size() == num);
                while (num --) {
                    if (first == 0) now = nxt[now];
                    else now = Query(nxt[now]);
                    ADD(now, sol[idx].back());
                    now = sol[idx].back();
                    // cout << "ins: " << sol[idx].back() << endl;
                    sol[idx].pop_back();
                }
                if (first == 0) first = 1, now = 0;
            // cout << "after insert c: " << idx << endl;
            // cout << "nxt[0]: " << nxt[0] << endl;
            // for (int i = 1; i <= n; ++ i) cout << nxt[i] << " "; cout << "\n";
            // cout << "now = " << now << endl;

            }
            int p = 0;
            for (int i = 1; i <= y - x; ++ i) {
                p = Query(nxt[p]);
                ans[p] = a[Query(nxt[p])];
            }
            for (int i = 1; i <= n; ++ i) if (ans[i] == 0) ans[i] = oth;
            // cout << "nxt[0]: " << nxt[0] << endl;
            // for (int i = 1; i <= n; ++ i) cout << nxt[i] << " "; cout << "\n";
            for (int i = 1; i <= n; ++ i) cout << ans[i] << " "; cout << "\n";
        }
    }
    return 0;
}