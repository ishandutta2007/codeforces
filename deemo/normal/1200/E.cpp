#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int C = 26;//XXX

const int MAXN = 1e6 + 10;
const int MOD[2] = {(int)1e9+7, 998244853};
const int B[2] = {701, 721};

int n;
string s;
int hs[2][MAXN], _hs[2][MAXN];
int ss[2][MAXN];

int sec[2];
pii getHash(int l, int r){
	for (int w = 0; w < 2; w++){
		sec[w] = (hs[w][r] - 1ll*hs[w][l]*ss[w][r-l]%MOD[w] + MOD[w]) % MOD[w];
	}
	return {sec[0], sec[1]};
}

void addChar(char c){
	int temp = s.size();
	for (int w = 0; w < 2; w++){
		hs[w][temp+1] = (1ll*hs[w][temp]*B[w] + c) % MOD[w];
	}
	s += c;
}

void solve() {
	for (int w = 0; w < 2; w++){
		ss[w][0] = 1;
		for (int i = 1; i < MAXN; i++)
			ss[w][i] = 1ll*ss[w][i-1]*B[w]%MOD[w];
	}
	cin >> n;
	while (n--) {
		string t; cin >> t;
		for (int w = 0; w < 2; w++){
			_hs[w][0] = 0;
			for (int i = 0; i < (int)t.size(); i++)
				_hs[w][i+1] = (1ll*_hs[w][i]*B[w] + t[i]) % MOD[w];
		}

		int mx = 0;
		for (int i = min(t.size(), s.size()); i; i--)
			if (make_pair(_hs[0][i], _hs[1][i]) == getHash((int)s.size() - i, (int)s.size())) {
				mx = i;
				break;
			}
		for (int i = mx; i < (int)t.size(); i++)
			addChar(t[i]);
	}
	cout << s << "\n";
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