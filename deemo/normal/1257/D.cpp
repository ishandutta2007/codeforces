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
const int LOG = 19;

int n, a[MAXN], m;
pii p[MAXN];
int mx[MAXN], d[MAXN];
int mxq[LOG][MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], mxq[0][i] = a[i];
	for (int w = 1; w < LOG; w++)
		for (int i = 0; i < n; i++)
			if (i+(1<<w-1) >= n)
				mxq[w][i] = mxq[w-1][i];
			else
				mxq[w][i] = max(mxq[w-1][i], mxq[w-1][i+(1<<w-1)]);

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> p[i].F >> p[i].S;
	sort(p, p + m);
	mx[m] = -1;
	for (int i = m-1; ~i; i--)
		mx[i] = max(mx[i+1], p[i].S);

	d[n] = 0;
	for (int i = n-1; ~i; i--){
		if (a[i] > p[m-1].F){
			cout << "-1\n";
			return;
		}
		int r = i+1, curMx = a[i];
		for (int w = LOG-1; ~w; w--)
			if (r + (1<<w) <= n) {
				int tempMx = max(curMx, mxq[w][r]);
				int pos = lower_bound(p, p+m, make_pair(tempMx, -1)) - p;
				if (mx[pos] >= r+(1<<w) - i)
					r += 1<<w, curMx = tempMx;
			}
		d[i] = d[r] + 1;
	}
	
	cout << d[0] << "\n";
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