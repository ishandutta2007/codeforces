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

const int MAXN = 600;
vector<int> aa[MAXN];

bool open[MAXN], closed[MAXN];
vector<int> ciclo;
bool ciclo_trovato = false;

bool dfs(int v) {
    open[v] = true;
    for (int a : aa[v]) {
        if (closed[a]) continue;
        if (open[a]) {
            ciclo = {a};
            return true;
        }
        if (dfs(a)) {
            if (!ciclo_trovato) ciclo.push_back(a);
            if (v == ciclo[0]) ciclo_trovato = true;
            return true;
        }
    }
    closed[v] = true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
    }
    for (int v = 1; v <= N; v++) {
        if (!closed[v]) {
            if (dfs(v)) break;
        }
    }
    if (ciclo.empty()) {
        cout << "YES\n";
        return 0;
    }
    reverse(ciclo.begin(), ciclo.end());
    vector<int> copia = ciclo;
    for (int i = 0; i < SZ(copia); i++) {
        int a = copia[i], b = copia[(i+1) % SZ(copia)];
        aa[a].erase(remove(aa[a].begin(), aa[a].end(), b));


        bool works = true;
        ciclo.clear();
        for (int v = 1; v <= N; v++) open[v] = closed[v] = 0;
        for (int v = 1; v <= N; v++) {
            if (!closed[v]) {
                if (dfs(v)) {
                    works = false;
                    break;
                }
            }
        }
        if (works) {
            cout << "YES\n";
            return 0;
        }
        
        aa[a].push_back(b);
    }
    cout << "NO\n";
}