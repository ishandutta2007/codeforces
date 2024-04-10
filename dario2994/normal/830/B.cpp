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
    stable_sort(ord.begin(), ord.end(), compare);
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

#define INF 1<<30
#define eps 1e-9

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
    // container[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. container[2] contains exactly the value of entry[2], whereas
    // container[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<Value> container;
};

// This should not compile if used.
const int MAXN = 150000;

int N;
int cards[MAXN];

LL SlowSimul() {
    const int NO_CARD = 1e9+3;
    LL res = 0;
    int pos = 0;
    for (int it = 0; it < N; it++) {
        int actmin = 1e9+1;
        for (int j = 0; j < N; j++) MinPlace(actmin, cards[j]);
        while (cards[pos] != actmin) {
            if (cards[pos] != NO_CARD) res++;
            pos++;
            pos %= N;
        }
        res++;
        cards[pos] = NO_CARD;
        pos++;
        pos %= N;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in online problems!

    cin >> N;
    for (int i = 0; i < N; i++) cin >> cards[i];

    auto ord = SortIndex(N, [&](int i, int j) {
        return cards[i] < cards[j];
    });

    vector<vector<int>> ord_vals;
    for (int i = 0; i < N; i++) {
        vector<int> poss;
        poss.push_back(ord[i]);
        i++;
        while (i < N and cards[ord[i]] == cards[ord[i-1]]) {
            poss.push_back(ord[i]);
            i++;
        }
        i--;
        ord_vals.push_back(poss);
    }

    vector<int> temppp(N, 1);
    Fenwick<int> removed(temppp);

    LL res = 1 + ord[0];
    removed.Set(ord[0], 0);

    int prev = ord[0];
    int val_it = 0; 
    int pos_it = 1;
    int done_cnt = 1;
    
    for (int i = 1; i < N; i++) {
        if (done_cnt == (int)ord_vals[val_it].size()) {
            done_cnt = 0;
            val_it++;
            pos_it = std::lower_bound (ord_vals[val_it].begin(), ord_vals[val_it].end(), prev) - ord_vals[val_it].begin();
            if (pos_it == (int)ord_vals[val_it].size()) pos_it = 0;
        }
        int curr = ord_vals[val_it][pos_it];
        
        if (prev > curr) {
            res += (LL)removed.GetRange(prev, N-1);
            prev = 0;
        }
        res += (LL)removed.GetRange(prev, curr);
        removed.Set(curr, 0);

        prev = curr;
        pos_it++;
        pos_it %= ord_vals[val_it].size();
        done_cnt++;
    }
    cout << res;

    // cout << endl << SlowSimul() << endl;
}