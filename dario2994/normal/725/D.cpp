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

// This should not compile if used.
const int MAXN = 300010;

// #include "../../CompetitiveProgrammingAlgos/read_graph.cpp"

int N;
LL tt[MAXN];
LL ww[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tt[i] >> ww[i];
    }
    priority_queue<pair<LL, int> > before;
    priority_queue<pair<LL, int> > after; // or equal
    for (int i = 1; i < N; i++) {
        if (tt[i] > tt[0]) {
            before.push(make_pair(-(ww[i]-tt[i]), i));
        } else {
            after.push(make_pair(tt[i], i));
        }
    }

    int answer = before.size();
    while (!before.empty()) {
        int best = before.top().second;
        LL needed = ww[best] - tt[best] +1;
        if (needed > tt[0]) break;
        before.pop();
        tt[0] -= needed;
        while (!after.empty()) {
            int argh = after.top().second;
            if (tt[argh] > tt[0]) {
                after.pop();
                before.push(make_pair(-(ww[argh]-tt[argh]), argh));
            } else {
                break;
            }
        }
        answer = min(answer, (int)before.size());
    }
    cout << answer+1;
}