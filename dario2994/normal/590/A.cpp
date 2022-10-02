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

const int MAXN = 51;
char mat[MAXN][MAXN];
char imat[MAXN][MAXN];

int relation(pair<int,int> A, pair<int,int> B) {
    if (A.first == B.first and A.second == B.second) return 5;
    if (A.first <= B.first and B.second <= A.second) return 1;
    if (B.first <= A.first and A.second <= B.second) return -1;
    return 0;
}

bool check(int N, int M) {
    vector<pair<int,int>> vec(N);
    for (int i = 0; i < N; i++) {
        int ff = -1;
        int ll = -1;
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'B') {
                ll = j;
                if (ff == -1) ff = j;
            }
        }
        if (ff == -1) vec[i] = {-1, -1};
        else {
            vec[i] = {ff, ll};
            for (int j = ff; j <= ll; j++) {
                if (mat[i][j] != 'B') return false;
            }
        }
    }
    int ff = -1;
    int ll = -1;
    for (int i = 0; i < N; i++) {
        if (vec[i] != pair<int,int>{-1, -1}) {
            ll = i;
            if (ff == -1) ff = i;
        }
    }
    for (int i = ff; i <= ll; i++) if (vec[i] == pair<int,int>{-1, -1}) return false;

    int cc = -1;
    for (int i = ff + 1; i <= ll; i++) {
        int c = relation(vec[i-1], vec[i]);
        if (c == 5) continue;
        if (c == 0) return false;
        if (c < cc) return false;
        cc = c;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<int> vec(N+2);
    for (int i = 1; i <= N; i++) cin >> vec[i];
    vec[0] = vec[1], vec[N+1] = vec[N];
    int iter = 0;
    for (int i = 0; i <= N+1; i++) {
        if (vec[i] != vec[i+1]) {
            int it = i;
            while (i < N+1 and vec[i] != vec[i+1]) i++;
            if ((i-it)%2) {
                for (int j = it; j < i; j++) vec[j] = vec[i];
                iter = max(iter, (i-it+1)/2);
                i--;
            } else {
                int m = (it+i)/2;
                for (int j = it; j < m; j++) vec[j] = vec[it-1];
                for (int j = m; j < i; j++) vec[j] = vec[i];
                iter = max(iter, (i-it)/2);
                i--;
            }
        } else {
            int it = i;
            while (i < N+1 and vec[it] == vec[i+1]) i++; // skipping stuff
        }
    }
    cout << iter << "\n";
    for (int i = 1; i <= N; i++) cout << vec[i] << " ";
    cout << "\n";
}