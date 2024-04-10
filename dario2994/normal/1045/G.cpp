#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

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


// end fenwick


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int N, K;
    cin >> N >> K;
    vector<int> x(N), r(N), q(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> r[i] >> q[i];

    set<int> coord;
    for (int i = 0; i < N; i++) coord.insert(x[i]);
    vector<int> coord_vec(coord.begin(), coord.end());
    int C = coord_vec.size();
    vector<int> xx(N), le(N), ri(N);
    for (int i = 0; i < N; i++) {
        xx[i] = lower_bound(coord_vec.begin(), coord_vec.end(), x[i]) - coord_vec.begin();
        le[i] = lower_bound(coord_vec.begin(), coord_vec.end(), x[i] - r[i]) - coord_vec.begin();
        ri[i] = (upper_bound(coord_vec.begin(), coord_vec.end(), x[i] + r[i]) - coord_vec.begin()) - 1;
    }

    vector<int> o(N);
    for (int i = 0; i < N; i++) o[i] = i;
    sort(o.begin(), o.end(), [&] (int i, int j) {return q[i] < q[j];});
    int aq = -1;
    LL res = 0;
    Fenwick<int> ff(C);
    for (int i = 0; i < N; i++) {
        if (aq == q[o[i]]) continue;
        aq = q[o[i]];
        vector<int> b;
        int k = i;
        while (k < N and q[o[k]] <= aq + K) b.push_back(o[k]), k++;
        k = i-1;
        while (k >= 0 and q[o[k]] >= aq - K) b.push_back(o[k]), k--;
        sort(b.begin(), b.end(), [&] (int i, int j) {if (r[i] == r[j]) return q[i] < q[j]; return r[i] > r[j];});
        for (int a : b) {
            if (q[a] == aq) {
                res += ff.GetRange(le[a], ri[a]);
            }
            ff.Add(xx[a], 1);
        }
        for (int a : b) {
            ff.Add(xx[a], -1);
        }
    }
    cout << res << "\n";
}