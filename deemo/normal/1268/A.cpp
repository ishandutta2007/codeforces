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

int n, k, a[MAXN], b[MAXN];

void printo(){
	cout << n << "\n";
	for (int i = 0; i < n; i++)
		cout << b[i];
	cout << "\n";
}

bool ok(){
	for (int i = 0; i + k < n; i++)
		if (b[i] != b[i+k])
			return false;
	return true;
}

void build(){
	for (int i = 0; i < n; i++)
		b[i] = a[i%k];
}

void solve() {
	cin >> n >> k;
	string s; cin >> s;
	for (int i = 0; i < n; i++) a[i] = s[i]-'0';
	build();
	bool fl = true;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]){
			fl &= a[i] < b[i];
			break;
		}
	if (fl && ok()){
		printo();
		return;
	}
	for (int i = k-1; ~i; i--)
		if (a[i] < 9){
			a[i]++;
			for (int j = i+1; j < k; j++)
				a[j] = 0;
			build();
			printo();
			return;
		}
	cout << n+1 << "\n";
	for (int i = 0; i < n+1; i++)
		if (i%k == 0)
			cout << "1";
		else
			cout << "0";
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