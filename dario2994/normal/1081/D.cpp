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

const int MAXN = 110000;

int ff[MAXN];
int sp[MAXN];

int anc(int v) {
    // dbg_var(v);
    // cout << v << " " << ff[v] << endl;
    if (ff[v] != v) ff[v] = anc(ff[v]);
    return ff[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) ff[i] = i;

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        sp[x]++;
    }

    vector<pair<int, pair<int,int>>> edges;
    for (int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        int w = e.first;
        int a = e.second.first;
        int b = e.second.second;
        // cout << "BEFORE" << a << " " << b << endl;
        a = anc(a);
        // cout << "HELLO" << endl;
         b = anc(b);

        // cout << a << " " << b << endl;
        if (a == b) continue; // nothing happens here
        ff[b] = a;
        sp[a] += sp[b];
        if (sp[a] == K) {
            for (int i = 1; i <= K; i++) cout << w << " ";
            cout << "\n";
            return 0;
        }
    }
}