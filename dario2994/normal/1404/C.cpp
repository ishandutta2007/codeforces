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

// A structure able to perform the following operation on an array A:
// 1. Sum x to A[i].
// 2. Get the sum A[l] + A[l+1] + ... + A[r].
// Both the operation are O(log(N)).
// Everything is 0-based.
template <typename Value>
class Fenwick {
  public:
    // The Fenwick tree is initialized leaving all entries with the value 0.
    Fenwick(int N) :
        size(N),
        max_pow2(log2(N)),
        container(N, 0) {}

    // Initialize the Fenwick tree with the given values as entries.
    Fenwick(const vector<Value>& initial_values) :
            Fenwick(initial_values.size()) {
        for (int p = 0; p < size; p++) {
            int q = p | (p+1);
            container[p] += initial_values[p];
            if (q < size) container[q] += container[p];
        }
    }

    // Add x to the p-th entry.
    void Add(int p, Value x) {
        for (; p < size; p |= (p+1)) container[p] += x;
    }

    // Get the sum on the interval [l, r].
    Value GetRange(int l, int r) {
        if (l > 0) return GetRange(0, r) - GetRange(0, l-1);
        Value res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += container[r];
        return res;
    }

    // Get the value of the p-th entry.
    Value Get(int p) {
        return GetRange(p, p);
    }
    
    // Get the smallest p >= 0 such that GetRange(0, p) >= x.
    // If such a p does not exist, it returns size.
    // ACHTUNG: Works only if all values are nonnegative.
    int LowerBound(Value x) {
        Value sum = 0;
        int res = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(res + i - 1 < size and sum + container[res + i - 1] < x) {
                sum += container[res + i - 1];
                res += i;
            }
        }
        return res;
    }

    // Set the p-th entry to x.
    void Set(int p, Value x) {
        Add(p, x - Get(p));
    }

    // Prints the current state of the Fenwick tree.
    void Debug() {
        cout << "Internal container representation (size = " << size << "):\n";
        for (int i = 0; i < size; i++) cout << container[i] << " ";
        cout << "\nValues of the entries:\n";
        for (int i = 0; i < size; i++) cout << Get(i) << " ";
        cout << "\n";
        cout.flush();
    }
    
  private:
    int size; // = container.size() (just to have a shorter name).
    int max_pow2; // = maximum integer such that (1 << max_pow2) <= N.
    // container[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. container[2] contains exactly the value of entry[2], whereas
    // container[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<Value> container;
};

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int pot = 1<<19;
int ff[2*pot];
int flag[2*pot];

void deflag(int v) {
    flag[2*v] += flag[v], ff[2*v] += flag[v];
    flag[2*v+1] += flag[v], ff[2*v+1] += flag[v];
    flag[v] = 0;
}

void decrement(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return;
    if (a <= l and r <= b) {
        flag[v]--;
        ff[v]--;
        return;
    }
    deflag(v);
    int m = (l+r)/2;
    decrement(2*v, l, m, a, b);
    decrement(2*v+1, m+1, r, a, b);
    ff[v] = min(ff[2*v], ff[2*v+1]);
}

int get_min_pos() {
    int v = 1;
    while (v < pot) {
        deflag(v);
        if (ff[2*v] < ff[2*v+1]) v = 2*v;
        else v = 2*v+1;
    }
    return v - pot;
}

void update(int v, int val) {
    vector<int> path;
    v += pot;
    int u = v;
    while (u > 1) {
        u /= 2;
        path.push_back(u);
    }
    reverse(path.begin(), path.end());
    for (int u: path) deflag(u);
    flag[v] = 0;
    ff[v] = val;
    reverse(path.begin(), path.end());
    for (int u: path) ff[u] = min(ff[2*u], ff[2*u+1]);
}

void decrement_after(int pos) {
    decrement(1, 0, pot-1, pos, pot-1);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int i = 0; i < 2*pot; i++) ff[i] = 1e8;

    int N;
    int Q;
    cin >> N >> Q;
    vector<int> a(N+1);
    vector<int> from(N+1, -10);
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = N; i >= 1; i--) {
        if (i-a[i] >= 0) update(i, i-a[i]);
        while (ff[1] == 0) { // min is 0
            int pos = get_min_pos();
            from[pos] = i;
            update(pos, 1e8);
            decrement_after(pos);
        }
    }
    // dbg(from);
    vector<int> ans(Q);
    Fenwick<int> fen(N+5);
    vector<pair<int,int>> queries;
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a+1, N-b});
    }
    vector<int> ord(Q);
    for (int i = 0; i < Q; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return queries[i] > queries[j];
    });
    vector<vector<int>> with_this_from(N+1);
    for (int i = 1; i <= N; i++) {
        if (from[i] > 0) with_this_from[from[i]].push_back(i);
    }
    int curr = N;
    for (int it: ord) {
        int l = queries[it].first, r = queries[it].second;
        while (curr >= l) { 
            while (!with_this_from[curr].empty()) {//wrong
                fen.Add(with_this_from[curr].back(), 1);
                with_this_from[curr].pop_back();
            }
            curr--;
        }
        ans[it] = fen.GetRange(l, r);
    }

    for (int i = 0; i < Q; i++) cout << ans[i] << "\n";
}