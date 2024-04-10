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

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

struct State {
    LL l, r;
    int cnt;
    LL sum;
    State(LL sum, LL N): l(1), r(N), cnt(0), sum(sum) {}
    LL diff() {
        assert(l < r);
        return (l+r-1)/2;
    }
    LL question() {
        if (cnt%2) return sum - diff();
        return sum + diff();
    }
    void update(bool ans) {
        LL pos = diff();
        sum = question();
        cnt++;
        if (ans) r = pos;
        else l = pos+1;
    }
};

LL starting_point(LL N) {
    State S(0, N);
    LL min_s = 0, max_s = 0;
    while (S.l != S.r) {
        S.update(false);
        // cout << S.sum << endl;
        min_s = min(min_s, S.sum);
        max_s = max(max_s, S.sum);
    }
    // cout << min_s << " " << max_s << endl;
    assert(max_s - min_s == N-1);
    return 1-min_s;
}

void solve(LL N, LL C) {
    LL sp = starting_point(N);
    
    State S(sp, N);
    set<LL> visited;
    LL last = sp;
    visited.insert(last);
    while (S.l != S.r) {
        cout << S.sum-sp << endl;
        LL curr = S.question();
        assert(1 <= curr and curr <= N);
        assert(visited.insert(curr).second);

        if (llabs(last-curr) < C) S.update(false);
        else S.update(true);
        last = curr;
    }
    assert(S.l == C);
    assert(S.cnt <= 62);
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        LL N;
        cin >> N;
        State S(starting_point(N), N);
        cout << "? " << starting_point(N) << endl;
        int ans;
        cin >> ans;
        while (S.l != S.r) {
            cout << "? " << S.question() << endl;
            cin >> ans;
            S.update(ans);
        }
        cout << "= " << S.l << endl;
    }

    // LL N = 1e18;
    // LL C = N/2;
    // solve(N, C);
    
    // for (int i = 1; i <= 1000; i++) for (int j = 1; j <= i; j++) solve(i, j);
    
}