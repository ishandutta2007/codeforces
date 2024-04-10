// https://codeforces.com/problemset/problem/893/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100000

int n;
long long mingold[MAXN];
int parent[MAXN];

int find(int x) {
    if(x==parent[x]) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        parent[d] = c;
        if(mingold[d]<mingold[c]) mingold[c] = mingold[d];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int m;
    forn(i, MAXN) parent[i] = i;
    cin >> n >> m;
    forn(i, n) cin >> mingold[i];
    int t1, t2;
    forn(i, m) {
        cin >> t1 >> t2;
        --t1; --t2;
        unite(t1, t2);
    }
    long long ans = 0;
    // forn(i, n) cout << parent[i] << " ";
    // cout << endl;
    // forn(i, n) cout << mingold[i] << " ";
    forn(i, n) {
        if(i==parent[i]) {
            ans += mingold[i];
        }
    }
    cout << ans;
    return 0;
}