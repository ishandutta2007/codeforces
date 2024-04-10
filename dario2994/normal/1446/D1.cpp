#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// void erase_ms(multiset<int>& ms, int x) {
    // auto it = ms.find(x);
    // if (it == ms.end()) return;
    // ms.erase(it);
// }

int slow_solve(vector<int> A) {
    int N = A.size();
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            map<int,int> MM;
            for (int k = i; k <= j; k++) MM[A[k]]++;
            int max_val = -1;
            int max_num = 1;
            for (auto pp: MM) {
                if (pp.second > max_val) max_val = pp.second, max_num = 0;
                if (pp.second == max_val) max_num++;
            }
            if (max_num > 1) res = max(res, j-i+1);
        }
    }
    return res;
}

const int MAXN = 200100;
int occ[MAXN];
int occ_x[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    // cout << slow_solve(A) << "\n";
    bool all_equal = true;
    for (int i = 0; i < N; i++) all_equal &= A[i] == A[0];
    if (all_equal) {
        cout << 0 << "\n";
        return 0;
    }

    int curr_best = -1;
    multiset<int> ms;
    vector<bool> is_unique(N, false);
    vector<int> uniq_val(N, -1);
    for (int i = 0; i < N; i++) {
        // erase_ms(ms, occ[A[i]]); // not necessary!
        occ[A[i]]++;
        ms.insert(occ[A[i]]);
        if (ms.count(*ms.rbegin()) > 1) is_unique[i] = false;
        else {
            is_unique[i] = true;
            if (occ[A[i]] == *ms.rbegin()) curr_best = A[i];
            uniq_val[i] = curr_best;
        }
    }
    // dbg(is_unique);
    int l = 0;
    for (int i = 0; i < N; i++) if (!is_unique[i]) l = i;
    if (l == N-1) {
        cout << N << "\n";
        return 0;
    }
    int res = max(2, l+1);
    int x = uniq_val[l+1];
    assert(x != -1);
    // dbg(l, x);
    for (int i = 0; i < MAXN; i++) occ[i] = 0;
    const int L = 100;
    vector<vector<pair<int,int>>> vec(L+1, vector<pair<int,int>>(N+1));
    for (int i = 0; i < N; i++) {
        if (A[i] == x) occ[x]++;
        else occ[A[i]]++;
        for (int a = 1; a <= L; a++) vec[a][i+1] = {occ[a]-occ[x], i};
    }
    for (int i = 1; i <= L; i++) {
        if (i == x) continue;
        if (vec[i].empty()) continue;
        vector<pair<int,int>>& Z = vec[i];
        sort(Z.begin(), Z.end());
        // int it = -1;
        // int arg_min = -1;
        int curr_min = 1e9;
        int ris = 0;
        for (int i = 0; i < SZ(Z); i++) {
            curr_min = min(curr_min, Z[i].second);
            int q = Z[i].second - curr_min;
            ris = max(ris, q);
        }
        res = max(res, ris);
    }
    cout << res << "\n";
}