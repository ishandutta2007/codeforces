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

bool FillOccurrences(const string& S, vector<int>& occ) {
    for (int i = 0; i < SZ(S); i++) {
        int c = S[i]-'a';
        if (occ[c] != -1) return false;
        occ[c] = i;
    }
    return true;
}

const int MAXN = 100100;
vector<int> aa[MAXN];
vector<int> diff[MAXN];

int component[MAXN];
int pos[MAXN];

bool Dfs(int v) {
    for (int i = 0; i < (int)aa[v].size(); i++) {
        int a = aa[v][i];
        int d = diff[v][i];
        if (component[a] == -1) {
            component[a] = component[v];
            pos[a] = pos[v] + d;
            if (!Dfs(a)) return false;
        } else if (pos[a] != pos[v] + d) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<string> ss(N);
    for (int i = 0; i < N; i++) cin >> ss[i];
    vector<vector<int>> occ(N, vector<int>(26, -1));
    for (int i = 0; i < N; i++) {
        if (!FillOccurrences(ss[i], occ[i])) {
            cout << "NO\n";
            return 0;
        }
    }
    for (int c = 0; c < 26; c++) {
        int id_first = N;
        for (int i = 0; i < N; i++) {
            if (occ[i][c] != -1) {
                id_first = i;
                break;
            }
        }
        for (int i = id_first+1; i < N; i++) {
            if (occ[i][c] != -1) {
                aa[i].push_back(id_first);
                diff[i].push_back(occ[i][c]-occ[id_first][c]);
                aa[id_first].push_back(i);
                diff[id_first].push_back(occ[id_first][c]-occ[i][c]);
            }
        }
    }
    // for (int i = 0; i < N; i++){
        // dbg_var(aa[i]);
        // dbg_var(diff[i]);
    // }
    // return 0;
    for (int i = 0; i < N; i++) {
        component[i] = -1;
    }
    int comp_num = 0;
    for (int i = 0; i < N; i++) {
        if (component[i] == -1) {
            component[i] = comp_num;
            comp_num++;
            pos[i] = 0;
            if (!Dfs(i)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    vector<int> smallest(comp_num, 1e8);
    vector<int> highest(comp_num, -1e8);
    for (int i = 0; i < N; i++) {
        int comp = component[i];
        // cout << comp << endl;
        smallest[comp] = min(smallest[comp], pos[i]);
        highest[comp] = max(highest[comp], pos[i] + ((int)ss[i].size()));
    }
    vector<string> conn_comp(comp_num);
    for (int i = 0; i < comp_num; i++) conn_comp[i].resize(highest[i]-smallest[i], 'X');
    for (int i = 0; i < N; i++) {
        int comp = component[i];
        for (int j = 0; j < SZ(ss[i]); j++) {
            int index = j + pos[i]-smallest[comp];
            char c = conn_comp[comp][index];
            if (c != 'X' and c != ss[i][j]) {
                cout << "NO\n";
                return 0;
            }
            conn_comp[comp][index] = ss[i][j];
        }
    }
    sort(conn_comp.begin(), conn_comp.end());
    for (const string& res : conn_comp) cout << res;
    cout << "\n";
}