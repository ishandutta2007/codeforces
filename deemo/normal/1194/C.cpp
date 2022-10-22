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

const int MAXN = 100 + 10;

string s[3];
int mp[200];

void solve() {
	for (int i = 0; i < 3; i++) cin >> s[i];
	int cur = 0;
	for (int j = 0; j < s[0].size(); j++){
		while (cur < s[1].size() && s[0][j] != s[1][cur]) cur++;
		if (cur == s[1].size()){
			cout << "NO\n";
			return;
		}
		cur++;
	}
	memset(mp, 0, sizeof(mp));
	for (int i = 0; i < 3; i++)
		for (char c: s[i])
			if (i == 1)
				mp[c]--;
			else
				mp[c]++;
	for (int i = 0; i < 26; i++)
		if (mp['a' + i] < 0){
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
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