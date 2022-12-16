#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
string s;

const int NMAX = 1010;

int a[NMAX];

vector<pii> adj[NMAX];
int in[NMAX];

void dfs(int u, int minv) {
    if(a[u] >= minv) {
        return;
    }
    a[u] = minv;
    for(auto& pp : adj[u]) {
        dfs(pp.first, minv+pp.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    cin >> s;
    for(int i=0;i<n-1;++i) {
        if(s[i] == 'L') {
            adj[i+1].emplace_back(i, 1);
        } else if(s[i] == 'R') {
            adj[i].emplace_back(i+1, 1);
        } else if(s[i] == '=') {
            adj[i].emplace_back(i+1, 0);
            adj[i+1].emplace_back(i, 0);
        } else {
            assert(false);
        }
    }
    for(int i=0;i<n;++i) {
        dfs(i, 1);
    }
    for(int i=0;i<n;++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}