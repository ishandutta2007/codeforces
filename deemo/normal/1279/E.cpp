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

const int MAXN = 50 + 3;
const ll INF = 2e18;

ll ss[MAXN], d[MAXN];

ll mult(ll a, ll b){
	if (a < INF/ b)
		return a*b;
	return INF;
}

#define next lkjasdf

int next[MAXN];
int getPar(int v){ return next[v]==v? v: next[v]=getPar(next[v]);}

void go(int l, int r, ll k){
	cout << r << " ";
	if (l == r) return;

	int ln = r-l+1;
	iota(next, next + ln, 0);

	int chains = r-l;
	ll used = 1ll<<ln-1;
	next[0] = ln-1;

	for (int i = 1; i < ln; i++) {
		for (int j = 0; j < ln; j++)
			if (!(used>>j&1)) {
				if (i == ln-1) {
					cout << j+l << " ";
					break;
				}

				if (getPar(j) != i) {
					if (k <= ss[max(0, chains-2)]) {
						chains--;
						next[i] = j;
						used |= 1ll<<j;
						cout << j + l << " ";
						break;
					}
					else
						k -= ss[max(0, chains-2)];
				}
			}
	}
}

void solve() {
	int n; ll k; cin >> n >> k; 
	if (k > d[n]){
		cout << "-1\n";
		return;
	}
	int rem = n;
	while (rem>0){
		int x;
		for (x = 1; x <= rem; x++){
			if (mult(ss[max(0, x-2)], d[rem-x]) >= k)
				break;
			k -= mult(ss[max(0, x-2)], d[rem-x]);
		}
		ll g = (k + d[rem-x]-1)/ d[rem-x];
		go(n-rem+1, n-rem+x, g);
		k -= (g-1)*d[rem-x];
		rem -= x;
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = mult(ss[i-1], i);
	d[0] = 1;
	for (int i = 1; i < MAXN; i++)
		for (int t = 1; t <= i; t++)
			d[i] = min(INF, d[i] + mult(ss[max(0, t-2)], d[i-t]));
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}