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

const int MAXN = -1;

struct Node {
    bool end_of_word;
    Node* sons[26];
    Node(): end_of_word(false) {
        for (int i = 0; i < 26; i++) sons[i] = nullptr;
    }
    void add(string& S, int it) {
        if (it == (int)S.size()) {
            end_of_word = true;
            return;
        }
        if (sons[S[it]-'a'] == nullptr) {
            sons[S[it]-'a'] = new Node();
        }
        sons[S[it]-'a']->add(S, it+1);
    }
};

typedef priority_queue<int>* pq;
pq dfs(Node* v, int depth) {
    vector<pq> sons;
    for (int i = 0; i < 26; i++) {
        if (v->sons[i] == nullptr) continue;
        sons.push_back(dfs(v->sons[i], depth+1));
    }
    pq ans = new priority_queue<int>();
    for (pq son : sons) {
        if (son->size() > ans->size()) swap(son, ans);
        while (!son->empty()) {
            int x = son->top();
            son->pop();
            ans->push(x);
        }
    }
    ans->push(depth);
    if (!v->end_of_word) ans->pop();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    Node* root = new Node();
    root->end_of_word = true;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        root->add(word, 0);
    }
    pq ans = dfs(root, 0);
    LL res = 0;
    while (!ans->empty()) {
        res += ans->top();
        ans->pop();
    }
    cout << res << "\n";
}