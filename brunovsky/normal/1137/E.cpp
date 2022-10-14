#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

using Linear = array<int64_t, 2>;
auto operator+(Linear a, Linear b) { return Linear{a[0] + b[0], a[1] + b[1]}; }
auto operator-(Linear a, Linear b) { return Linear{a[0] - b[0], a[1] - b[1]}; }
auto eval(Linear a, int64_t x) { return a[0] * x + a[1]; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int64_t C;
    int Q;
    cin >> C >> Q;

    struct Node {
        Linear cancel;
        int64_t length, start;
        int prv, nxt, killed = 0;
    };

    using Entry = array<int64_t, 2>;
    vector<Node> nodes;
    Linear lin;
    priority_queue<Entry, vector<Entry>, greater<Entry>> updates;

    auto reset = [&](int64_t k) {
        lin = {0, 0};
        nodes = {Node{lin, k, 0, -1, +1}, Node{lin, 0, k, 0, 2}};
        while (!updates.empty()) {
            updates.pop();
        }
    };
    auto get_height = [&](int i) { return eval(lin - nodes[i].cancel, nodes[i].start); };

    reset(C);

    vector<int64_t> height, start, length;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int64_t k;
            cin >> k;
            C += k;
            reset(C);
        } else if (t == 2) {
            int64_t k;
            cin >> k;
            C += k;
            int P = nodes.size() - 1;
            int i = nodes[P].prv;
            int64_t x = nodes[i].length;
            int64_t s = (get_height(i) + x - 1) / x;

            nodes[P].cancel = lin;
            nodes[P].length = k;
            nodes.push_back(Node{lin, 0, k + nodes[P].start, P, P + 2});
            updates.push({lin[0] + s, P});
        } else if (t == 3) {
            Linear l;
            cin >> l[1] >> l[0];
            lin = lin + l;
        } else {
            assert(false);
        }

        int P = nodes.size() - 1;

        while (!updates.empty() && lin[0] >= updates.top()[0]) {
            auto [A, i] = updates.top();
            updates.pop();
            if (nodes[i].killed) {
                continue;
            }
            nodes[i].killed = true;
            int p = nodes[i].prv, n = nodes[i].nxt;
            assert(0 <= p && p < i && i < n && n <= P);
            nodes[p].nxt = n;
            nodes[n].prv = p;
            nodes[p].length += nodes[i].length;
            if (n < P) {
                int64_t x = nodes[p].length;
                int64_t s = (get_height(p) - get_height(n) + x - 1) / x;
                updates.push({lin[0] + s, n});
            }
        }

        int i = nodes[P].prv;
        cout << nodes[i].start + 1 << ' ' << get_height(i) << '\n';
    }

    return 0;
}