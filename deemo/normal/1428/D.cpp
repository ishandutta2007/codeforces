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

int n, a[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<pii> ans;
	set<pii> ready2;
	set<pii> ready3;
	set<pii> ready3_only;
	for (int i = n-1; ~i; i--) 
		if (a[i] == 0) {
			continue;
		} else if (a[i] == 1) {
			ans.push_back({i, i});
			ready2.insert({i, i});
			ready3.insert({i, i});
		} else if (a[i] == 2) {
			if (ready2.empty()) {
				cout << "-1\n";
				exit(0);
			}
			auto c = *ready2.begin();
			ready2.erase(c);
			ready3.erase(c);

			ans.push_back({i, c.second});
			ready3_only.insert({i, c.second});
		} else {  // 3
			if (ready3_only.empty() && ready3.empty()) {
				cout << "-1\n";
				exit(0);
			}
			auto c = ready3_only.empty()? *ready3.begin(): *ready3_only.begin();
			ready3_only.erase(c);
			ready3.erase(c);
			ready2.erase(c);

			ans.push_back({i, i});
			ans.push_back({c.first, i});
			ready3_only.insert({i, i});
		}

	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x.second + 1 << " " << x.first+1 << "\n";
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