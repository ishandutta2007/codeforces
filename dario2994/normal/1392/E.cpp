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

const int MAXN = 30;
LL mat[MAXN][MAXN];
typedef pair<int,int> pii;


int main() {
    int N;
    cin >> N;
    for (int s = 2; s <= 2*N; s++) {
        for (int i = 1; i <= N; i++) {
            int j = s-i;
            if (j < 1 or j > N) continue;
            mat[i][j] = (i%2 == 0)?(1ll<<(s-2)):0;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cout << mat[i][j] << " ";
        cout << endl;
    }
    int q;
    cin >> q;
    for (int it = 0; it < q; it++) {
        LL sum;
        cin >> sum;
        sum /= 2;
        vector<pii> ans;
        ans.emplace_back(1, 1);
        int x = 1, y = 1;
        for (int i = 2; i <= 2*N-1; i++) {
            LL parity  = sum % 2;
            sum /= 2;
            if (x == N) {
                y++;
            } else if (y == N) x++;
            else if ((mat[x+1][y] != 0) == parity) x++;
            else y++;
            ans.push_back({x, y});
        }
        for (auto pp: ans) cout << pp.first << " " << pp.second << "\n";
        cout << endl;
    }
}