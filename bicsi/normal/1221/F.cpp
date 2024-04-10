#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    int n;
    vector<pair<long long, int>> data;
    vector<long long> bias;

    SegTree(const vector<int>& all) : 
        n(all.size()), data(4 * n), bias(4 * n, 0LL) { 
        init(1, 0, n - 1, all);
    }

    void Update(int l, int r, int val) {
        update(1, 0, n - 1, l, r, val);
    }
    
    pair<long long, int> Get() {
        return data[1];
    }

    void init(int node, int b, int e, const vector<int>& all) {
        if (b == e) data[node] = {0, b};
        else {
            int m = b + (e - b) / 2;
            init(node * 2, b, m, all);
            init(node * 2 + 1, m + 1, e, all);
            data[node] = max(data[node * 2], data[node * 2 + 1]);
        }
    }

    void update(int node, int b, int e, int l, int r, long long val) {
        l = max(l, b); r = min(r, e);
        if (l > r) return;
        if (b == l && e == r) {
            bias[node] += val;
            data[node].first += val;
        } else {
            int m = (b + e) / 2;
            update(node * 2, b, m, l, r, val);
            update(node * 2 + 1, m + 1, e, l, r, val);
            data[node] = max(data[node * 2], data[node * 2 + 1]);
            data[node].first += bias[node];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<tuple<int, int, int>> events;

    vector<int> all;

    for (int i = 0; i < n; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);
        events.emplace_back(b, a, c);
        all.push_back(a);
        all.push_back(b);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    
    SegTree st(all);
    sort(events.rbegin(), events.rend());

    tuple<long long, int, int> best = make_tuple(0LL, (int)2e9, (int)2e9);
    for (int i = 0; i < (int)all.size(); ++i) {
        int at = all[i];
        //cerr << "AT: " << at << endl;
        while (events.size()) {
            int a, b, c; tie(b, a, c) = events.back();
            if (b != at) break;
            events.pop_back();

            //cerr << "[0.." << a << "] += " << c << endl;
            a = lower_bound(all.begin(), all.end(), a) - all.begin();
            st.Update(0, a, c);
        }
        st.Update(i, i, at);
        pair<long long, int> now = st.Get();
        now.first -= at;
        //cerr << "NOW: " << now.first << " " << all[now.second] << endl;
        best = max(best, make_tuple(now.first, all[now.second], at));
    }
    cout << get<0>(best) << endl;
    cout << get<1>(best) << " " << get<1>(best) 
        << " " << get<2>(best) << " " << get<2>(best) << endl;

    return 0;
}