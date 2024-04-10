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
const int SQ = 150;

int n, pt[MAXN];
string s;
vector<ll> res[3];
int sec[MAXN];
int sz;
int nxt[MAXN];

void solve() {
	cin >> s; n = s.size();
	for (int i = 0; i < n; i++) pt[i+1] = pt[i] + int(s[i] == '1');
	
	ll ans = 0;
	for (int k = 1; k < SQ; k++) {
		sz = 0;
		for (int i = 0; i <= n; i++)
			sec[sz++] = i - k*pt[i];
		sort(sec, sec + sz);
		for (int l = 0; l < sz;){
			int r = l;
			while (r < sz && sec[l] == sec[r]) r++;

			ans += 1ll*(r-l)*(r-l-1)/ 2;
			l = r;
		}
	}
	int lst = nxt[n] = n;
	for (int i =n-1; ~i; i--){
		if (s[i] == '1')
			lst = i;
		nxt[i] = lst;
	}
	for (int l = 0; l < n; l++)
		if (nxt[l] != n){
			int cur = 1, r = nxt[l];
			while (r < n && cur*SQ + l <= n){
				int nextR = nxt[r+1];
				ans += max(0, (nextR-l)/ cur - max(SQ-1, (r-l)/ cur));
				
				r = nextR;
				cur++;
			}
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