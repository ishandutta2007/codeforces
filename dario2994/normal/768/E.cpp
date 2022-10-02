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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) cout << #x  << ": " << x << endl;
    #define dbg_vec(x) cout << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) cout << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif  

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

unordered_map<ULL, int> grundy[61];
int max_grund = 0;

int ComputeGrundy(int k, ULL used) {
    if (k == 0) return 0;
    if (!grundy[k].count(used)) {
        bool values[11];
        std::fill(std::begin(values), std::end(values), false);
        for (int i = 1; i <= k; i++) {
            if (used & (1ull<<i)) continue;
            values[ComputeGrundy(k-i, used | (1ull<<i))] = true;
        }
        int it = 0;
        while (values[it]) it++;
        grundy[k][used] = it;
        max_grund = max(max_grund, it);
    }
    return grundy[k][used];
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    
    for (int k = 1; k <= 60; k++) ComputeGrundy(k, 0);
    
    int res = 0;
    vector<int> grundy0(61);
    for (int i = 0; i <= 60; i++) grundy0[i] = grundy[i][0];
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        res ^= grundy0[s];
    }
    if (res == 0) cout << "YES";
    else cout << "NO";
}