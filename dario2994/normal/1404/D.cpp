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

bool is_good(vector<pair<int,int>> A) {
    int N = A.size();
    for (int bb = 0; bb < (1<<N); bb++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (bb&(1<<i)) sum += A[i].first;
            else sum += A[i].second;
        }
        if (sum%(2*N) == 0) return false;
    }
    return true;
}

void generate_pairs(int N, int curr, vector<bool>& used, vector<pair<int,int>>& A) {
    if (curr == 2*N+1) {
        if (is_good(A)) {
            cout << A << endl;
        }
        return;
    }
    if (used[curr]) {
        generate_pairs(N, curr+1, used, A);
        return;
    }
    for (int i = curr+1; i <= 2*N; i++) {
        if (used[i]) continue;
        used[curr] = true;
        used[i] = true;
        A.push_back({curr, i});
        generate_pairs(N, curr, used, A);
        A.pop_back();
        used[i] = false;
        used[curr] = false;
    }
}

void slow_backtrack(int N) {
    vector<bool> used(2*N+1);
    vector<pair<int,int>> A;
    generate_pairs(N, 1, used, A);
}


const int MAXN = 500100;
bool visited[2*MAXN];
vector<int> aa[2*MAXN];
int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= N; i++) cout << i << " ";
        for (int i = 1; i <= N; i++) cout << i << " ";
        cout << endl;
        int ans;
        cin >> ans;
        assert(ans == 0);
        return 0;
    }
    cout << "Second" << endl;
    vector<int> known(N+1, 0);
    for (int i = 1; i <= 2*N; i++) {
        int p;
        cin >> p;
        if (known[p]) {
            int j = known[p];
            if (j + N != i) {
                aa[i].push_back(j);
                aa[j].push_back(i);
            }
        }
        else known[p] = i;
    }
    for (int i = 1; i <= N; i++) {
        aa[i].push_back(i+N);
        aa[i+N].push_back(i);
    }

    vector<vector<int>> comp;
    for (int v = 1; v <= 2*N; v++) {
        if (visited[v]) continue;
        int u = v;
        vector<int> path;
        while (!visited[u]) {
            path.push_back(u);
            visited[u] = true;
            for (int a: aa[u]) {
                if (!visited[a]) {
                    u = a;
                    break;
                }
            }
        }
        // assert(SZ(path)%2 == 0);
        comp.push_back(path);
    }
    // dbg(comp);

    LL sum = 0;
    for (const auto& path: comp) {
        for (int i = 0; i < SZ(path); i += 2) sum += path[i];
    }
    if (sum % (2*N)) {
        for (auto& path: comp) {
            if (SZ(path)%4) {
                reverse(path.begin(), path.end());
                break;
            }
        }
    }

    sum = 0;
    for (const auto& path: comp) {
        for (int i = 0; i < SZ(path); i += 2) {
            sum += path[i];
            cout << path[i] << " ";
        }
    }
    cout << endl;
    int ans;
    cin >> ans;
    assert(ans == 0);
}