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

const int MAXN = 30100;
int N, M;

bool pos[MAXN];
int next_pos[MAXN];

void get_poss(vector<int> q) {
    int bigger = 0;
    for (int x : q) bigger += x;
    for (int i = 0; i <= N; i++) pos[i] = false;
    pos[0] = true;
    for (int c : q) {
        for (int i = N; i >= 0; i--) {
            if (!pos[i]) continue;
            if (i+c > N) bigger = min(bigger, i + c);
            else pos[i+c] = true;
        }
    }
    if (bigger >= N+1) next_pos[N+1] = bigger;
    else next_pos[N+1] = 1e6;
    for (int i = N; i >= 0; i--) next_pos[i] = pos[i]?i:next_pos[i+1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int T;
    cin >> T;
    for (int tt = 0; tt < T; tt++) {
        int K;
        cin >> N >> M >> K;
        string S;
        cin >> S;
        vector<int> q(26, 0);
        for (int i = 0; i < K; i++) q[S[i]-'A']++;
        LL res = ((LL)N)*M;
        for (int c = 0; c < 26; c++) {
            int cnt = q[c];
            q[c] = 0;
            get_poss(q);
            q[c] = cnt;
            for (int a = 0; a <= N; a++) {
                int k = next_pos[N-a];
                int b = max(0, M + k- K + q[c]);
                // dbg_var(q[c]);
                // cout << a << " " << b << " " << k << " " << -K + q[c] << endl;
                if (a+b <= q[c]) res = min(res, ((LL)a)*b);
            }
        }
        cout << res << "\n";
    }
}