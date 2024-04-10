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
const int MAXN = 100100; 
int a[MAXN];
int pr[MAXN];
int last_apparizione[MAXN];
int N;



int res[MAXN];
int EasyCalc(int k) {
    if (res[k]) return res[k];
    int ris = 1;
    int curr_start = 0;
    int curr_size = 1;
    for (int i = 1; i < N; i++) {
        curr_size += curr_start > pr[i];
        if (curr_size > k) {
            curr_size = 1;
            curr_start = i;
            ris++;
        }
    }
    return ris;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < MAXN; i++) last_apparizione[i] = -1;
    for (int i = 0; i < N; i++) {
        pr[i] = last_apparizione[a[i]];
        last_apparizione[a[i]] = i;
    }
    int rad = min((int)(2*sqrt(N)), N);
    for (int k = 1; k <= rad; k++) res[k] = EasyCalc(k);
    int curr = rad;
    while (curr <= N) {
        int l = curr+1;
        int r = N+1;
        while (l < r) {
            int m = (l+r)/2;
            res[m] = EasyCalc(m);
            if (res[m] == res[curr]) l = m+1;
            else r = m;
        }
        int prox = l;
        for (int i = curr+1; i < prox; i++) res[i] = res[curr];
        curr = prox;
    }
    for (int k = 1; k <= N; k++) cout << res[k] << " ";
}