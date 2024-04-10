#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

map<int,bool> ok;
pair<int,pii> vert[100001];
int par[100001], root = 1, ans=0, n;

void dfs(int node, int lo, int hi) {
    if (lo <= vert[node].f && vert[node].f <= hi) ok[vert[node].f] = 1;
    if (vert[node].s.f != -1) dfs(vert[node].s.f,lo,min(vert[node].f-1,hi));
    if (vert[node].s.s != -1) dfs(vert[node].s.s,max(vert[node].f+1,lo),hi);
}

int main() {
	cin >> n;
	F0R(i,n) {
	    int v,l,r; cin >> v >> l >> r;
	    vert[i+1] = mp(v,mp(l,r));
	    if (l != -1) par[l] = i+1;
	    if (r != -1) par[r] = i+1;
	}
	while (par[root]) root = par[root];
	dfs(root,0,1000000000);
	FOR(i,1,n+1) ans += (1-ok[vert[i].f]);
	cout << ans;
}