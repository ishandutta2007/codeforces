#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const LL INF = 1e18;
const int M = 1e6;
LL F[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int k;
    cin >> k;

    for (int i = 0; i < 6; i++) cin >> F[i];
    vector<LL> gain(M, -INF);
    gain[0] = 0;
    LL w = 1;
    for (int e = 0; e < 6; e++, w *= 10) {
        // cout << e << endl;
        LL f = F[e];
        vector<LL> new_gain(M, -INF);

        
        LL q = 3*(k-1);
        // Step 1:
        vector<multiset<LL>> vals(3*w);
        for (int i = 0; i < M; i++) {
            LL p = i/(3*w);
            vals[i%(3*w)].insert(gain[i] - f*p);
            LL it = i - (q+1)*3*w;
            if (it >= 0) {
                auto boh = vals[it % (3*w)].find(gain[it] - f * (it/(3*w)));
                vals[it % (3*w)].erase(boh);
            }
            new_gain[i] = (*vals[i%(3*w)].rbegin()) + f*p;
            // if (i-3*(q+1)*w >= 0) val
            // for (int j = 0; j <= q; j++) {
                // if (j*3*w > i) break;
                // new_gain[i] = max(new_gain[i], gain[i-j*3*w] + f*j);
            // }
        }
        // if (e == 0) cout << new_gain[3] << endl;

        // Step 2
        for (int i = M-1; i >= 0; i--) {
            if (i >= w) new_gain[i] = max(new_gain[i], new_gain[i-w]);
            if (i >= 2*w) new_gain[i] = max(new_gain[i], new_gain[i-2*w]);
        }

        // Step 3:
        int z = 9*(k-1);
        vector<int> AA = {z+3, z+4, z+5, z+6, z+7, z+8, z+9};
        vector<LL> BB = {q+1, q, q, q+2, q, q, q+3};
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < SZ(AA); j++) {
                if (i >= AA[j] * w) {
                    new_gain[i] = max(new_gain[i], BB[j]*f + gain[i-AA[j]*w]);
                }
            }
        }
        gain = new_gain;

        // cout << e << endl;
        // if (e == 0) for (int i = 0; i < 40; i++) cout << i << " " << gain[i] << "\n";
    }

    int q;
    cin >> q;
    for (int _ = 0; _ < q; _++) {
        int n;
        cin >> n;
        cout << gain[n] << "\n";
    }
}