#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cout << #x << " = " << x << endl
 
using namespace std;

int n;
pair<int, int> a[200111];
vector <pair<int, int>> res;
int node[200111];
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	
	for(int i = 0; i < a[n].fi; ++i) 
		node[i] = 2 * a[n - i].se - 1;
	node[a[n].fi] = 2 * a[n].se;
	int R = a[n].fi;
	for(int i = 1; i < a[n].fi; ++i) {
		int ind = i + a[n - i].fi - 1;
		if(ind < R)
			res.pb({node[ind], 2 * a[n - i].se});
		else {
			R += 1;
			node[R] = 2 * a[n - i].se;
			res.pb({node[ind], 2 * a[n - i].se});
		}
	}
	
	for(int i = a[n].fi; i <= n - 1; ++i) {
		if(a[n - i].fi == 1) {
			res.pb({node[0], 2 * a[n - i].se - 1});
			res.pb({2 * a[n - i].se - 1, 2 * a[n - i].se});
			continue;
		}
		res.pb({node[0], 2 * a[n - i].se});
		res.pb({node[a[n - i].fi - 2], 2 * a[n - i].se - 1});
	}
	for(int i = 0; i < a[n].fi; ++i)
		res.pb({node[i], node[i + 1]});
	for(auto it : res)
		printf("%d %d\n", it.fi, it.se);
			
		
	
	
	
 
	return 0;
}