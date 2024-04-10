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

const int MAXN = 1e3 + 10;

int n, cnt[2], c[2];
string s[MAXN];
int sec[MAXN], sz;

void solve() {
	cin >> n;
	cnt[0] = cnt[1] = sz = 0;
	int cc = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (char c: s[i])
			cnt[c-'0']++;
		sec[sz++] = s[i].size();
		if (sec[sz-1]&1)
			cc++;
	}
	sort(sec, sec + sz);
	int ans = 0;
	for (int a = 0; a <= cc; a++)
		for (int b = 0; a+b <= cc; b++){
			int temp = 0;
			c[0] = cnt[0] - a, c[1] = cnt[1] - b;
			if (c[0] < 0 || c[1] < 0) continue;

			int aa = a, bb = b;
			for (int i = 0; i < sz; i++){
				int x = sec[i];
				int g = min(c[0]/2, x/2);
				c[0] -= g*2;
				x -= g*2;
				g = min(c[1]/2, x/ 2);
				c[1] -= g*2;
				x -= g*2;
				if (x > 1) break;
				
				if (x) {
					if (aa)
						aa--;
					else if (bb)
						bb--;
					else
						break;
				}
				temp++;
			}
			if (aa == 0 && bb == 0)
				ans = max(ans, temp);
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