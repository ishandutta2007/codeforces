#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

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

const int MAXN = 1e5 + 10;

int n, m, a[MAXN], b[MAXN];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

	ll ans = 0;
	int pt = 0;
	set<int> st;
	for (int i = 0; i < m; i++) {
		cin >> b[i], b[i]--;
		if (st.count(b[i])){
			st.erase(b[i]);
			ans++;
		}
		else{
			ans += st.size() * 2;
			while (pt < n && st.count(b[i]) == 0)
				st.insert(a[pt++]), ans += 2;
			ans--;
			st.erase(b[i]);
		}
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}