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

const int MAXN = -1; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<LL> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<LL> din1(N);
    vector<LL> num1(N);
    din1[0] = 0, num1[0] = a[0];
    for (int k = 0; k < N-1; k++) {
        din1[k+1] = din1[k] + max(0ll, num1[k]+1-a[k+1]);
        num1[k+1] = max(num1[k]+1ll, a[k+1]);
    }
    reverse(a.begin(), a.end());
    vector<LL> din2(N);
    vector<LL> num2(N);
    din2[0] = 0, num2[0] = a[0];
    for (int k = 0; k < N-1; k++) {
        din2[k+1] = din2[k] + max(0ll, num2[k]+1-a[k+1]);
        num2[k+1] = max(num2[k]+1ll, a[k+1]);
    }
    reverse(a.begin(), a.end());
    
    LL ans = min(din1[N-1], din2[N-1]);
    for (int k = 1; k <= N-2; k++) {
        MinPlace(ans, din1[k-1] + din2[N-2-k] + max(0ll, max(num1[k-1], num2[N-2-k])+1 - a[k]));
        // cout << k << " " << ans << endl;
    }
    cout << ans << "\n";
}