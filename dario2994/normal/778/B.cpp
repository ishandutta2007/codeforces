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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) cout << #x  << ": " << x << endl;
    #define dbg_vec(x) cout << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) cout << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif  

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// Inizio: 16.24

map<string, vector<short int>> vars;

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vars["?"].assign(M, 2);
    for (int i = 0; i < N; i++) {
        string varname, equality_sign;
        cin >> varname >> equality_sign;
        string x;
        cin >> x;
        vector<short int> t(M);
        if (x[0] == '0' or x[0] == '1') {
            for (int j = 0; j < M; j++) t[j] = (x[j] == '0') ? 0 : 3;
        } else {
            string op;
            string y;
            cin >> op >> y;

            std::function<int(int, int)> op_lambda = [op](int a, int b) {
                if (op == "AND") return a & b;
                if (op == "OR") return a | b;
                return a ^ b;
            };
            const auto& varx = vars.at(x);
            const auto& vary = vars.at(y);
            for (int j = 0; j < M; j++) t[j] = op_lambda(varx[j], vary[j]);
        }
        vars[varname] = t;
    }
    string minimo(M, '0');
    string massimo(M, '0');
    vector<int> occ[4];
    occ[0].assign(M, 0);
    occ[1].assign(M, 0);
    occ[2].assign(M, 0);
    occ[3].assign(M, 0);
    for (const auto& v : vars) {
        if (v.first == "?") continue;
        for (int i = 0; i < M; i++) {
            occ[(v.second)[i]][i]++;
        }
    }
    for (int i = 0; i < M; i++) {
        if (occ[1][i] > occ[2][i]) minimo[i] = '1';
        if (occ[1][i] < occ[2][i]) massimo[i] = '1';
    }
    cout << minimo << "\n" << massimo;
}