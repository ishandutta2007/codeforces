#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <map>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int N = 1001000;

int par[N];
vector<int> ch[N];
int dep_in[N];

set<pii> s[N];
int offset[N];
int sl[N]; // set location
int set_count = 1;

int v[N];
int n, k;

struct segtree {
    vector<int> d;
    int n, h;
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        d = vector<int>(n<<1, 0);
    }
    void pushh(int x) {
        if (d[x]) {
            d[x<<1] = d[x];
            d[x<<1|1] = d[x];
            d[x] = 0;
        }
    }
    void update(int l, int r, int v, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv || rv<=l) {
            return;
        }
        if (l<=lv && rv<=r) {
            //cerr << " d[" << x << "] set to " << v << endl;
            d[x] = v;
            return;
        }
        pushh(x);
        int mv = (lv+rv)/2;
        update(l, r, v, x*2, lv, mv);
        update(l, r, v, x*2+1, mv, rv);
    }
    int get(int i) {
        i += n;
        for (int j=h; j; --j) {
            pushh(i>>j);
        }
        return d[i];
    }
};

void build() {
    segtree st(n+2);
    //cerr << "!! " << st.n << endl;
    for (int i=n; i; --i) {
        par[i] = st.get(v[i]);
        if (par[i]) {
            ch[par[i]].push_back(i);
        }
        //cerr << " par[" << i << "] = " << par[i] << endl;
        //cerr << "   v[" << i << "] = " << v[i] << endl;
        st.update(1, v[i], i);
    }
}

set<pii> best_of;

void insert_into(int si, int i, int d, bool inc = false) {
    int old_best = 0;
    if (s[si].size()) {
        old_best = s[si].rbegin()->first + offset[si];
    }

    if (inc) {
        ++offset[si];
    }

    sl[i] = si;
    s[si].insert(pii(d-offset[si], i));
    dep_in[i] = d-offset[si];

    int new_best = s[si].rbegin()->first + offset[si];
    if (old_best != new_best) {
        best_of.erase(pii(old_best, si));
        best_of.insert(pii(new_best, si));
    }
}
void insert_onto(int si, int i) {
    insert_into(si, i, 1, true);
}
void remove_from(int i) {
    int si = sl[i];

    ////cerr << " try to remove from " << si << endl;
    int old_best = s[si].rbegin()->first + offset[si];

    s[si].erase(pii(dep_in[i], i));

    if (s[si].size()) {
        int new_best = s[si].rbegin()->first + offset[si];
        ////cerr << " NEW best is " << best << endl;
        if (new_best != old_best) {
            best_of.erase(pii(old_best, si));
            best_of.insert(pii(new_best, si));
        }
    } else {
        best_of.erase(pii(old_best, si));
    }
}
int get_ans() {
    return best_of.rbegin()->first;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
    }

    build();

    for (int i=1; i<=k; ++i) {
        if (ch[i].empty()) {
            insert_onto(set_count++, i);
        } else if (ch[i].size() == 1) {
            insert_onto(sl[ch[i][0]], i);
        } else {
            pii big(-1, -1);
            for (auto& j : ch[i]) {
                big = max(big, pii(s[sl[j]].size(), j));
            }
            int b = big.second;
            insert_onto(sl[b], i);
            //cerr << "!! merge" << endl;
            for (auto& j : ch[i]) {
                if (j == b) continue;
                int sj = sl[j];
                for (auto& p : s[sj]) {
                    int u = p.second;
                    int d = p.first;
                    insert_into(sl[b], u, d+offset[sj]+1);
                }
                //cerr << "! " << s[sj].size() << " for " << j << endl;
                if (s[sj].size()) {
                    //cerr << " erasing " << sj << endl;
                    best_of.erase(pii(s[sj].rbegin()->first + offset[sj], sj));
                }
            }
        }
    }

    ////cerr << " gonna get ans " << endl;
    cout << get_ans() << " ";

    for (int i=k+1; i<=n; ++i) {
        remove_from(i-k);
        if (ch[i].empty()) {
            insert_onto(set_count++, i);
        } else if (ch[i].size() == 1) {
            insert_onto(sl[ch[i][0]], i);
        } else {
            pii big(-1, -1);
            for (auto& j : ch[i]) {
                big = max(big, pii(s[sl[j]].size(), j));
            }
            int b = big.second;
            insert_onto(sl[b], i);
            for (auto& j : ch[i]) {
                if (j == b) continue;
                int sj = sl[j];
                for (auto& p : s[sj]) {
                    int u = p.second;
                    int d = p.first;
                    insert_into(sl[b], u, d+offset[sj]+1);
                }
                if (s[sj].size()) {
                    best_of.erase(pii(s[sj].rbegin()->first + offset[sj], sj));
                }
            }
        }
        ////cerr << "!! answer " << endl;
        cout << get_ans() << " ";
    }
    cout << endl;

    // todo: implement the "two pointer walk"
    // 0. add a remapping so that we can store the parent of each leaf
    // 2. add the right element as done above.
    return 0;
}