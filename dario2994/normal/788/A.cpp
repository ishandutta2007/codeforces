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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define endl "\n";

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = 100010;
int N;
LL a[MAXN];
LL b[MAXN];

LL sign(int x) {
    if (x%2) return -1;
    return 1;
}

LL res = 0;
void dfs(int s, int e) {
    if (s == e) {
        MaxPlace(res, b[s]);
        return;
    }
    int m = (s+e)/2;
    dfs(s, m);
    dfs(m+1, e);
    LL best_before_pari = 0;
    LL best_before_dispari = 0;
    LL best_after = 0;
    LL worst_after = 0;
    LL curr_before = 0;
    LL curr_after = 0;
    for (int i = m; i >= s; i--) {
        curr_before = b[i] - curr_before;
        if ((m+1-i) % 2 == 0) MaxPlace(best_before_pari, curr_before);
        else MaxPlace(best_before_dispari, curr_before);
    }
    for (int i = m+1; i <= e; i++) {
        curr_after += b[i] * sign(i) * sign(m+1);
        MaxPlace(best_after, curr_after);
        MinPlace(worst_after, curr_after);
    }
    
    // if (e-s == 4) {
        // cout << "DEB" << endl;
        // cout << curr_before << endl;
        // cout << best_before_pari << " " << best_before_dispari << endl;
    // }
    MaxPlace(res, max(best_before_pari+best_after, best_before_dispari - worst_after));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N-1; i++) {
        b[i] = a[i]-a[i+1];
        if (b[i] < 0) b[i] *= -1ll;
        // cout << "B: " << b[i] << endl;
    }
    dfs(0, N-2);
    cout << res;
    // LL real_res = 0;
    // for (int l = 0; l < N-1; l++) {
        // for (int r = l+1; r < N; r++) {
            // LL ris = 0;
            // for (int i = l; i < r; i++) {
                // ris += sign(i)*sign(l)*abs(a[i]-a[i+1]);
            // }
            // MaxPlace(real_res, ris);
        // }
    // }
    // cout << "\n" << real_res << endl;
}