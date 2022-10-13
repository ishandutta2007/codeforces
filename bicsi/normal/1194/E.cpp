#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    vector<int> data;
    int max;
    Fenwick(int max) : data(2 * max + 2, 0), max(max) {}

    void Add(int pos) {
        for (pos += max + 1; pos < (int)data.size(); pos += (pos & -pos))
            data[pos] += 1;
    }

    int Query(int pos) {
        int ans = 0;
        for (pos += max + 1; pos > 0; pos -= (pos & -pos))
            ans += data[pos];
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    long long ans = 0;
    vector<tuple<int, int, int>> hors, verts;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            verts.emplace_back(x1, y1, y2);
        } else {
            assert(y1 == y2);
            if (x1 > x2) swap(x1, x2);
            hors.emplace_back(y1, x1, x2);
        }
    }

    sort(hors.begin(), hors.end());

    n = hors.size();
    for (int i = 0; i < n; ++i) {
        int x, y1, y2; tie(x, y1, y2) = hors[i];

        vector<tuple<int, int, int, int>> evts;
        for (auto itr : verts) {
            int y, x1, x2; tie(y, x1, x2) = itr;
            if (x1 > x) continue;
            if (y > y2 || y < y1) continue;
            evts.emplace_back(x2, 2, y, y);
        }

        for (int j = n - 1; j > i; --j) {
            int xp, y1p, y2p; tie(xp, y1p, y2p) = hors[j];
            evts.emplace_back(xp, 1, y1p, y2p);
        }

        Fenwick fw(5005);
        sort(evts.rbegin(), evts.rend());
        for (auto itr : evts) {
            int tp, y1, y2; tie(ignore, tp, y1, y2) = itr;
            if (tp == 2) fw.Add(y1);
            else {
                int now = fw.Query(y2) - fw.Query(y1 - 1);
                ans += now * (now - 1) / 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}