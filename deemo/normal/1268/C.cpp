#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
			 OrderedSet;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 2e5 + 10;

int n, a[MAXN], pos[MAXN];
int fen[MAXN];

void add(int v, int val){ for (; v < MAXN; v += v&-v) fen[v] += val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--, pos[a[i]] = i;

	int l = pos[0], r = pos[0] + 1;
	ll ans = 0;
	cout << ans << " ";
	OrderedSet st;
	st.insert(l);
	add(l+1, 1);
	ll inv = 0;
	for (int i = 1; i < n; i++){
		int p = pos[i];
		int t = st.size();
		int mid;
		if (t & 1)
			mid = *st.find_by_order(t/2);
		else{
			mid = *st.find_by_order(t/ 2);
			if (p < mid) {
				mid = *st.find_by_order(t/2 - 1);
				if (p > mid)
					mid = p;
			}
		}

		if (p < mid) {
			if (p >= l)
				ans -= get(p) - get(l);
			ans += (mid - (p + 1)) - (get(mid) - get(p+1));
		}
		else{
			if (p <= r)
				ans -= get(r) - get(p); 
			if (p != mid)
				ans += p - 1 - mid - (get(p) - get(mid+1));
		}


		inv += get(MAXN-2) - get(p);
		st.insert(p);
		add(p+1, 1);
		l = min(l, p);
		r = max(r, p+1);
		cout << ans+inv << " ";
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}