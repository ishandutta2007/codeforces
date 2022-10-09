#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define rand __rand
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
template<class T = int> T rand(T range = numeric_limits<T>::max()) { return (T)(rng() % range); }

#define CONCAT_(x, y) x##y/*{{{*/
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
bool __db_same_line = false;
#define clog cerr << string(!__db_same_line ? __db_level * 2 : 0, ' ')
struct debug_block {
    function<void()> fn;
    void print_name() { __db_same_line = true; fn(); clog << endl; __db_same_line = false;  }
    debug_block(function<void()> fn_): fn(fn_) { clog << "{ "; print_name(); ++__db_level; }
    ~debug_block() { --__db_level; clog << "} "; print_name(); }
};
#define DB(args...) debug_block CONCAT(dbbl, __LINE__)([=]{ clog << args; })
#define deb(...)  if (1) { (clog << "[" #__VA_ARGS__ "] = [" << __VA_ARGS__) << "]"; if (!__db_same_line) clog << endl; }
#else
#define clog if (0) cerr
#define DB(...)
#define deb(...)
#endif
template<class T>
ostream& operator,(ostream& out, const T& thing) { return out << ", " << thing; }
template<class U, class V>
ostream& operator<<(ostream& out, const pair<U, V>& p) { return (out << "(" << p.first, p.second) << ")"; }
template<class A, class B>
ostream& operator<<(ostream& out, const tuple<A, B>& t) { return (out << "(" << get<0>(t), get<1>(t)) << ")"; }
template<class A, class B, class C>
ostream& operator<<(ostream& out, const tuple<A, B, C>& t) { return (out << "(" << get<0>(t), get<1>(t), get<2>(t)) << ")"; }
template<class T> ostream& operator<<(ostream& out, const vector<T>& container) { 
    out << "{";
    if (len(container)) out << container[0];
    rep1(i, len(container) - 1) out, container[i];
    return out << "}";
}
template<class x> vector<typename x::value_type> $v(const x& a) { return vector<typename x::value_type>(a.begin(), a.end()); }
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION BELOW ////////////////////////////////////////////////////////////

const int dim = (int)1e6;

struct seg {
    int pos, h;
    seg(int p_ = 0, int h_ = 0) : pos(p_), h(h_) {}
};

bool cmp_seg_h(const seg& u, const seg& v) {
    return u.h < v.h;
}

bool cmp_seg_pos(const seg& u, const seg& v) {
    return u.pos < v.pos;
}

struct segs {
    vector<seg> left, right;
};

void do_sort(segs& cur, segs& other) {
    sort(other.left.begin(), other.left.end(), cmp_seg_h);
    sort(other.right.begin(), other.right.end(), cmp_seg_h);
    sort(cur.left.begin(), cur.left.end(), cmp_seg_pos);
    sort(cur.right.begin(), cur.right.end(), cmp_seg_pos);
}

template<bool rev>
struct BIT {
    vector<int> cnt;
    BIT(): cnt(dim + 10) {}
    void upd(int pos, int del) {
        if (rev) pos = len(cnt) - pos - 4;
        for (++pos; pos < len(cnt); pos += pos & -pos) cnt[pos] += del;
    }
    
    int get(int pos) {
        if (rev) pos = len(cnt) - pos - 4;
        int ans = 0;
        for (++pos; pos > 0; pos -= pos & -pos) ans += cnt[pos];
        return ans;
    }
};

llong process(segs& a, segs& b) {
    do_sort(a, b);
    llong ans = 0;
    
    {
        BIT<false> cnt_left_pos, cnt_right_pos;
                
        for (auto& [pos, h]: b.left) {
            cnt_left_pos.upd(pos, 1);
        }
        
        int p1 = 0, p2 = 0;
        for (auto& [pos, h]: a.left) {
            while (p1 < len(b.left) and b.left[p1].h < pos) {
                auto cur = b.left[p1++];
                cnt_left_pos.upd(cur.pos, -1);
            }
            
            while (p2 < len(b.right) and b.right[p2].h <= pos) {
                auto cur = b.right[p2++];
                cnt_right_pos.upd(cur.pos, 1);
            }
            
            ans += cnt_left_pos.get(h) + cnt_right_pos.get(h);
        }
    }
    
    {
        BIT<true> cnt_left_pos, cnt_right_pos;
                
        for (auto& [pos, h]: b.left) {
            cnt_left_pos.upd(pos, 1);
        }
        
        int p1 = 0, p2 = 0;
        for (auto& [pos, h]: a.right) {
            while (p1 < len(b.left) and b.left[p1].h < pos) {
                auto cur = b.left[p1++];
                cnt_left_pos.upd(cur.pos, -1);
            }
            
            while (p2 < len(b.right) and b.right[p2].h <= pos) {
                auto cur = b.right[p2++];
                cnt_right_pos.upd(cur.pos, 1);
            }
            
            ans += (cnt_left_pos.get(h) + cnt_right_pos.get(h));
        }
    }
    return ans;
}

int n, m;
segs ver, hor;

llong ans = 1;
void read(int cnt, segs& a) {
    rep(i, cnt) {
        int pos, l, r; cin >> pos >> l >> r;
        if (l == 0) a.left.emplace_back(pos, r);
        else a.right.emplace_back(pos, l);
        if (l == 0 and r == dim) ++ans;
    }
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    read(n, ver);
    read(m, hor);
    ans += process(hor, ver);
    cout << ans;
    
    return 0;
}

// Remember:
// - Multitest? REFRESHING the data!!!
// - Constrains for each set of data may differs. Should NOT USE the same max constant (maxn)
//   for all of them.
// vim: foldmethod=marker