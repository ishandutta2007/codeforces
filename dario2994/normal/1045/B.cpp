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

const int MAXN = 250000;
LL invpot1[MAXN], invpot2[MAXN];

vector<LL> hash_string(LL mod, LL B, const vector<int>& S) {
    int N = S.size();
    vector<LL> res(N+1, 0);
    LL pot = 1;
    for (int i = 0; i < N; i++) {
        res[i+1] = (res[i] + S[i]*pot)%mod;
        pot = (pot*B)%mod;
    }
    return res;
}

LL get_range(int a, int b, const vector<LL>& hh, const LL mod, LL* invarr) {
    LL res = hh[b+1]-hh[a];
    res = (invarr[a]*res)%mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<int> b(N);
    for (int i = 1; i < N; i++) {
        b[i-1] = a[i]-a[i-1];
    }
    b[N-1] = (a[0]-a[N-1]+M);
    vector<int> c = b;
    reverse(c.begin(), c.end());
    const LL MOD = 1104982751;
    const LL B = 432561;
    const LL INVB = 1057777903;

    const LL MOD2 = 982419349;
    const LL B2 = 414341;
    const LL INVB2 = 952838246;

    invpot1[0] = 1;
    invpot2[0] = 1;
    for (int i = 0; i < MAXN-1; i++) {
        invpot1[i+1] = (invpot1[i] * INVB) % MOD;
        invpot2[i+1] = (invpot2[i] * INVB2) % MOD2;
    }

    // dbg_var(b);
    // dbg_var(c);
    auto hb = hash_string(MOD, B, b);
    auto hc = hash_string(MOD, B, c);
    auto hb2 = hash_string(MOD2, B2, b);
    auto hc2 = hash_string(MOD2, B2, c);
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (get_range(0, N-1-i, hb, MOD, invpot1) == get_range(i, N-1, hc, MOD, invpot1) and
            get_range(N-i, N-1, hb, MOD, invpot1) == get_range(0, i-1, hc, MOD, invpot1) and
            get_range(0, N-1-i, hb2, MOD2, invpot2) == get_range(i, N-1, hc2, MOD2, invpot2) and
            get_range(N-i, N-1, hb2, MOD2, invpot2) == get_range(0, i-1, hc2, MOD2, invpot2)) {
            ans.push_back((a[0] + a[(N-i)%N]) % M);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    if (!ans.empty()) {
        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
}