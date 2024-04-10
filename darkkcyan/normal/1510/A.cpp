#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const ld eps = 1e-8;
// for matching the kactl notes
#define sz(x) ((int)x.size())
#define rep(i,a,b) for (int i = (int)(a); i < (int)(b); ++i) 
#define all(a) (a).begin(), (a).end()
// #define constexpr(...) (__VA_ARGS__)  
// DEBUGING TEMPLETE ////////////////////////////////////////////////////////////////////////{{{
#define db(val) "["#val" = "<<(val)<<"] "
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#ifdef LOCAL_DEBUG   
#   define clog cerr << flush << string(__db_level * 2, ' ')
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

template<class U, class V> ostream& operator<<(ostream& out, const pair<U, V>& p) {
    return out << "(" << p.first << ", " << p.second << ")";
}

template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}

template<class ...U> ostream& operator<<(ostream& out, const tuple<U...>& tup) {
    return print_tuple_utils<0, tuple<U...>>(out, tup);
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& container) { 
    out << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        out << (it == container.begin() ? "" : ", ") << *it;
    return out << "}";
}
// ACTUAL SOLUTION START HERE ////////////////////////////////////////////////////////////////}}}

using Board = vector<string>;
struct RelBoard {
    Board* board;
    int dr, dc;
    RelBoard(Board* br, int r = 0, int c = 0): board(br), dr(r), dc(c) {}
    RelBoard move(int r = 0, int c = 0) {
        RelBoard other = *this;
        other.dr += r;
        other.dc += c;
        return other;
    }
    
    void put(int r, int c, char ch) { (*board)[r + dr][c + dc] = ch; }
    void put(int r, int c, const string& s) {
        rep(i, 0, sz(s)) put(r, i + c, s[i]);
    }
    void hor_line(int r, int c, int length) {
        rep(i, 0, length) put(r, c + i, '-');
    }
    void ver_line(int r, int c, int length) {
        rep(i, 0, length) put(r + i, c, '|');
    }
    void right_arrow(int r, int c, int length) {
        hor_line(r, c, length - 1);
        put(r, c + length - 1, '>');
    }
    void left_arrow(int r, int c, int length) {
        hor_line(r, c + 1, length - 1);
        put(r, c, '<');
    }
    void ver_seg(int r, int c, int length) {
        put(r, c, '+');
        ver_line(r + 1, c, length - 2);
        put(r + length - 1, c, '+');
    }
};

using sit = const char*&;
template<class T> using uptr = unique_ptr<T>;
struct Box {
    int w, h;
    vector<uptr<Box>> children;
    Box(int w_, int h_): w(w_), h(h_) {
        clog << "new box" << db(w) << db(h) << endl;
    }
    Box(int w_, int h_, vector<uptr<Box>>& c): w(w_), h(h_), children(move(c)) {
        clog << "new box" << db(w) << db(h) << endl;
    }
    // Box(int w_, int h_, vector<uptr<Box>>&& c): w(w_), h(h_), children(c) {} 
    Box(int w_, int h_, uptr<Box>& inner): w(w_), h(h_) {
        clog << "new box" << db(w) << db(h) << endl;
        children.push_back(move(inner));
    }
    virtual ~Box() = default;
    virtual void render(RelBoard rb) = 0;
};

struct Letter: Box {
    string content;
    Letter(const string& c): Box(sz(c) + 4, 3), content(c) {}
    virtual void render(RelBoard rb) override {
        rep(i, -1, 2) {
            rb.put(i, 0, '+');
            rb.put(i, w - 1, '+');
        }
        rb.hor_line(-1, 1, w - 2);
        rb.hor_line(1, 1, w - 2);
        rb.put(0, 2, content);
    }
};

struct Input : Box {
    Input(uptr<Box>& inner): Box(inner->w + 6, inner->h, inner) {}
    virtual void render(RelBoard rb) override {
        rb = rb.move(1, 0);
        rb.put(0, 0, 'S');
        rb.right_arrow(0, 1, 2);
        rb.right_arrow(0, w - 3, 2);
        rb.put(0, w - 1, 'F');
        children[0]->render(rb.move(0, 3));
    }
};
struct Expr : Box {
    Expr(vector<uptr<Box>>& c): Box(0, 0, c) {
        for (auto& ch: children) {
            w = max(w, ch->w);
            h += ch->h;
        }
        if (children.size() > 1) {
            h += sz(children) - 1;
            w += 6;
        }
    }
    virtual void render(RelBoard rb) override {
        if (sz(children) == 1) {
            children[0]->render(rb);
            return ;
        }
        rep(i, 0, sz(children)) {
            children[i]->render(rb.move(0, 3));
            rb.right_arrow(0, 1, 2);
            rb.right_arrow(0, 3 + children[i]->w, w - children[i]->w - 4);
            if (i == sz(children) - 1) break;
            rb.ver_seg(0, 0, children[i]->h + 2);
            rb.ver_seg(0, w - 1, children[i]->h + 2);
            rb = rb.move(children[i]->h + 1, 0);
        }
    }
};
struct Term: Box {
    Term(vector<uptr<Box>>& c): Box(0, 0, c) {
        for (auto& ch: children) {
            h = max(ch->h, h);
            w += ch->w;
        }
        w += (sz(children) - 1) * 2;
    }
    virtual void render(RelBoard rb) {
        rep(i, 0, sz(children) - 1) {
            children[i]->render(rb);
            rb = rb.move(0, children[i]->w + 2);
            rb.right_arrow(0, -2, 2);
        }
        children.back()->render(rb);
    }
};

struct QuesAtom: Box {
    QuesAtom(uptr<Box>& inner): Box(inner->w + 6, inner->h + 3, inner) {}
    virtual void render(RelBoard rb) override {
        rb.ver_seg(0, 0, 4); rb.ver_seg(0, w - 1, 4);
        rb.right_arrow(0, 1, w - 2);
        rb.right_arrow(3, 1, 2);
        rb.right_arrow(3, w - 3, 2);
        children[0]->render(rb.move(3, 3));
    }
};
struct PlusAtom: Box {
    PlusAtom(uptr<Box>& inner): Box(inner->w + 6, inner->h + 2, inner) {}
    virtual void render(RelBoard rb) override {
        rb.ver_seg(0, 0, children[0]->h + 1); rb.ver_seg(0, w - 1, children[0]->h + 1);
        rb.right_arrow(0, 1, 2);
        rb.right_arrow(0, w - 3, 2);
        rb.left_arrow(children[0]->h, 1, w - 2);
        children[0]->render(rb.move(0, 3));
    }
};
struct StarAtom: Box {
    StarAtom(uptr<Box>& inner): Box(inner->w + 6, inner->h + 5, inner) {}
    virtual void render(RelBoard rb) override {
        rb.ver_seg(0, 0, 4); rb.ver_seg(0, w - 1, 4);
        rb.right_arrow(0, 1, w - 2);
        rb.right_arrow(3, 1, 2);
        rb.right_arrow(3, w - 3, 2);
        rb.ver_seg(3, 0, children[0]->h + 1); rb.ver_seg(3, w - 1, children[0]->h + 1);
        rb.left_arrow(children[0]->h + 3, 1, w - 2);
        children[0]->render(rb.move(3, 3));
    }
};
uptr<Box> parseExpr(sit s);
uptr<Box> parseTerm(sit s);
uptr<Box> parseAtom(sit s);
uptr<Box> parseLetter(sit s);

uptr<Box> parseExpr(sit s) {
    DB(); clog << "expr " << *s << endl;
    vector<uptr<Box>> children;
    children.push_back(parseTerm(s));
    while (*s and *s == '|') {
        ++s;
        children.push_back(parseTerm(s));
    }
    return make_unique<Expr>(children);
}

uptr<Box> parseTerm(sit s) {
    DB(); clog << "term " << *s << endl;
    vector<uptr<Box>> children;
    children.push_back(parseAtom(s));
    while (*s and *s != '|' and *s != ')') {
        children.push_back(parseAtom(s));
    }
    return make_unique<Term>(children);
}

uptr<Box> parseAtom(sit s) {
    DB(); clog << "atom " << *s << endl;
    uptr<Box> ans = NULL;
    string content;
    if (isalpha(*s)) {
        ans = parseLetter(s);
        auto cur_ans = dynamic_cast<Letter*>(ans.get());
        content = cur_ans->content;
    } else if (*s == '(') {
        ans = parseExpr(++s);
        assert(*s == ')');
        ++s;
    }
    clog << db(*s) << endl;
    uptr<Box> head = NULL;
    while (true) {
        if ((*s == '+' or *s == '?' or *s == '*') and content.size() > 1) {
            clog << db(content) << endl;
            head = make_unique<Letter>(content.substr(0, sz(content) - 1));
            clog << db(string(1, content.back())) << endl;
            ans.reset();
            ans = make_unique<Letter>(string(1, content.back()));
            content = "";
        }
        if (*s == '+') ans = make_unique<PlusAtom>(ans);
        else if (*s == '?') ans = make_unique<QuesAtom>(ans);
        else if (*s == '*') ans = make_unique<StarAtom>(ans);
        else break;
        ++s;
    }
    if (!head) return ans;
    vector<uptr<Box>> children;
    children.push_back(move(head));
    children.push_back(move(ans));
    return make_unique<Term>(children);
}

uptr<Box> parseLetter(sit s) {
    DB(); clog << "letter " << *s << endl;
    string c; 
    while (*s and isalpha(*s)) c += *s++;
    return make_unique<Letter>(c);
}

uptr<Box> parseInput(sit s) {
    DB(); clog << "input " << endl;
    auto expr = parseExpr(s);
    return make_unique<Input>(expr);
}

int main() {
#ifdef LOCAL
    freopen("main.inp", "r", stdin); 
    freopen("main.out", "w", stdout);  
    freopen(".log", "w", stderr);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    const char* it = s.data();
    auto ans = parseInput(it);
    cout << ans->h << ' ' << ans->w << endl;
    Board board(ans->h, string(ans->w, ' '));
    ans->render(RelBoard(&board));
    for (auto& i: board) {
        cout << i << '\n';
    }
    
    return 0;
}

// vim: foldmethod=marker