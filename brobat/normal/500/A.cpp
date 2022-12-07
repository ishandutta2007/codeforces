// https://codeforces.com/problemset/problem/500/A

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 1; i <= int(n); i++)
using namespace std;
#define MAXN 30001

int n, t;
int adj[MAXN];

int find(int x) {
    if(x==t) return 1;
    if (adj[x]==0) return 0;
    return find(adj[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n >> t;
    int temp;
    for(int i=0; i<MAXN; i++) adj[i] = 0;
    forn(i, n-1) {
        cin >> temp;
        // add i+temp to adj list of i
        adj[i] = i+temp;
    }
    int ans = find(1);
    if(ans) cout << "YES";
    else cout << "NO";
    return 0;
}