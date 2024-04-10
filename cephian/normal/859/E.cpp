#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n;
const int N = 1e5+5, M = 1e9 + 7;
int want[2*N]={};
bool fix[2*N] = {};
vector<int> prv[2*N];
int vis[2*N] = {};

int g1_cyc = 0;

vector<int> top;
ll dp[2*N] = {};

bool search(int v) {
	// cout << "at " << v << endl;
	if(vis[v] == 2) return false;
	if(vis[v] == 1) {
		// cout << "found fault at " << v << endl;
		g1_cyc += want[v] != v;
		return fix[v] = true;
	}
	vis[v] = 1;
	if(want[v] == 0) {
		vis[v] = 2;
		top.push_back(v);
		return false;
	}
	if(search(want[v])) {
		vis[v] = 2;
		if(!fix[v]) {
			// cout << "coming back, i made " << v << " fixed\n";
			fix[v] = true;
			return true;
		}
		return false;
	}
	top.push_back(v);
	vis[v] = 2;
	return false;
}

int main() {	
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		int a,b;
		scanf("%d%d",&a,&b);
		want[a] = b;
		prv[b].pb(a);
	}
	for(int i = 1; i <= 2*n; ++i) {
		if(want[i] && !vis[i]) {
			search(i);
		}
	}
	ll ans = 1;
	while(g1_cyc) {
		ans = (ans * 2) % M;
		--g1_cyc;
	}
	fix[0] = true;
	for(int i = (int)top.size()-1; i >= 0; --i) {
		int v = top[i];
		dp[v] = 1;
		for(int u : prv[v]) {
			dp[v] = (dp[v] + dp[u]) % M;
		}
		if(want[v] == 0) {
			ans = ans * dp[v] % M;
		}
	}
	printf("%I64d\n",ans);
}