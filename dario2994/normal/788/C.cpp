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
const int MAXN = -1; 

bool possible[1010];
vector<int> pos, neg;


const int MAXDIN = 1000010;
int pos_doable[MAXDIN];
int neg_doable[MAXDIN];
int N, K;
const int INF = 1e9;

void fill_din(int din[], vector<int> val, int max_ris) {
    int max_it = max_ris * val.back();
    for (int v : val) {
        for (int i = v; i <= max_it; i++) {
            din[i] = min(din[i-v]+1, din[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        possible[x] = true;
    }
    if (possible[N]) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < 1010; i++) {
        if (possible[i]) {
            if (i < N) {
                neg.push_back(N-i);
            } else {
                pos.push_back(i-N);
            }
        }
    }
    sort(neg.begin(), neg.end());
    if (neg.empty() or pos.empty()) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < MAXDIN; i++) {
        pos_doable[i] = INF;
        neg_doable[i] = INF;
    }
    pos_doable[0] = 0;
    neg_doable[0] = 0;
    fill_din(pos_doable, pos, pos.front()+neg.front()-1);
    fill_din(neg_doable, neg, pos.front()+neg.front()-1);
    int res = INF;
    for (int i = 1; i < MAXDIN; i++) {
        MinPlace(res, pos_doable[i] + neg_doable[i]);
    }
    cout << res;
}