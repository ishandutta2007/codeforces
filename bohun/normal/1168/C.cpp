#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int LOG = 18, nax = 300005;

int n, q;
int t[nax];	
int last[LOG + 1];
int go[nax][LOG + 1];	

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> q;
	FOR(i, n)
		cin >> t[i];
	FOR(i, n + 1) {
		for(int j = 0; j <= LOG; ++j) {
			go[i][j] = n + 1;
		}
	}
	for(int j = 0; j <= LOG; ++j)
		last[j] = n + 1;
	
	FORd(i, n) {
		for(int j = 0; j <= LOG; ++j) {
			if(((1 << j) & t[i]) == 0)
				continue;
			int w = last[j];
			for(int k = 0; k <= LOG; ++k)
				go[i][k] = min(go[i][k], go[w][k]);
		}
		for(int j = 0; j <= LOG; ++j) {
			if((1 << j) & t[i]) {
				go[i][j] = i;
				last[j] = i;
			}
		}
	}
	while(q--) {
		int a, b;
		cin >> a >> b;
		bool ok = 0;
		for(int j = 0; j <= LOG; ++j) {
			if((1 << j) & t[b]) {
				if(go[a][j] <= b)
					ok = 1;
			}
		}
		if(ok) {
			cout << "Shi\n";
		}
		else {
			cout << "Fou\n";
		}
	}
				
	
		
	
	
	
	
				
	
	
    return 0;
}