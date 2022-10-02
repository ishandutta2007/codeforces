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
    // ifstream input_from_file("input.txt");
    // #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXK = 10000;
const int MAXQ = 5;
const ULL MAXM = 10004205361450474ull;
ULL din[MAXQ+1][MAXK+1];


ULL secret = 342435235;
int query_cnt = 0;
int dbg_ask_question(vector<ULL> vec) {
    assert(vec.size() <= secret);
    query_cnt++;
    assert(query_cnt <= 5);
    for (int i = 1; i < (int)vec.size(); i++) assert(vec[i-1] < vec[i]);
    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i] == secret) return -1;
        if (vec[i] > secret) return i;
    }
    return vec.size();
}

int ask_question(vector<ULL> vec) {
    cout << vec.size() << " ";
    for (ULL x : vec) cout << x << " ";
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

void solve(int q, ULL l) {
    // cout << "L" << l << endl;
    ULL res = 0;
    vector<ULL> query;
    for (int i = 0; i < (int)min(l, (ULL)MAXK); i++) {
        res += din[q-1][min(l+res, (ULL)MAXK)]+1;
        if (res+l-1 > MAXM){
            if (query.empty()) query.push_back(MAXM);
        } else query.push_back(res + l-1);
        res = min(res, MAXM);
    }
    int ans = ask_question(query);
    if (ans == -1) {
        // cout << "SUCCESS" << endl;
        return;
    }
    if (ans == 0) solve(q-1, l);
    else solve(q-1, query[ans-1]+1);
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(0); // Remove in problems with online queries!

    for (int q = 1; q <= MAXQ; q++) {
        for (ULL l = 1; l <= MAXK; l++) {
            if (q == 5 and l > 1) break;
            ULL res = 0;
            for (int i = 0; i < (int)l; i++) {
                res += din[q-1][min(l+res, (ULL)MAXK)]+1;
                res = min(res, MAXM);
            }
            res += din[q-1][min(l+res, (ULL)MAXK)];
            din[q][l] = res;
        }
    }
    // secret = 5;
    solve(5, 1);
    // for (int i = 1; i <= 100; i++) {
    //     query_cnt = 0;
    //     secret = MAXM + 1 - i;
    //     solve(5, 1);
    // }
    // vector<ULL> secrets
    // for (auto s : secrets) {
    //     secret = s;
    //     solve(5, 1);
    // }
}