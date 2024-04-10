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

const int MAXN = 5e3 + 10;

int n, x[MAXN][2], y[MAXN][2];
vector<pair<pii, int>> vec[2];
// 0 hor
//

int fen[2*MAXN];
void addFen(int v, int val){for (; v<MAXN*2; v += v&-v) fen[v] += val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

pii sec[MAXN];
ll get2(int x){return 1ll*x*(x-1)/ 2;}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
		x[i][0] += MAXN, x[i][1] += MAXN, y[i][0] += MAXN, y[i][1] += MAXN;
		if (x[i][0] == x[i][1])
			vec[1].push_back({{min(y[i][0], y[i][1]), max(y[i][0], y[i][1])}, x[i][0]});
		else
			vec[0].push_back({{min(x[i][0], x[i][1]), max(x[i][0], x[i][1])}, y[i][0]});
	}
	sort(vec[0].begin(), vec[0].end(), [](pair<pii, int> a, pair<pii, int> b) {
			return a.S < b.S;
			});

	ll ans = 0;
	for (int i = 0; i < vec[0].size(); i++){
		auto v = vec[0][i];
		memset(fen, 0, sizeof(fen));
		int sz = 0;
		for (auto s: vec[1])
			if (v.F.F <= s.S && s.S <= v.F.S && s.F.F <= v.S && v.S <= s.F.S){
				addFen(s.S, 1);
				sec[sz++] = make_pair(s.F.S + 1, s.S);
			}
		sort(sec, sec + sz);

		int pt = 0;
		for (int j = i+1 ; j < vec[0].size(); j++){
			auto u = vec[0][j];
			int tl = max(v.F.F, u.F.F), tr = min(v.F.S, u.F.S);
			if (tl > tr) continue;

			while (pt < sz && sec[pt].F <= u.S)
				addFen(sec[pt++].S, -1);
			ans += get2(get(tr) - get(tl - 1));
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