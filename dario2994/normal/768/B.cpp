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

LL CountOdds(LL x) {
    return (x+1ll) / 2ll;
}

int main() {
    ios::sync_with_stdio(false);
    LL N;
    cin >> N;
    LL l, r;
    cin >> l >> r;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    vector<bool> binary_digits;
    while (N != 0) {
        binary_digits.push_back(N%2ll);
        N /= 2ll;
    }
    
    LL res = 0;
    LL l1 = l;
    LL r1 = r;
    for (int i = binary_digits.size()-1; i >= 0; i--) {
        if (l1 > r1) break;
        if (binary_digits[i]) {            
            res += CountOdds(r1) - CountOdds(l1-1);
        }
        l1 = (l1+1ll) / 2ll;
        r1 = r1 / 2ll;
    }
    cout << res;
}