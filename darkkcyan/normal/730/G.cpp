#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int from, to;  // [from, to)
    int length() const {
        return to - from;
    }
    bool contains(Interval x) const {
        return from <= x.from and x.to <= to;
    }
};

bool operator<(const Interval& u, const Interval& v) {
    if (u.from == v.from) return u.to < v.to;
    return u.from < v.from;
}

vector<Interval> split(Interval big, Interval inner) {
    vector<Interval> ans;
    if (big.from != inner.from) {
        ans.push_back({big.from, inner.from});
    }
    if (inner.to != big.to) {
        ans.push_back({inner.to, big.to});
    }
    return ans;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    set<Interval> free_int;
    free_int.insert({1, INT_MAX});
    while (n--) {
        Interval cur;
        cin >> cur.from >> cur.to;
        cur.to += cur.from;
        bool ok = false;
        for (auto it = free_int.begin(); it != free_int.end(); ++it) {
            if (it->contains(cur)) {
                ok = true;
                cout << cur.from << ' ' << cur.to - 1 << '\n';
                auto t = *it;
                free_int.erase(it);
                for (auto u: split(t, cur)) {
                    free_int.insert(u);
                }
                break;
            }
        }
        if (ok) continue;
        for (auto it = free_int.begin(); it != free_int.end(); ++it) {
            if (it->length() >= cur.length()) {
                ok = true;
                Interval ans{it->from, it->from + cur.length()};
                cout << ans.from << ' ' << ans.to - 1 << '\n';
                auto t = *it;
                free_int.erase(it);
                for (auto u: split(t, ans)) {
                    free_int.insert(u);
                }
                break;
            }
        }
        assert(ok);
    }
}