//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 1100
#define MOD 1000000007

int n;
int parent[MAXN];
int sze[MAXN];
vector <pair<int, int>> cut;
set <int> join;

void make_set(int v) {
    parent[v] = v;
    sze[v] = 1;
}

int find_set(int v) {
    if(v==parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int c, int d) {
    int a = find_set(c);
    int b = find_set(d);
    if(a!=b) {
        if(sze[a] < sze[b]) swap(a, b);
        parent[b] = a;
        sze[a] += sze[b];
    }
    else {
        cut.push_back({c, d});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) make_set(i+1);
    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        union_sets(a, b);
    }
    forn(i, n) join.insert(find_set(i+1));
    int x = join.size();
    int arr[x];
    int t = 0;
    for(auto it: join) {
        arr[t] = it;
        t++;
    }
    // arr contains x elements. cut contains x-1 pairs.
    cout << x-1 << endl;
    forn(i, x-1) printf("%d %d %d %d\n", cut[i].first, cut[i].second, arr[i], arr[i+1]);
    return 0;
}