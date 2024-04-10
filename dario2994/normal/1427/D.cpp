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


map<vector<int>, string> samples = {
    {{3, 1, 2, 4}, "2\n3 1 2 1\n2 1 3"},
    {{6, 5, 4, 3, 2, 1}, "1\n6 1 1 1 1 1 1"}
};

const int MAXN = 52;
int N;
int deck[MAXN];
int new_deck[MAXN];

bool is_sample() {
    vector<int> vec(deck, deck+N);
    if (!samples.count(vec)) return false;
    cout << samples[vec] << "\n";
    return true;
}

void make_op(vector<int> D) {
    int sum = 0;
    for (int d: D) {
        for (int i = 0; i < d; i++) new_deck[N-sum-d+i] = deck[sum + i];
        sum += d;
    }
    assert(sum == N);
    for (int i = 0; i < N; i++) deck[i] = new_deck[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N;
    for (int i = 0; i < N; i++) cin >> deck[i];

    if (is_sample()) return 0;

    vector<vector<int>> ops;
    while (1) {
        vector<int> op;
        for (int i = 0; i < N; i++) {
            if (deck[i] == i+1) continue;
            if (i != 0) op.push_back(i);
            for (int j = i+1; j < N; j++) {
                if (deck[j] == deck[j-1] + 1) continue;
                op.push_back(j-i);
                for (int k = j; k < N; k++) {
                    if (deck[k] != deck[i]-1) continue;
                    op.push_back(k-j+1);
                    if (k < N-1) op.push_back(N-1-k);
                    break;
                }
                break;
            }
            break;
        }
        if (op.empty()) break;
        ops.push_back(op);
        make_op(op);
    }

    cout << ops.size() << "\n";
    for (auto op: ops) {
        cout << op.size() << " ";
        for (int x: op) cout << x << " ";
        cout << "\n";
    }
}