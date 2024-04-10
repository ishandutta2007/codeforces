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

int n[3], a[3][MAXN], pos[MAXN], d[3][MAXN], mx[MAXN];

void solve() {
	cin >> n[0] >> n[1] >> n[2];
	for (int w = 0; w < 3; w++) {
		for (int i = 0; i < n[w]; i++)
			cin >> a[w][i], a[w][i]--, pos[a[w][i]] = w;
		sort(a[w], a[w]+n[w]);
	}
	int tn = n[0] + n[1] + n[2];
	d[2][tn] = 0;
	d[1][tn] = n[1];
	for (int i = tn-1; ~i; i--){
		d[2][i] = d[2][i+1];
		if (pos[i] == 2)
			d[2][i]++;

		d[1][i] = d[1][i+1];
		if (pos[i] == 1)
			d[1][i]--;
	}

	mx[tn] = d[2][tn] + d[1][tn];
	for (int i = tn-1; ~i; i--)
		mx[i] = max(mx[i+1], d[1][i] + d[2][i]);

	int ans = tn - mx[0], x = 0;
	int d1 = 0;
	for (int i = 0; i < tn; i++){
		if (pos[i] == 0)
			d1++;
		else if (pos[i] == 1)
			x++;

		ans = min(ans, tn - (mx[i+1] - x + d1));
	}
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