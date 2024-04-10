#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#ifdef testing/*{{{*/
mt19937 rng(177013);
#else
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
#endif
#define rand() (int)(rng() >> 1)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#define SPEC(name) CONCAT(name, __LINE__)
#ifdef LOCAL_DEBUG   
int __db_level = 0;
#define clog cerr << string(__db_level * 2, ' ')
struct debug_block {
    string msg;
    debug_block(const string& s): msg(s) { clog << "{ " << msg << endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "} " << msg << endl; }
};
#define DB(args...) stringstream SPEC(ss); SPEC(ss)<< args; debug_block SPEC(dbbl)(SPEC(ss).str())
#else
#define clog if (0) cerr
#define DB(...)
#endif
#define db(val) "[" #val " = " << val << "]; "
template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")";
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup);
}
template<class ...U>
ostream& operator<<(ostream& out, const tuple<U...>& tup) { return print_tuple_utils<0, tuple<U...>>(out, tup); }
template<class, typename = void> struct has_const_iterator : false_type {};
template<class T> struct has_const_iterator<T, void_t<typename T::const_iterator>> : true_type {};
template<class T>
typename enable_if<has_const_iterator<T>::value && !is_same<T, string>::value, ostream&>::type
operator<<(ostream& out, const T& container) { 
    auto beg = container.begin(), end = container.end();
    out << "(" << container.size() << ") {";
    if (beg != end) out << *(beg++);
    while (beg != end) out << ", " << *(beg++);
    return out << "}";
}
#define ptrtype(x) typename iterator_traits<x>::value_type
template<class u> vector<ptrtype(u)> $v(u a, u b) { return vector<ptrtype(u)>(a, b); }/*}}}*/
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////

#define def_op(op, uop, body) \
    inline self_t& operator uop(const self_t& o) { body; return *this; } \
    friend inline self_t operator op (self_t lhs, const self_t & rhs) { return lhs uop rhs; }
#define def_cmp_op(op, body) friend inline bool operator op(const self_t& u, const self_t& v) { return body; }

template<int mod>
struct ModInt {
    int x;
    ModInt(): x(0) {}
    ModInt(int v): x(v >= mod ? v - mod : v < 0 ? v + mod : v) {}
    ModInt(long long v): ModInt((int)(v % mod)) {}
    using self_t = ModInt<mod>;
    def_op(+, +=, {x += o.x; if (x >= mod) x -= mod;})
    def_op(-, -=, {x -= o.x; if (x < 0) x += mod;}) 
    def_op(*, *= , {x = (int)(1ll * x * o.x % mod); })
    def_cmp_op(==, u.x == v.x;)
    def_cmp_op(!=, u.x != v.x;) 
    def_cmp_op(<, u.x < v.x;) 
    friend ostream& operator<<(ostream& out, const self_t& u) { return out << u.x; }
};
////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename U = ModInt<(int)1e9 + 8181>, typename V = unsigned long long>
struct Hash {
    U x; V y;
    Hash(): x(0), y(0) {}
    Hash(U u, V v): x(u), y(v) {}
    Hash(int u): x(u), y(u) {}
    using self_t = Hash<U, V>;
#define component_op(op, uop) def_op(op, uop, { x uop o.x; y uop o.y; })
    component_op(+, +=)
    component_op(-, -=)
    component_op(*, *=)
    def_cmp_op(==, u.x == v.x && u.y == v.y)
    def_cmp_op(!=, u.x != v.x || u.y != v.y)
    def_cmp_op(<, u.x < v.x || (u.x == v.x && u.y < v.y))
    friend ostream& operator<<(ostream& out, const self_t& u) { return out << "(" << u.x << ", " << u.y << ")"; }
};

template<int base = 29, int first_alpha = 'a', typename Hs = Hash<>>
struct StrHash {
    static Hs pow_base(int exp) {
        static vector<Hs> data(1, 1);
        while ((int)data.size() <= exp) data.push_back(data.back() * base);
        return data[exp];
    }
    
    vector<Hs> hs;
    StrHash() = default;
    StrHash(const string& s): hs(len(s) + 1, {0, 0}) {
        rep(i, len(s)) {
            int ch = s[i] - first_alpha + 1;
            hs[i + 1] = hs[i] * base + ch;
        }
    }
    
    Hs get(int l, int r) const {
        return hs[r] - hs[l] * pow_base(r - l);
    }
    
    Hs get_pref(int length) const {
        return get(0, length);
    }
    
    Hs get_suff(int length) const {
        return get(len(hs) - 1 - length, len(hs) - 1);
    }
    
    int count_occ(const Hs& xhs, int length) const {
        int ans = 0;
        for (int i = 0; i + length < len(hs); ++i) {
            ans += xhs == get(i, i + length);
        }
        return ans;
    }
};


////////////////////////////////////////////////////////////////////////////////////////////////////
using modInt = ModInt<(int)1e9 + 7>;

const int max_size = (int)1e6 + 10;
const int small_lv = 25;
const llong mod_hash = (int)1e9 + 8181;
const llong mod = (int)1e9 + 7;
const llong base = 29;

modInt p2[max_size], ip2[max_size];
void precal() {
    modInt inv_2(-mod / 2);
    clog << db(inv_2) << endl;
    p2[0] = 1;
    ip2[0] = 1;
    rep1(i, max_size - 1) {
        p2[i] = p2[i - 1] + p2[i - 1];
        ip2[i] = ip2[i - 1] * inv_2;
    }
}
int n, q;
string t;
vector<string> short_songs;
vector<StrHash<>> song_hash;
array<modInt, 26> acc_after[max_size];

modInt query(int song_id, const string& name) {
    DB(db(song_id) << db(name));
    int small_song = 0;
    while (small_song < len(short_songs) and len(short_songs[small_song]) < len(name))
        ++small_song;
    clog << db(small_song) << endl;
    small_song = min(small_song, song_id);
    clog << db(small_song) << endl;
    if (len(short_songs[small_song]) < len(name)) return 0;
    
    StrHash<> name_hs(name);
    auto& sh = song_hash[small_song];
    modInt ans = sh.count_occ(name_hs.hs.back(), len(name));
    clog << db(ans) << endl;
    ans *= p2[song_id - small_song];
    clog << db(ans) << endl;
    
    modInt coef = ip2[n - song_id];
    clog << db(coef) << endl;
    rep(p, len(name)) {
        DB(db(p));
        int suff_length = len(name) - p - 1;
        clog << db(suff_length) << endl;
        clog << db(sh.get_suff(p)) << db(name_hs.get_pref(p)) << endl;
        clog << db(sh.get_pref(suff_length)) << db(name_hs.get_suff(suff_length)) << endl;
        if (sh.get_suff(p) != name_hs.get_pref(p)) continue;
        if (sh.get_pref(suff_length) != name_hs.get_suff(suff_length)) continue;
        int ch = name[p] - 'a';
        modInt acc = acc_after[small_song][ch] - acc_after[song_id][ch];
        modInt cur_ans = acc * coef;
        ans += cur_ans;
    }
    return ans;
}

int main(void) {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    short_songs.push_back("");
    cin >> short_songs.back();
    cin >> t;
    for (int i = len(t); i--; ) {
        int ch = t[i] - 'a';
        acc_after[i] = acc_after[i + 1];
        acc_after[i][ch] += p2[n - i - 1];
        clog << i << ' ' << db(acc_after[i]) << endl;
    }
    
    for (int i = 0; i < n and len(short_songs.back()) < max_size; ++i)
        short_songs.push_back(short_songs.back() + t[i] + short_songs.back());
    
#ifdef LOCAL
    rep(i, len(short_songs)) clog << db(i) << db(short_songs[i]) << '\n';
#endif
    
    for (auto& s: short_songs) {
        song_hash.emplace_back(s);
    }
    
    while (q--) {
        int song_id;
        string name;
        cin >> song_id >> name;
        modInt ans = query(song_id, name);
        cout << ans << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker