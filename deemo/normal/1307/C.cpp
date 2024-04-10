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

ll cnt[200];
int n;
string s;
ll d[200][200];

void solve() {
	cin >> s; n = s.size();
	ll ans = 0;
	for (int i = 0; i < n; i++) cnt[s[i]]++;
	for (int i = 0; i < n; i++)
		ans = max(ans, cnt[s[i]]);

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < 26; a++)
			d[a][s[i]-'a'] += cnt[a];
		cnt[s[i]-'a']++;
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, d[i][j]);

	cout << ans << "\n";
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