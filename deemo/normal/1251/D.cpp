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
const ll INF = 1e18;

int n;
ll s;
pii p[MAXN];

ll get(int mid){
	ll sm = 0;
	int gre = 0;
	
	for (int i = 0; i < n; i++)
		if (p[i].S < mid)
			sm += p[i].F;
		else if (p[i].F >= mid)
			sm += p[i].F, gre++;
		else
			sm += p[i].F;

	for (int i = 0; gre < n/2+1 && i < n; i++)
		if (p[i].F < mid && p[i].S >= mid){
			sm += mid - p[i].F;
			gre++;
		}
	
	if (gre < n/2 + 1)
		return INF;
	return sm;
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S;
	sort(p, p + n);
	reverse(p, p + n);
	int lo = 0, hi = (int)1e9 + 1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (get(mid) > s)
			hi = mid;
		else
			lo = mid;
	}
	cout << lo << "\n";
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