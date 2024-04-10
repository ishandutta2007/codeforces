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

int cc[1024];
int cc2[1024];

void iterate(int X) {
    int sum = 0;
    for (int i = 0; i < 1024; i++) {
        int count = (sum%2)? (cc[i] / 2) : ((cc[i]+1) / 2);
        cc2[i^X] += count;
        cc2[i] += cc[i] - count;
        sum += cc[i];
    }
    for (int i = 0; i < 1024; i++) cc[i] = cc2[i], cc2[i] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    int N, K, X;
    cin >> N >> K >> X;
    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        cc[s]++;
    }
    for (int i = 0; i < K; i++) iterate(X);
    int massimo, minimo;
    for (int i = 1023; i >= 0; i--) {
        if (cc[i]) {
            massimo = i;
            break;
        }
    }
    for (int i = 0; i < 1024; i++) {
        if (cc[i]) {
            minimo = i;
            break;
        }
    }
    cout << massimo << " " << minimo;
}