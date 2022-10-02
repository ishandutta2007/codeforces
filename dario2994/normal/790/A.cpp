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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define endl "\n";

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = -1; 

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<string> names;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            char a = 'A' + i;
            char b = 'a' + j;
            string name = "aa";
            name[0] = a;
            name[1] = b;
            names.push_back(name);
        }
    }
    vector<int> chosen(N);
    for (int i = 0; i < N; i++) {
        if (i < K-1) {
            chosen[i] = i;
            cout << names[i] << "\n";
        }
        else {
            string val;
            cin >> val;
            if (val == "YES") {
                cout << names[i] << "\n";
                chosen[i] = i;
            }
            else {
                cout << names[chosen[i-(K-1)]] << "\n";
                chosen[i] = chosen[i-(K-1)];
            }
        }
    }
}