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

int NeededTime(int pos, int l, int r) {
    if (r < pos) return pos-l;
    if (pos < l) return r-pos;
    return (r-l) + min(pos-l, r-pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<int> pacmen;
    vector<int> food;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'P') pacmen.push_back(i);
        if (c == '*') food.push_back(i); 
    }

    int lt = 1;
    int rt = 3*N;
    while (lt < rt) {
        int mt = (lt+rt)/2;
        
        int todo = 0;
        for (int p = 0; p < (int)pacmen.size(); p++) {
            int pos = pacmen[p];
            // dbg_var(pos);
            // dbg_var(todo);
            // cout << "hello: " << NeededTime(3, 0, 4) << endl;
            int left = todo;
            int right = todo;
            while (right < (int)food.size() and NeededTime(pos, food[left], food[right]) <= mt) right++;
            todo = right;
        }
        
        
        if (todo == (int)food.size()) rt = mt;
        else lt = mt+1;
    }
    cout << lt << "\n";
}