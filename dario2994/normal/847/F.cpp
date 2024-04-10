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


bool Chance(int x, int K, int R, vector<int> votes, vector<int> ord) {
    if (votes[x] == 0 and R == 0) return false;
    int pos = 0;
    for (int i = 0; i < (int)ord.size(); i++) {
        if (ord[i] == x) pos = i;
    }
    if (pos < K) return true;
    return (votes[ord[K-1]] + 1 - votes[x]) <= R;
}

bool Always(int x, int K, int R, vector<int> votes, vector<int> ord) {
    if (votes[x] == 0) return (ord.size() == 1 and R > 0);
    int pos = 0;
    for (int i = 0; i < (int)ord.size(); i++) {
        if (ord[i] == x) pos = i;
    }

    if (pos >= K) return false;
    if (K == (int)ord.size()) return true;
    for (int p = pos+1; p <= K; p++) {
        if (votes[x]+1-votes[ord[p]] > R) return true;
        R -= votes[x]+1-votes[ord[p]];
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, K, M, A;
    cin >> N >> K >> M >> A;
    vector<int> votes(N), last_vote(N);
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        x--;
        votes[x]++, last_vote[x] = i;
    }
    auto ord = SortIndex(N, [&](int i, int j) {
        if (votes[i] == votes[j]) return last_vote[i] < last_vote[j];
        return votes[i] > votes[j];
    });
    for (int i = 0; i < N; i++) {
        if (Always(i, K, M-A, votes, ord)) cout << "1";
        else if (Chance(i, K, M-A, votes, ord)) cout << "2";
        else cout << "3";
        cout << " ";
    }
}