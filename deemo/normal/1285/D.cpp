#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 30;

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

int n, a[MAXN];
int tr[MAXN*(C+1)][2], sz;

void insert(int x){
	int cur = 0;
	for (int w = C-1; ~w; w--){
		int z = x>>w&1;
		if (!tr[cur][z])
			tr[cur][z] = ++sz;

		cur = tr[cur][z];
	}
}

int go(int cur, int dig = C-1) {
	if (dig == -1)
		return 0;

	if (!tr[cur][0])
		return go(tr[cur][1], dig-1);

	if (!tr[cur][1])
		return go(tr[cur][0], dig-1);

	int x = go(tr[cur][0], dig-1);
	int y = go(tr[cur][1], dig-1);
	return min(x, y) + (1<<dig);
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], insert(a[i]);

	cout << go(0) << "\n";
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