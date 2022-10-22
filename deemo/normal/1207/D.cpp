#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int C = 26;//XXX
const int MOD = 998244353 ;

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

const int MAXN = 3e5 + 10;

int n;
pii p[MAXN];
int ss[MAXN];
int a[MAXN];
int b[MAXN], tt;

int get(int l, int r){
	int sz = 0;
	for (int i = l; i < r; i++) a[sz++] = p[i].S;
	sort(a, a + sz);
	int ret = 1;
	for (int l = 0; l < sz;){
		int r = l;
		while (r < sz && a[l] == a[r]) r++;
		ret = 1ll*ret*ss[r-l]%MOD;
		l = r;
	}
	for (int i = 0; i < sz; i++)
		b[tt++] = a[i];
	return ret;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = 1ll*ss[i-1]*i%MOD;
	int ans = ss[n];
	sort(p, p + n);
	int temp = 1;
	for (int l = 0; l < n; ){
		int r = l;
		while (r < n && p[l].F == p[r].F) r++;
		temp = 1ll*temp*ss[r-l]%MOD;
		l = r;
	}
	add(ans, -temp);
	for (int i = 0; i < n; i++) swap(p[i].F, p[i].S);
	sort(p, p + n);
	temp = 1;
	for (int l = 0; l < n; ){
		int r = l;
		while (r < n && p[l].F == p[r].F) r++;
		temp = 1ll*temp*ss[r-l]%MOD;
		l = r;
	}
	add(ans, -temp);
	temp = 1;
	for (int l = 0; l < n;){
		int r = l;
		while (r < n && p[l].F == p[r].F) r++;
		temp = 1ll*temp*get(l, r)%MOD;
		l = r;
	}
	bool fl = false;
	for (int i = 0; i + 1 < tt; i++)
		if (b[i+1] < b[i])
			fl = true;
	if (!fl)
		add(ans, temp);
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