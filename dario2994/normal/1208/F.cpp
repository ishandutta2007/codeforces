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

const int MAXN = 1e6+5;
const int MAXV = 1<<22;

int A[MAXN];

int primo[MAXV], ultimo[MAXV], penultimo[MAXV];

bool works(int x) {
    for (int bb = 0; bb < MAXV; bb++) {
        if ((x&bb) != bb) continue;
        int bef = x&bb;
        int aft = x^bb;
        if (primo[bef] < penultimo[aft]) return true;
    }
    return false;
}

void aggiorna_primo(int x, int pos) {
    if (primo[x] <= pos) return;
    primo[x] = pos;
    for (int i = 0; i < 22; i++) {
        if (x&(1<<i)) aggiorna_primo(x^(1<<i), pos);
    }
}

void aggiorna_ultimo(int x, int pos) {
    if (penultimo[x] >= pos || ultimo[x] == pos) return;
    if (ultimo[x] > pos) {
        penultimo[x] = pos;
    } else ultimo[x] = pos;
    for (int i = 0; i < 22; i++) {
        if (x&(1<<i)) aggiorna_ultimo(x^(1<<i), pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    // srand(time(NULL));
    // for (int i = 0; i < N; i++) A[i] = rand()%2000000;
    for (int i = 0; i < MAXV; i++) primo[i] = N, ultimo[i] = -1, penultimo[i] = -1;
    for (int i = 0; i < N; i++) aggiorna_primo(A[i], i);
    for (int i = N-1; i >= 0; i--) aggiorna_ultimo(A[i], i);

    int res = 0;
    for (int k = 21; k >= 0; k--) {
        if (works(res^(1<<k))) res ^= (1<<k);
    }
    cout << res << "\n";

    // int slow_res = 0;
    // for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) for (int k = j+1; k < N; k++) {
        // slow_res = max(slow_res, A[i]|(A[j]&A[k]));
    // }
    // cout << slow_res << endl;
}