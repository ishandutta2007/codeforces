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

int a[3000], n;
char mp[2000];

void solve() {
	mp['S'] = 'R';
	mp['R'] = 'P';
	mp['P'] = 'S';
	cin >> n;
	cin >> a['R'] >> a['P'] >> a['S'];
	string s; cin >> s;
	string t;
	for (int i = 0; i < n; i++) t += '.';
	int ans = 0;
	for (int i = 0; i < n; i++){
		if (a[mp[s[i]]] > 0)
			a[mp[s[i]]]--, t[i] = mp[s[i]], ans++;
	}
	vector<char> vec;
	vec.push_back('R');
	vec.push_back('P');
	vec.push_back('S');
	if (ans >= (n+1)/ 2) {
		for (int i = 0; i < n; i++)
			if (t[i] == '.')
				for (int j = 0; j < 3; j++)
					if (a[vec[j]]){
						a[vec[j]]--;
						t[i] = vec[j];
						break;
					}
		cout << "YES\n" << t << "\n";
	}
	else
		cout << "NO\n";
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