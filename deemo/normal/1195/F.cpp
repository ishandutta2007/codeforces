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

const int MAXN = 3e5 + 10;

int n;
int tl[MAXN], tr[MAXN];
vector<pii> vec[MAXN];
pii a[MAXN];
int q, bb[MAXN], ee[MAXN];
int sec[MAXN], fen[MAXN];

void addFen(int v, int val){for (; v<MAXN; v+=v&-v) fen[v] += val;}
int getFen(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

pii fix(pii p){
	int g = __gcd(abs(p.F), abs(p.S));
	p.F /= g;
	p.S /= g;
	return p;
}

int ans[MAXN];
void solve() {
	cin >> n;
	int sm = 0;
	for (int i = 0; i < n; i++){
		tl[i] = sm;
		int t; cin >> t;
		vec[i].resize(t);
		for (int j = 0; j < t; j++)
			cin >> vec[i][j].F >> vec[i][j].S;
		for (int j = 0; j < t; j++){
			int nxt = (j+1 == t? 0: j+1);
			a[sm++] = fix({vec[i][nxt].F - vec[i][j].F, vec[i][nxt].S - vec[i][j].S});
		}
		tr[i] = sm;
	}
	cin >> q;
	for (int i = 0; i < q; i++)
		cin >> bb[i] >> ee[i], bb[i]--, ee[i]--, bb[i] = tl[bb[i]], ee[i] = tr[ee[i]];
	iota(sec, sec + q, 0);
	sort(sec, sec + q, [](int a, int b){
			return ee[a] < ee[b];
			});

	int pt = 0;
	map<pii, int> mp;
	for (int i = 0; i < q; i++){
		int v = sec[i];
		while (pt < ee[v]) {
			auto x = a[pt];
			if (mp.count(x))
				addFen(mp[x]+1, -1);
			mp[x] = pt++;
			addFen(mp[x] + 1, 1);
		}
	
		ans[v] = getFen(ee[v]) - getFen(bb[v]);
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
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