#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
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



const int MAXN = 1<<17;
int n;
int p[MAXN];
int skip[MAXN]; // skip[i] is the first index > i so that p[i, skip[i]] is an
                // interval in p[i, n].
                // skip[n] = n+1.

Fenwick<int> fen(MAXN);

pair<int,int> tt[2*MAXN];

pair<int,int> query_tt(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return {1e9, -1e9};
    if (a <= l and r <= b) return tt[v];
    int m = (l+r)/2;
    auto pp_l = query_tt(2*v, l, m, a, b);
    auto pp_r = query_tt(2*v+1, m+1, r, a, b);
    return {min(pp_l.first, pp_r.first), max(pp_l.second, pp_r.second)};
}

void init_tt() {
    for (int i = 1; i <= n; i++) tt[MAXN + i] = {p[i], p[i]};
    for (int v = MAXN-1; v >= 1; v--) {
        auto pp_l = tt[2*v];
        auto pp_r = tt[2*v+1];
        tt[v] = {min(pp_l.first, pp_r.first), max(pp_l.second, pp_r.second)};
    }
}

bool is_interval(int a, int b) {
    auto low_high = query_tt(1, 0, MAXN-1, a, b);
    return fen.GetRange(low_high.first, low_high.second) == b - a + 1;
}

namespace countpairs{
int cnt[5*MAXN];
LL res = 0;
void decrease(int id) { res -= --cnt[id]; }
void increase(int id) { res += cnt[id]++; }
};


vector<vector<int>> groups;

void solve(int l, int r) {
    // cout << l << " " << r << endl;
    vector<int> prefixes = {l};
    int dir = 0;
    vector<int> group = {l};
    auto clear_group = [&]() {
        if (2 <= (int)group.size()) groups.push_back(group);
        group.clear();
        dir = 0;
    };
    while (prefixes.back() != r) {
        int old_r = prefixes.back();
        int new_r = skip[old_r];
        if (new_r > r or !is_interval(l, new_r)) break;
        if (is_interval(old_r+1, new_r)) {
            int new_dir = (p[new_r] > p[old_r]) ? 1 : -1;
            if (dir == 0) dir = new_dir;
            if (dir != new_dir) {
                clear_group();
                dir = new_dir;
                group.push_back(old_r);
            }
        } else clear_group();
        group.push_back(new_r);
        
        prefixes.push_back(new_r);
        solve(old_r+1, new_r);
    }
    clear_group();
    for (int maybe_r: prefixes) {
        if (maybe_r != r) groups.push_back({l-1, maybe_r});
    }
    if (prefixes.back() != r) {
        int maybe_l = prefixes.back() + 1;
        solve(maybe_l, r);
        if (is_interval(maybe_l, r)) groups.push_back({maybe_l-1, r});
    }
}

LL slow(int l, int r) {
    LL res = 0;
    for (int a = l; a <= r; a++) for (int b = a; b <= r; b++) {
        res += is_interval(a, b);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    // for (int i = 1; i <= n; i++) p[i] = i;
    // random_shuffle(p+1, p + n + 1);
    init_tt();

    skip[n] = n+1;
    fen.Add(p[n], 1);
    for (int i = n-1; i >= 1; i--) {
        fen.Add(p[i], 1);
        skip[i] = i+1;
        while (!is_interval(i, skip[i])) skip[i] = skip[skip[i]];
    }
    // for (int i = 1; i <= n; i++) cout << skip[i] << "\n";

    groups.push_back({0, n});
    solve(1, n);

    // cout << groups << endl;
    // return 0;

    // auto b2 = [&](int x) { return x*(x-1) / 2; };
    // int q;
    // cin >> q;
    // while (q--) {
        // int l, r;
        // cin >> l >> r;
        // l--;
        // int res = 0;
        // for (auto gr: groups) {
            // int cnt = 0;
            // for (int x: gr) cnt += l <= x and x <= r;
            // res += b2(cnt);
        // }
        // cout << res << "\n";
    // }

    vector<vector<int>> colors(n+1);
    for (int i = 0; i < SZ(groups); i++) {
        for (int x: groups[i]) colors[x].push_back(i);
    }

    const int L = 300;
    vector<int> sector(n+1);
    sector[0] = 1;
    int sector_sum = SZ(colors[0]);
    for (int i = 1; i <= n; i++) {
        if (sector_sum + SZ(colors[i]) > L) {
            sector_sum = 0;
            sector[i] = sector[i-1] + 1;
        } else sector[i] = sector[i-1];
        sector_sum += SZ(colors[i]) + 1;
    }

    int q;
    cin >> q;
    // vector<LL> correct(q);
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // l = rand() % n + 1;
        // r = rand() % n + 1;
        // if (l > r) swap(l, r);
        // l = 1, r = n;
        queries[i][0] = l-1;
        queries[i][1] = r;
        queries[i][2] = i;
        // correct[i] = slow(l, r);
    }
    sort(queries.begin(), queries.end(), [&](auto a, auto b) {
        if (sector[a[1]] != sector[b[1]]) return sector[a[1]] < sector[b[1]];
        return a[0] < b[0];
    });

    auto _add = [&](int pos) { for (int c: colors[pos]) countpairs::increase(c); };
    auto _remove = [&](int pos) { for (int c: colors[pos]) countpairs::decrease(c); };
    vector<LL> ans(q);
    int l = 0;
    int r = -1;
    for (auto arr: queries) {
        int new_l = arr[0];
        int new_r = arr[1];
        int id = arr[2];

        while (r < new_r) _add(++r);
        while (new_l < l) _add(--l);
        while (new_r < r) _remove(r--);
        while (l < new_l) _remove(l++);
        ans[id] = countpairs::res;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << "\n";

    // assert(ans == correct);

    // for (int i = 1; i <= n; i++) cout << p[i] << " ";
    // cout << endl;
    // for (int i = 0; i < q; i++) {
        // cout << queries[i][0] << " " << queries[i][1] << ": ";
        // cout << correct[i] <<  " " << ans[i] << endl;
    // }
    
    // cout << groups << endl;
    // assert(ans == correct);

}