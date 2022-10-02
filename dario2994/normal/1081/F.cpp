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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 400;
int N;
int curr;


int X[MAXN];
int false_query(int l, int r) {
    if (rand()%2) {
        for (int i = 1; i <= r; i++) X[i] = 1-X[i];
    } else for (int i = l; i <= N; i++) X[i] = 1-X[i];
    int res = 0;
    for (int i = 1; i <= N; i++) res += X[i];
    return res;
}

int query(int l, int r) {
    assert(1 <= l and r <= N);
    assert(l <= r);
    cout << "? " << l << " " << r << endl;

    // return false_query(l, r);
    int ans;
    cin >> ans;
    assert(ans != -1);
    return ans;
}

pair<int,int> get_ans(int l, int r) {
    assert(1 <= l and r <= N);
    assert(l <= r);
    assert(r%2 != (N+1-l) % 2);
    int ll = 0, rr = 0;

    pair<int,int> ans = {-1, -1};
    while (ll%2 != 0 or rr%2 != 0 or (ll == 0 and rr == 0)) {
        int val = query(l, r);
        bool ch = curr%2 != val%2;
        if (ch == r%2) {
            rr++;
            if (ans.second == -1) ans = {1, (r-(val-curr))/2};
        } else {
            ll++;
            if (ans.second == -1) ans = {-1, (N+1-l-(val-curr))/2};
        }
        curr = val;
    }
    return ans;
}

int get_pref(int r) {
    assert(r >= 2);
    int l = -1;
    if (N % 2) l = r-1;
    else l = r;
    pair<int,int> pp = get_ans(l, r);
    while (pp.first != 1) pp = get_ans(l, r);
    return pp.second;
}

int get_suff(int l) {
    int r = -1;
    if (N % 2) r = l+1;
    else r = l;
    pair<int,int> pp = get_ans(l, r);
    while (pp.first != -1) pp = get_ans(l, r);
    return pp.second;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N >> curr;

    // TOREMOVE
    // curr = 0;
    // for (int i = 1; i <= N; i++) cin >> X[i], curr += X[i];
    // TOREMOVE

    if (N == 1) {
        cout << "! ";
        cout << curr << endl;
        return 0;
    }

    vector<int> pref(N+1);
    for (int i = 2; i <= N; i++) pref[i] = get_pref(i);
    int sum = curr;
    vector<int> ans(N+1);
    ans[1] = sum - get_suff(2);
    ans[2] = pref[2] - ans[1];
    for (int i = 3; i <= N; i++) ans[i] = pref[i] - pref[i-1];
    cout << "! ";
    for (int i = 1; i <= N; i++) cout << ans[i];
    cout << endl;
}