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
    // ifstream input_from_file("input.txt");
    // #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

pair<int,int> ask(vector<int> val) {
    sort(val.begin(), val.end());
    cout << "? ";
    for (int x: val) cout << x << " ";
    cout << "\n";
    cout.flush();
    int pos, z;
    cin >> pos >> z;
    if (pos == -1) exit(0);
    return {pos, z};
}

void conclude(int m) {
    cout << "! " << m << "\n";
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        conclude(1);
        return 0;
    }
    vector<int> val(n+1, -1); // -1 = unknown, -2 = below, -3 = above
    for (int i = 0; i < n-(k-1); i++) {
        vector<int> query;
        for (int it = 1; it <= n and SZ(query) < k; it++) {
            if (val[it] == -1) query.push_back(it);
        }
        auto pp = ask(query);
        val[pp.first] = pp.second;
    }
    int u=-1, v=-1;
    for (int i = 1; i <= n; i++) {
        if (val[i] != -1) {
            if (u == -1) u = i;
            else v = i;
        }
    }
    // cout << "UFF" << endl;
    if (val[u] > val[v]) swap(u, v);
    vector<int> bef_aft;
    for (int i = 1; i <= n; i++) {
        if (val[i] == -1) bef_aft.push_back(i);
    }
    assert(SZ(bef_aft) == k-1);
    for (int i = 0; i < k-1; i++) {
        vector<int> query = {u, v};
        for (int j = 1; j < k-1; j++) query.push_back(bef_aft[(i+j)%(k-1)]);
        // dbg(query);
        auto pp = ask(query);
        if (pp.first == u) val[bef_aft[i]] = -3;
        else val[bef_aft[i]] = -2;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) res += val[i] == -2;
    conclude(res);
}
// 4 3
// 1 2
// 4 9