#include <bits/stdc++.h>
using namespace std;

// #define constexpr(...) (__VA_ARGS__)  
using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };
#else
#   define clog if (0) cerr
#   define DB(...)
#endif

template<class U, class V> print_op(pair<U, V>) {
    return out << "(" << u.first << ", " << u.second << ")";
}
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << "{";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : ", ") << *it;
    return out << "}";
}
template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

template<class T>
inline void combine(int& cur, T new_val, int max_val) {
    cur = cur * max_val + new_val;
}
template<class T>
inline void extract(int& cur, T& val, int max_val) {
    val = T(cur % max_val);
    cur /= max_val;
}

const int maxcard = 9;
const int maxcardval = 5;
struct PlayerCards {
    char cnt[maxcardval];
    operator int() const {
        // compress
        int ans = cnt[1];
        combine(ans, cnt[2], maxcard);
        combine(ans, cnt[3], maxcard);
        combine(ans, cnt[4], maxcard);
        return ans;
    }
    
    PlayerCards() = default;
    PlayerCards(int val) {
        extract(val, cnt[4], maxcard);
        extract(val, cnt[3], maxcard);
        extract(val, cnt[2], maxcard);
        extract(val, cnt[1], maxcard);
        cnt[0] = char(maxcard - 1 - cnt[1] - cnt[2] - cnt[3] - cnt[4]);
    }
    
    bool is_valid() const {
        return cnt[0] >= 0;
    }
    
    PlayerCards& play(int a, int b) {
        assert(cnt[a] > 0);
        --cnt[a];
        ++cnt[(a + b) % 5];
        return *this;
    }
    friend print_op(PlayerCards) {
        rep(i, 1, maxcardval) {
            rep(t, 0, u.cnt[i]) out << i << ' ';
        }
        return out;
    }
    friend bool operator==(const PlayerCards& u, const PlayerCards& v) {
        rep(i, 0, maxcardval) if (u.cnt[i] != v.cnt[i]) return false;
        return true;
    }
};

const int total_card_config = 495; // bigger than (4 + 8)! / 4! / 8!
const int uncompressed_card_config = maxcard * maxcard * maxcard * maxcard;

int pcid[uncompressed_card_config];
int rev_id[total_card_config];
vector<PlayerCards> good_player_cards;
void precal_id() {
    int cur_id = 0;
    rep(i, 0, uncompressed_card_config) {
        PlayerCards u(i);
        if (!u.is_valid()) {
            pcid[i] = -1;
        } else {
            rev_id[cur_id] = i;
            pcid[i] = cur_id++;
            good_player_cards.push_back(u);
        }
    }
}

struct Game {
    PlayerCards first, second;
    Game(initializer_list<PlayerCards> li) {
        auto beg = li.begin();
        first = *beg++;
        second = *beg++;
        assert(is_valid());
    }
    Game() = default;
    Game(int val): first(rev_id[val / total_card_config]), second(rev_id[val % total_card_config]) {
        assert(is_valid());
    }
    
    bool is_valid() const {
        return first.is_valid() and second.is_valid();
    }
    optional<Game> play(int a, int b) const {
        if (a == 0 or b == 0) return {};
        if (first.cnt[a] == 0) return {};
        if (second.cnt[b] == 0) return {};
        Game new_game{second, first};
        new_game.second.play(a, b);
        return new_game;
    }
    
    operator int() const {
        auto fi = pcid[first];
        auto si = pcid[second];
        return fi * total_card_config + si;
    }
    
    friend print_op(Game) {
        return out << db(u.first) << db(u.second);
    }
    
    friend bool operator == (const Game& u, const Game& v) {
        return u.first == v.first and u.second == v.second;
    }
};

const int total_game = total_card_config * total_card_config;

enum VisState { notvis = 0, visiting, visited };
enum GameState { win = 1, lose = -1, draw = 0, undetermined = 2 };

GameState game_state[total_game];

vector<Game> gr[total_game], rgr[total_game];
void build_graph() {
    for (auto first: good_player_cards) {
        for (auto second: good_player_cards) {
            Game g{first, second};
            if (first.cnt[0] == 8) {
                game_state[g] = win;
                continue;
            }
            if (second.cnt[0] == 8) {
                game_state[g] = lose;
                continue;
            }
            game_state[g] = undetermined;
            rep(a, 1, maxcardval) {
                if (first.cnt[a] == 0) continue;
                rep(b, 1, maxcardval) {
                    if (second.cnt[b] == 0) continue;
                    auto ng = g.play(a, b);
                    assert(ng);
                    assert(ng->is_valid());
                    gr[g].push_back(*ng);
                    rgr[*ng].push_back(g);
                }
            }
        }
    }
}

void precal() {
    precal_id();
    build_graph();
    // rep(i, 0, total_game) { 
        // if (comp_id[i]) continue; 
        // find_scc(i); 
    // } 
    // rep(i, 0, total_game) cal_game_state(i); 
    queue<Game> qu;
    vector<bool> vis(total_game);
    rep(i, 0, total_game) if (game_state[i] != undetermined) {
        qu.push(i);
        vis[i] = true;
    }
    vector<int> cnt_nxt_win(total_game);
    for (; qu.size(); qu.pop()) {
        auto u = qu.front();
        for (auto v: rgr[u]) {
            if (game_state[u] == lose) {
                game_state[v] = win;
                if (!vis[v]) {
                    vis[v] = 1;
                    qu.push(v);
                }
            } else {
                ++cnt_nxt_win[v];
                if (cnt_nxt_win[v] == sz(gr[v])) {
                    game_state[v] = lose;
                    if (!vis[v]) {
                        vis[v] = 1;
                        qu.push(v);
                    }
                }
            }
        }
    }
    rep(i, 0, total_game) if (game_state[i] == undetermined) {
        game_state[i] = draw;
    }
}

map<GameState, string> who_win = {
    {win, "Alice"}, {lose, "Bob"}, {draw, "Deal"}, {undetermined, "wtf??"}
};

int main() {
    precal();
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int ntest; cin >> ntest;
    rep(testcase, 1, ntest + 1) {
        int go_first;
        cin >> go_first;
        Game g{};
        rep(i, 0, 8) {
            int u; cin >> u;
            g.first.cnt[u]++;
        }
        rep(i, 0, 8) {
            int u; cin >> u;
            g.second.cnt[u]++;
        }
        clog << db(g) << db(go_first) << endl;
        if (go_first) swap(g.first, g.second);
        int ans = (int)game_state[g];
        if (go_first) ans = -ans;
        cout << who_win[(GameState)ans] << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker