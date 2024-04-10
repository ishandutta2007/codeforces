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
 
const int MOD = 1000000007;
const int MAX = 10000005;

ll n,x,y,u,v, u1,v1, ans;
vi children[200001];
bool b1=true,b2=true;

int dfs(int v,int p) {
	int s=0;
	for (auto u:children[v]) if (u!=p) s+=dfs(u,v);
	if (!s) return 1;
	else if (s==1) return ans++,1;
	return ans+=2,0;
}

int main() {
 	cin >> n >> x >> y >> u1 >> v1;
 	children[v1].pb(u1),children[u1].pb(v1);
 	F0R(i,n-2) {
 		cin >> u >> v;
 		children[v].pb(u),children[u].pb(v);
 		if (u != u1 && v != u1) b1 = false;
 		if (u != v1 && v != v1) b2 = false;
 	}
 	
 	if (x<y) {
 		dfs(1,0);
	 	cout << x*ans+y*(n-1-ans);
 	} else if (x == y) cout << x*(n-1);
 	else {
 		if (b1 || b2) cout << x+y*(n-2);
 		else cout << y*(n-1);
 	}
	return 0;
}