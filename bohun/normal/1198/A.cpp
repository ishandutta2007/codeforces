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

const int mod = 1e9 + 7, nax = 200001;

int n, k, a;
vector <int> v;
map <int, int> mapa;

int ile, sum;
int daj(int x) {
	return ceil((double) log2(x));
}

int main() {
	ios
	cin >> n >> k;
	k *= 8;
	FOR(i, 1, n) {
		cin >> a;
		mapa[a]++;
		v.pb(a);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	int wsk = 0;
	int ans = n + 10;
	
	FOR(i, 0, ss(v) - 1) {
		while(wsk < ss(v) && (ll) n * daj(ile + 1) <= k) {
			ile++;
			sum += mapa[v[wsk]];
			++wsk;
		}
		if(n * daj(ile) <= k) {
			ans = min(ans, n - sum);
		}
		sum -= mapa[v[i]];
		ile--;
	}
	cout << ans;
	
	
	
	
	
	
	
	
	
	return 0;
}