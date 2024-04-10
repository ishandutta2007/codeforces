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

struct Lista {
    Lista() {}
    Lista(int N) : val(N, 0), sz(0) {}
    vector<bool> val;
    int sz;
    void Togli(int x) {
        if (val[x]) {
            sz--, val[x] = false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<pair<int, Lista>> liste;
    for (int i = 0; i < N; i++) {
        int s = 0;
        while (s < N-1) {
            if (s != 0) {
                char c;
                cin >> c;
            }
            liste.push_back({i, Lista(N)});
            if ((int)liste.size() > 2*(N-1)) {
                cout << -1 << "\n";
                return 0;
            }
            int k;
            cin >> k;
            s += k;
            for (int j = 0; j < k; j++) {
                char c;
                cin >> c;
                int x;
                cin >> x;
                liste.back().second.val[x-1] = true;
                liste.back().second.sz++;
            }
        }
    }
    if ((int)liste.size() != 2*(N-1)) {
        cout << -1 << "\n";
        return 0;
    }

    // for (auto X : liste) {
        // cout << X.first << ": ";
        // for (int i = 0; i < N; i++) {
            // if (X.second.val[i]) {
                // cout << i << " ";
            // }
        // }
        // cout << "\n";
    // }
    
    vector<pair<int,int>> edges;
    bool modified = true;
    while (modified) {
        modified = false;
        for (auto& P : liste) {
            int u = P.first;
            auto& lista = P.second;
            if (lista.sz == 1) {
                modified = true;
                int v = -1;
                for (int i = 0; i < N; i++) {
                    if (lista.val[i]) v = i;
                }
                lista.Togli(v);
                // cout << "PRIMA\n";
                // cout << u << " " << v << endl;
                // for (auto X : liste) {
                    // if (X.first != 4) continue;
                    // cout << X.first << ": ";
                    // for (int i = 0; i < N; i++) {
                        // if (X.second.val[i]) {
                            // cout << i << " ";
                        // }
                    // }
                    // cout << "\n";
                // }

                for (auto& Q : liste) {
                    auto& lista2 = Q.second;
                    if (Q.first == v) {
                        if (lista2.sz != 0 and lista2.sz != N - 1 - (int)edges.size()) {
                            // cout << "CIAO";
                            cout << "-1\n";
                            return 0;
                        }
                        lista2 = Lista(N);
                    }

                    if (lista2.val[u] != lista2.val[v]) {
                        // cout << "BONO" << Q.first << " " << lista2.sz;
                        cout << "-1\n";
                        return 0;
                    }
                    lista2.Togli(v);
                }
                edges.push_back({u, v});

                // cout << "DOPO\n";
                // for (auto X : liste) {
                    // if (X.first != 4) continue;
                    // cout << X.first << ": ";
                    // for (int i = 0; i < N; i++) {
                        // if (X.second.val[i]) {
                            // cout << i << " ";
                        // }
                    // }
                    // cout << "\n";
                // }
                break;
            }
        }
    }
    if ((int)edges.size() != N-1) {
        // cout << "COSO";
        cout << -1 << "\n";
        return 0;
    }
    cout << N-1 << "\n";
    for (auto e : edges) cout << e.first+1 << " " << e.second+1 << "\n";
}