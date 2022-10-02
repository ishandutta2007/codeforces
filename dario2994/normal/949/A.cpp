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

set<int> zebra0;
set<int> zebra1;
vector<vector<int>> zebras;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    string S;
    cin >> S;
    set<int> zebra0;
    set<int> zebra1;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '0') {
            int id;
            if (!zebra1.empty()) {
                id = *zebra1.begin();
                zebra1.erase(id);
                // cout << "BEFORE: " << i << " " << id << " " << zebras[id] << endl;
            } else {
                id = zebras.size();
                zebras.push_back({});
            }
            // cout << i << " " << id << " " << zebras[id] << endl;
            zebras[id].push_back(i);
            zebra0.insert(id);
        } else {
            if (zebra0.empty()) {
                cout << "-1" << "\n";
                return 0;
            }
            int id = *zebra0.begin();
            zebra0.erase(id);
            zebras[id].push_back(i);
            zebra1.insert(id);
        }
    }
    if (!zebra1.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    cout << zebras.size() << "\n";
    for (auto zebra : zebras) {
        cout << zebra.size() << " ";
        for (int x : zebra) cout << x+1 << " ";
        cout << "\n";
    }
}