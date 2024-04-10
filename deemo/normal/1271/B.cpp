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

int n;
string s;
int cnt[200];
char mp[200];

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cnt[s[i]]++;
	char ch;
	mp['B'] = 'W';
	mp['W'] = 'B';
	if (cnt['B'] % 2 == 0)
		ch = 'W';
	else if (cnt['W'] %2 == 0)
		ch = 'B';
	else {
		cout << "-1\n";
		return;
	}

	vector<int> ans;
	for (int i = 0; i < n;)
		if (s[i] == ch)
			i++;
		else{
			s[i] = mp[s[i]];
			ans.push_back(i++);
			s[i] = mp[s[i]];
			while (s[i] != ch){
				s[i] = mp[s[i]];
				ans.push_back(i++);
				s[i] = mp[s[i]];
			}
			i++;
		}
	cout << ans.size() << "\n";
	for (auto x: ans)
		cout << x+1 << " ";
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