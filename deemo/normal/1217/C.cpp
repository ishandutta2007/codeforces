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

const int MAXN = 2e5 + 10;

int n;
string s;

void solve() {
	cin >> s; n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '1'){
			int t = 0;
			while (i-t-1 >= 0 && s[i-t-1] == '0') t++;
			
			int cur = 1, r = i+1;
			while (r <= n && cur <= n){
				ans += int(r-i <= cur && cur <= r-i+t);
				if (r == n) break;
				cur <<= 1;
				if (s[r++] == '1')
					cur++;
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