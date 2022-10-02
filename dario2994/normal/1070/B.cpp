#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Container>
int SZ(const Container& S) { return S.size(); }

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

string to_string(string sub) {
    int it = 0;
    static int a[4];
    for (int i = 0; i < 4; i++) a[i] = 0;
    int x = 0;
    bool read_x = false;
    for (char c : sub) {
        // dbg_var(c);
        if (c == '.') it++;
        else if (c == '/') read_x = true;
        else {
            int z = c-'0';
            if (read_x) x = 10*x + z;
            else a[it] = 10*a[it]+z;
        }
    }
    if (!read_x) x = 32;
    // dbg_array(a, 4);
    // dbg_var(x);
    // return "X";
    // return "CIA";
    string s(32, '0');
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) if (1<<j & a[i]) s[8*i + 7-j] = '1';
    }
    s.resize(x);
    return s;
}

string to_subnet(string s) {
    int x = s.size();
    s.resize(32, 0);
    stringstream sout;
    static int a[4];
    for (int i = 0; i < 4; i++) {
        a[i] = 0;
        for (int j = 8*i; j < 8*(i+1); j++) {
            a[i] *= 2;
            a[i] += s[j] == '1';
        }
        sout << a[i];
        if (i != 3) sout << ".";
    }

    sout << "/" << x;
    return sout.str();
}

struct Node {
    Node *ll, *rr;
    int bm;
    int tipo = 0;
    Node(): ll(nullptr), rr(nullptr), bm(0), tipo(0) {}
};

void add_to_trie(const string& S, int it, Node* v, int tipo) {
    v->bm |= tipo;
    if (it == (int)S.size()) {
        v->tipo = tipo;
        return;
    }
    if (S[it] == '0') {
        if (!v->ll) v->ll = new Node();
        add_to_trie(S, it+1, v->ll, tipo);
    } else {
        if (!v->rr) v->rr = new Node();
        add_to_trie(S, it+1, v->rr, tipo);
    }
}


int work = true;
vector<string> ans;
void solve(Node* v, string curr) {
    // dbg_var(curr);
    if (v->tipo == 1) { // BLACKLIST
        if (v->bm & 2) work = false;
        ans.push_back(to_subnet(curr));
    } else if (v->tipo == 2) {
        if (v->bm & 1) work = false;
    } else if (v->bm == 1) {
        ans.push_back(to_subnet(curr));
    } else {
        if (v->ll) solve(v->ll, curr + '0');
        if (v->rr) solve(v->rr, curr+'1');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    Node* root = new Node();
    for (int i = 0; i < N; i++) {
        char sign;
        cin >> sign;
        string s;
        cin >> s;
        string S = to_string(s);
        // cout << sign << " " << S << endl;
        add_to_trie(S, 0, root, (sign == '-')?1:2);
    }
    solve(root, "");
    if (!work) cout << -1 << "\n";
    else {
        cout << ans.size() << "\n";
        for (string s : ans) cout << s << "\n";
    }
}