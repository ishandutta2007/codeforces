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

const int MAXN = 300010;
int D[MAXN];
vector<int> aa[MAXN];
vector<int> edge_index[MAXN];
vector<int> chosen;
int N, M;

bool fatto[MAXN];
bool dfs(int v) {
    fatto[v] = true;
    int current_degree = 0;
    for (int i = 0; i < (int)aa[v].size(); i++) {
        int a = aa[v][i];
        if (fatto[a]) continue;
        if (dfs(a)) {
            current_degree++;
            chosen.push_back(edge_index[v][i]);
        }
    }
    if (D[v] != -1 and current_degree%2 != D[v]) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N >> M;
    int one_num = 0;
    int minus_index = 0;
    for (int i = 1; i <= N; i++) {
        cin >> D[i];
        if (D[i] == 1) one_num++;
        if (D[i] == -1) minus_index = i;
    }
    if (minus_index == 0 and (one_num % 2)) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        aa[a].push_back(b);
        edge_index[a].push_back(i);
        aa[b].push_back(a);
        edge_index[b].push_back(i);
    }
    
    int root = 1;
    if (minus_index) root = minus_index;
    dfs(root);
    cout << chosen.size() << "\n";
    for (int x : chosen) cout << x << "\n";
}