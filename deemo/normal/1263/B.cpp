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

const int MAXN = 10 + 3;

int n;
string s[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (s[i] == s[j]){
				ans++;
				break;
			}
	cout << ans << "\n";
	for (int i = 0; i < n; i++) {
		bool fl = false;
		for (int j = i+1; j < n; j++)
			if (s[i] == s[j]) {
				fl = true;
				break;
			}
		if (fl){
			for (int w = 0; w < 10; w++) {
				s[i][0] = char(w + '0');
				fl = false;
				for (int j = 0; j < n; j++)
					if (i != j && s[i] == s[j]){
						fl = true;
						break;
					}
				if (!fl)
					break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << s[i] << "\n";
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