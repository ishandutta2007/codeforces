#define _USE_MATH_DEFINES
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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

// const int MAXN = -1;

unordered_map<ULL, vector<int>> choice;

vector<int> DOUBLIFY(vector<int> a) {
    for (int& x : a) x = 2*x;
    return a;
}

ULL hashami(const vector<int>& a) {
    ULL res = 0;
    for (int x : a) {
        ULL y = 100001ll+x;
        res *= 322147ll;
        res += y;
    }
    return res;
}

vector<int> f(vector<int> a) {
    a.erase(unique(a.begin(), a.end()), a.end());
    int N = a.size();
    ULL hasha = hashami(a);
    if (!choice.count(hasha)) {
        bool isp = false;
        bool isn = false;
        bool is = false;
        bool dispari = false;
        vector<int> b(N, 0), c(N, 0);
        for (int i = 0; i < N; i++) {
            if (a[i] == 0) continue;
            if (a[i] != 1) isp = true;
            if (a[i] != -1) isn = true;
            if (a[i] != -1 and a[i] != 1) is = true;
            if (a[i]%2) {
                b[i] = (a[i]-1)/2;
                c[i] = (a[i]+1)/2;
                dispari = true;
            } else b[i] = a[i]/2, c[i] = a[i]/2;
        }
        if (!is) {
            if (isp and isn) choice[hasha] = {1, -1};
            else if (isp) choice[hasha] = {-1};
            else if (isn) choice[hasha] = {1};
            else choice[hasha] = {};
        } else if (!dispari) choice[hasha] = DOUBLIFY(f(b));
        else {
            auto ansp = f(b);
            auto ansn = f(c);
            if (ansp.size() < ansn.size()) {
                choice[hasha] = DOUBLIFY(ansp);
                choice[hasha].push_back(1);
            } else {
                choice[hasha] = DOUBLIFY(ansn);
                choice[hasha].push_back(-1);
            }
        }
    }

    return choice[hasha];
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    auto ans = f(a);
    cout << ans.size() << "\n";
    for (int x : ans) cout << x << " ";
    // cout << endl << choice.size() << endl;
}