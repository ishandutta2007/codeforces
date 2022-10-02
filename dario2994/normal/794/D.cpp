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

#define INF 1<<30
#define eps 1e-9

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

// Inizio: 21.45

// This should not compile if used.
const int MAXN = 300010;
vector<int> aa[MAXN];
int tmp_label[MAXN];
int cric_num;
vector<int> cric_aa[MAXN];
int real_label[MAXN];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in online problems!
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        aa[a].push_back(b);
        aa[b].push_back(a);
    }
    for (int i = 0; i < N; i++) aa[i].push_back(i), sort(aa[i].begin(), aa[i].end());
    // dbg_array(aa, N);
    auto tmp_ord = SortIndex(N, [&](int i, int j) {
        return aa[i] < aa[j];
    });
    for (int i = 1; i < N; i++) {
        int u = tmp_ord[i];
        int v = tmp_ord[i-1];
        tmp_label[u] = tmp_label[v];
        if (aa[u] != aa[v]) tmp_label[u]++;
    }
    cric_num = tmp_label[tmp_ord[N-1]] + 1;
    // dbg_array(tmp_label, N);
    if (cric_num == 1) {
        cout << "YES\n";
        for (int v = 0; v < N; v++) cout << 1 << " ";
        return 0;
    }
    for (int v = 0; v < N; v++) {
        int lv = tmp_label[v];
        auto& friends = cric_aa[lv];
        for (int a : aa[v]) {
            int la = tmp_label[a];
            if (la == lv) continue;
            if (find(friends.begin(), friends.end(), la) == friends.end()) {
                friends.push_back(la);
                if (friends.size() > 2) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }
    // dbg_var(cric_num);
    // dbg_array(cric_aa, cric_num);
    
    int cric_first = -1;
    for (int label = 0; label < cric_num; label++) {
        if (cric_aa[label].size() == 1) {
            cric_first = label;
            break;
        }
    }
    if (cric_first == -1) {
        cout << "NO\n";
        return 0;
    }

    real_label[cric_first] = 1;
    int it = cric_first;
    while (1) {
        bool finished = true;
        for (int lab : cric_aa[it]) {
            if (real_label[lab]) continue;
            real_label[lab] = real_label[it] + 1;
            it = lab;
            finished = false;
        }
        if (finished) break;
    }

    cout  << "YES\n";
    for (int v = 0; v < N; v++) cout << real_label[tmp_label[v]] << " ";
}