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

vector<vector<double>> pp;

void Iterate(int K) {
    int d = pp.size();
    pp.resize(d + 1);
    pp[d].resize(K+1);
    pp[d][0] = 0;
    for (int t = 1; t <= K; t++) {
        pp[d][t] = pp[d-1][t] * (double)(t);
        pp[d][t] += pp[d-1][t-1] * (double)(K+1-t);
        pp[d][t] /= (double)K;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int K, Q;
    cin >> K >> Q;
    vector<int> qq(Q);
    for (int i = 0; i < Q; i++) cin >> qq[i];
    pp.resize(1);
    pp[0].assign(K+1, 0);
    pp[0][0] = 1.0;
    while (pp.back().back() < 0.5) Iterate(K);
    for (int i = 0; i < Q; i++) {
        double prob = (double)qq[i];
        prob -= 1e-7;
        prob /= (double)2000;
        for (int d = 0; d < (int)pp.size(); d++) {
            if (pp[d][K] >= prob) {
                cout << d << "\n";
                break;
            }
        }
    }
}