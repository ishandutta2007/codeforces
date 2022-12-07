// https://codeforces.com/problemset/problem/1143/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100000

int n, ROOT;
int parent[MAXN], dr[MAXN], nodel[MAXN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) parent[i] = i;
    forn(i, n) nodel[i] = 0;
    forn(i, n) {
        cin >> parent[i] >> dr[i];
        --parent[i];
        if(parent[i]==-2) {
            parent[i] = i;
            ROOT = i;
        }
    }
    // cout << ROOT << endl;
    forn(i, n) {
        if(dr[i]==0) {
            nodel[parent[i]] = 1;
        }
    }
    // forn(i, n) cout << nodel[i] << " " << dr[i] << endl;
    int ans = 0;
    forn(i, n) {
        if(i==ROOT) continue;
        if(nodel[i]==0&&dr[i]==1) {
            cout << (i+1) << " ";
            ans++;
        }
    }
    if(ans==0) cout << -1;
    return 0;
}