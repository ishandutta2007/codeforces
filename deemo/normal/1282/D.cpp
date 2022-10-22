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

const int MAXN = 300 + 10;

string gen(char ch, int t){
	string res;
	while (t--)
		res += ch;
	return res;
}

int get(string s, char ch, int t){
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ch){
			if (t == 0) return i;
			t--;
		}
	assert(0);
}

void solve() {
	cout << "a" << endl;
	int n1; cin >> n1;
	if (n1 == 0) return;
	
	cout << gen('b', n1) << endl;
	int n2; cin >> n2;
	if (n2 == 0) return;

	int n = n1 + 1;
	if (n2 == n){
		cout << gen('a', n) << endl;
		cin >> n;
		return;
	}

	int tb = n - n2;
	int ta = n - tb;

	string ans = gen('b', tb);
	for (int i = 0; i < tb; i++){
		int ind = get(ans, 'b', i);
		while (ta){
			ans.insert(ind, "a");
			cout << ans << endl;
			int x; cin >> x;
			if (x == n - (int)ans.size())
				ta--;
			else {
				ans.erase(ans.begin() + ind);
				break;
			}
		}
	}
	while (ta--)
		ans += 'a';
	cout << ans << endl;
	cin >> n;
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