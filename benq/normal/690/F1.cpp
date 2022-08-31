#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vi adj[10005];

int main() {
    int n,ans=0; cin >> n;
    FOR(i,1,n) {
        int a,b; cin >> a >> b;
        adj[a].pb(b),adj[b].pb(a);
    }
    FOR(i,1,n+1) {
        for (int j: adj[i]) ans += (adj[j].size()-1);
    }
    cout << ans/2;
}