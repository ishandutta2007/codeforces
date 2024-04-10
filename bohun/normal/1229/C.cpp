#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;	

const int nax = 3e5 + 111;

int n, m, q;
int a, b;
vector <int> v[nax];
bool ok[nax];
int L[nax], R[nax];
int u;
int w[nax];
int pos;
int gdzie[nax];
bool bad[nax];

int main() {	
	scanf("%d%d", &n, &m);
	pos = n + 1;
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		if(a > b)
			swap(a, b);
		L[b] += 1;
		R[a] += 1;
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i, 1, n) {
		w[i] = i;
		gdzie[i] = i;
		sort(v[i].begin(), v[i].end());
	}
	ll res = 0;
	FOR(i, 1, n) {
		res += (ll) L[i] * R[i];
	}
	scanf("%d", &q);
	while(q--) {
		printf("%lld\n", res);
		scanf("%d", &u);
		res -= (ll) L[u] * R[u];
		bad[gdzie[u]] = 1;
		if(ss(v[u]) <= 300) {
			
			for(auto it : v[u]) {
				if(gdzie[it] > gdzie[u]) {
					res -= R[it];
				L[it] -= 1;
				R[it] += 1;
				res += L[it];
				}
			}
		}
		
		else {
			FOR(i, gdzie[u], pos - 1) {
				if(bad[i])
					continue;
				if(*lower_bound(v[u].begin(), v[u].end(), w[i]) != w[i])
					continue;
				res -= R[w[i]];
				L[w[i]] -= 1;
				R[w[i]] += 1;
				res += L[w[i]];
			}
		}
		
		L[u] = ss(v[u]);
		R[u] = 0;
		w[pos++] = u;
		gdzie[u] = pos - 1;
	}
			
	cout << res << endl;	
				
				
				
		
		
		
	
	
	
	
	return 0;
}