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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		

const int nax = 700005, pod = (1 << 18);
 
int n, m;
int a[nax];
ll sum[nax], maxi[nax], mini[nax], lazy[nax], da[nax];
 
void push(int node) {
	if(!da[node])
		return;
	mini[2 * node] = mini[2 * node + 1] = maxi[2 * node] = maxi[2 * node + 1] = lazy[node];
	lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
	da[2 * node] = da[2 * node + 1] = 1;
	da[node] = 0;
}
 
void Ustaw(int x, int y, int k, int node = 1, int le = 0, int pr = pod - 1) {
	if(x <= le && pr <= y) {
		lazy[node] = k;
		mini[node] = maxi[node] = k;
		da[node] = 1;
		return ;
	}
	push(node);
	int mid = (le + pr) / 2;
	if(x <= mid)
		Ustaw(x, y, k, 2 * node, le, mid);
	if(mid < y)
		Ustaw(x, y, k, 2 * node + 1, mid + 1, pr);
	maxi[node] = max(maxi[2 * node], maxi[2 * node + 1]);
	mini[node] = min(mini[2 * node], mini[2 * node + 1]);
}
 
void Mod(int x, int y, int k, int node = 1, int le = 0, int pr = pod - 1) {
	if(mini[node] >= k)
		return;
	if(maxi[node] == mini[node]) {
		da[node] = 1;
		maxi[node] = mini[node] = lazy[node] = k;
		return ;
	}
		
	if(x <= le && pr <= y && mini[node] == maxi[node]) {
		mini[node] = mini[node] % k;
		maxi[node] = maxi[node] % k;
		sum[node] = (ll) (pr - le + 1) * mini[node];
		lazy[node] = mini[node];
		da[node] = 1;
		return ;
	}
	push(node);
	int mid = (le + pr) / 2;
	if(x <= mid)
		Mod(x, y, k, 2 * node, le, mid);
	if(mid < y)
		Mod(x, y, k, 2 * node + 1, mid + 1, pr);
	sum[node] = sum[2 * node] + sum[2 * node + 1];
	maxi[node] = max(maxi[2 * node], maxi[2 * node + 1]);
	mini[node] = min(mini[2 * node], mini[2 * node + 1]);
}
	
	
	
				
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		maxi[i + pod] = mini[i + pod] = sum[i + pod] = a[i];
	}
	cin >> m;
	for(int i = pod - 1; 1 <= i; --i) {
		maxi[i] = max(maxi[2 * i], maxi[2 * i + 1]);
		mini[i] = min(mini[2 * i], mini[2 * i + 1]);
	}
	while(m--) {
		int type;
		scanf("%d", &type);
		if(type == 2) {
			int x;
			cin >> x;
			Mod(1, pod - 1, x);
		}
		if(type == 1) {
			int l;
			cin >> l;
			int x;
			cin >> x;
			Ustaw(l, l, x);
		}
	}
	
	
	FOR(i, 1, pod - 1) {
		push(i);
	}
	
	FOR(i, 1, n) {
		cout << maxi[i + pod] << " ";
	}
		
	
	
	
	
	
	
	
	
	
	
		
	return 0;
}