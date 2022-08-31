#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n,m,s, ans[300001];
bool reach[300001];
multiset<int> adj1[300001];
set<vi> adj2[300001], tmp[300001];

void solve1() {
    FOR(i,1,n+1) tmp[i] = adj2[i];
    memset(reach,0,sizeof reach);
    
    queue<int> todo; todo.push(s); reach[s] = 1;
    while (todo.size()) {
        int x = todo.front(); todo.pop();
        // cout << "HI " << x << " " << reach[x] << "\n";
        for (int i: adj1[x]) if (!reach[i]) {
            reach[i] = 1;
            todo.push(i);
        }
        for (vi i: tmp[x]) {
            ans[i[1]] = i[2];
            if (!reach[i[0]]) {
                reach[i[0]] = 1;
                todo.push(i[0]);
            }
            tmp[i[0]].erase({x,i[1],3-i[2]});
        }
        tmp[x].clear();
    }
    
    int tot = 0;
    FOR(i,1,n+1) if (reach[i]) tot ++;
    FOR(i,1,n+1) for (vi a: tmp[i]) ans[a[1]] = 1;
    
    cout << tot << "\n";
    FOR(i,1,m+1) if (ans[i]) {
        if (ans[i] == 1) cout << '+';
        else cout << '-';
    }
    cout << "\n";
}

void solve2() {
    FOR(i,1,n+1) tmp[i] = adj2[i];
    memset(reach,0,sizeof reach);
    
    queue<int> todo; todo.push(s); reach[s] = 1;
    while (todo.size()) {
        int x = todo.front(); todo.pop();
        for (int i: adj1[x]) if (!reach[i]) {
            reach[i] = 1;
            todo.push(i);
        }
        for (vi i: tmp[x]) {
            ans[i[1]] = 3-i[2];
            tmp[i[0]].erase({x,i[1],3-i[2]});
        }
        tmp[x].clear();
    }
    
    int tot = 0;
    FOR(i,1,n+1) if (reach[i]) tot ++;
    FOR(i,1,n+1) for (vi a: tmp[i]) ans[a[1]] = 1;
    
    cout << tot << "\n";
    FOR(i,1,m+1) if (ans[i]) {
        if (ans[i] == 1) cout << '+';
        else cout << '-';
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> s;
	FOR(i,1,m+1) {
	    int t,u,v; cin >> t >> u >> v;
	    if (t == 1) adj1[u].insert(v);
	    else adj2[u].insert({v,i,1}), adj2[v].insert({u,i,2});
	}
	solve1(); // maximize
	solve2(); // minimize
}

// read!
// ll vs. int!