#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 400100
#define MOD 1000000007

int n, m, q, u, v, t;
set <int> adj[MAXN];
bool isNoble[MAXN];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    ans = 0;
    cin >> n >> m;
    forn(i, n) adj[i].insert(-1);
    forn(i, m) {
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    forn(i, n) {
        // cout << *--adj[i].end() << endl;
        if(i > *--adj[i].end()) {
            ans += 1;
            isNoble[i] = true;
        }
        else isNoble[i] = false;
    }
    
    cin >> q;
    forn(i, q) {
        cin >> t;
        if(t==3) {
            cout << ans << endl;
        }
        else {
            cin >> u >> v;
            u--; v--;
            if(t==1) {
                adj[u].insert(v);
                adj[v].insert(u);
                if(isNoble[u]&&(u < *--adj[u].end())) {
                    isNoble[u] = false;
                    ans -= 1;
                }
                if(isNoble[v]&&(v < *--adj[v].end())) {
                    isNoble[v] = false;
                    ans -= 1;
                }
            }
            if(t==2) {
                set<int>::iterator it;
                it = adj[u].find(v);
                adj[u].erase(it);
                it = adj[v].find(u);
                adj[v].erase(it);
                if((!isNoble[u])&&(u > *--adj[u].end())) {
                    isNoble[u] = true;
                    ans += 1;
                }
                if((!isNoble[v])&&(v > *--adj[v].end())) {
                    isNoble[v] = true;
                    ans += 1;
                }
            }
        }
    }
}
    return 0;
}