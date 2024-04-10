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

const int MAXN = -1;

struct pt {
    int x, y;
    pt() {}
    pt(LL x, LL y) : x(x), y(y) {}
    LL norm() {
        return ((LL)x)*x + ((LL)y)*y;
    }
};

bool operator <(pt A, pt B) {
    return A.x < B.x;
}

unordered_map<LL, set<pt>> dist;
map<pair<int,int>, int> sym_cnt;

pair<int,int> get_middle(pt A, pt B) {
    int x = A.x + B.x, y = A.y+B.y;
    int g = __gcd(x, y);
    return {x/g, y/g};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int Q;
    cin >> Q;
    int cnt = 0;
    for (int _ = 0; _ < Q; _++) {
        int t, x, y;
        cin >> t >>  x >> y;
        int g = __gcd(x, y);
        pt P(x, y);
        if (t == 1) {
            cnt++;
            LL d = P.norm();
            sym_cnt[{x/g, y/g}]++;
            // cout << d << " " << dist[d].size() << endl;
            for (auto Q : dist[d]) {
                auto pp = get_middle(P, Q);
                sym_cnt[pp]+=2;
            }
            dist[d].insert(P);
        } else if (t == 2) {
            cnt--;
            LL d = P.norm();
            dist[d].erase(P);
            sym_cnt[{x/g, y/g}]--;
            for (auto Q : dist[d]) {
                auto pp = get_middle(P, Q);
                sym_cnt[pp]-=2;
            }
        } else {
            cout << cnt - sym_cnt[{x/g, y/g}] << "\n";
        }
    }
}