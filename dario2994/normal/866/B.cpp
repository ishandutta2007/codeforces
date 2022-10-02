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
    LL N, S;
    cin >> N >> S;
    vector<LL> s(N), a(N), b(N);
    LL slices_num = 0;
    LL res = 0;
    vector<pair<LL, LL>> diff(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i] >> a[i] >> b[i];
        res += a[i] * s[i];
        slices_num += s[i];
        diff[i] = {b[i]-a[i], s[i]};
    }
    // dbg_var(slices_num);
    // LL pizzas_num = slices_num / S;
    if (slices_num % S) diff.push_back({0, S - (slices_num % S)});
    sort(diff.begin(), diff.end());
    reverse(diff.begin(), diff.end());
    // dbg_var(res);
    // dbg_var(diff);
    LL curr = 0;
    LL gain = 0;
    for (int i = 0; i < (int)(diff.size()); i++) {
        LL sl = diff[i].second;
        LL val = diff[i].first;
        if (sl + curr < S) {
            curr += sl;
            gain += val * sl;
        } else {
            LL first_val = gain + val*(S-curr);
            if (first_val <= 0) break;
            res += first_val;
            sl -= (S-curr);
            curr = 0;
            gain = 0;
            if (val <= 0) break;
            res += val * (sl/S) * S;
            sl %= S;
            curr += sl;
            gain += val*sl;
        }
    }
    cout << res << "\n";
}