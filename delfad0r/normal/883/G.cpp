#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
    out << "[";
    for (int x : vec) out << x << ", ";
    out << "]";
    return out;
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
    #define dbg_var(x) clog << #x << ": " << x << endl;
#endif

const int MAXN = 700000;
vector<int> aa[MAXN];
vector<int> ind[MAXN];
int orientation[MAXN];

bool can_go(int index) {
    if (index == 0) return true;
    int pos = index;
    if (pos < 0) pos = -pos;
    if (orientation[pos] == 0) {
        orientation[pos] = (index > 0)?1:-1;
        return true;
    }
    return orientation[pos] == ((index > 0) ? 1 : -1);
}

bool can_stop(int index) {
    if (index == 0) return false;
    int pos = index;
    if (pos < 0) pos = -pos;
    if (orientation[pos] == 0) {
        orientation[pos] = (index > 0)?-1:1;
        return true;
    }
    return orientation[pos] == ((index > 0) ? -1 : 1);
}

bool fatto[MAXN];

int dfs_good(int v) {
    fatto[v] = true;
    int res = 1;
    for (int i = 0; i < (int)aa[v].size(); i++) {
        int a = aa[v][i];
        int id = ind[v][i];
        if (fatto[a]) continue;
        if (!can_go(id)) continue;
        res += dfs_good(a);
    }
    return res;
}

int dfs_bad(int v) {
    fatto[v] = true;
    int res = 1;
    for (int i = 0; i < (int)aa[v].size(); i++) {
        int a = aa[v][i];
        int id = ind[v][i];
        if (fatto[a]) continue;
        if (can_stop(id)) continue;
        res += dfs_bad(a);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int root;
    int N, E;
    cin >> N >> E >> root;
    int id = 1;
    for (int i = 0; i < E; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            aa[a].push_back(b);
            ind[a].push_back(0);
        } else {
            aa[a].push_back(b);
            aa[b].push_back(a);
            ind[a].push_back(id);
            ind[b].push_back(-id);
            id++;
        }
    }
    
    cout << dfs_good(root) << "\n";
    for (int i = 1; i < id; i++) {
        if (orientation[i] == 0) cout << "+";
        if (orientation[i] == 1) cout << "+";
        if (orientation[i] == -1) cout << "-";
    }
    cout << "\n";
    for (int i = 0; i <= E; i++) orientation[i] = 0;
    for (int i = 0; i <= N; i++) fatto[i] = false;
    cout << dfs_bad(root) << "\n";
    for (int i = 1; i < id; i++) {
        if (orientation[i] == 0) cout << "+";
        if (orientation[i] == 1) cout << "+";
        if (orientation[i] == -1) cout << "-";
    }
    cout << "\n";
}