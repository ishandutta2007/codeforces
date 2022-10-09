#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

struct seg {
    int l, r;
    int id;
    seg(){}
    seg(int l_, int r_, int id_): l(l_), r(r_), id(id_) {}
};

bool cmp_seg(seg const& u, seg const& v) {
    if (u.l == v.l) return u.r < v.r;
    return u.l < v.l;
}

int n;
vector<seg> zig, zag;

list<int> construct(vector<seg> segs) {
    sort(segs.rbegin(), segs.rend(), cmp_seg);
    vector<pair<int, list<int>>> st;
    for (auto& i: segs) {
        list<int> cur_ans; 
        while (len(st) and st.back().xx < i.r) {
            cur_ans.splice(cur_ans.begin(), st.back().yy);
            st.pop_back();
        }
        cur_ans.push_front(i.id);
        st.emplace_back(i.l, move(cur_ans));
    }
    list<int> ans;
    for (auto& i: st) ans.splice(ans.end(), move(i.yy));
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) {
        int u, v;
        cin >> u >> v;
        if (u < v) zig.emplace_back(u, v, i);
        else zag.emplace_back(-u, -v, i);
    }

    auto u = construct(zig);
    auto v = construct(zag);
    auto& ans = len(u) < len(v) ? v : u;
    cout << len(ans) << '\n';
    for (auto i: ans) cout << i + 1 << ' ';

    return 0;
}