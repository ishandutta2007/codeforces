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

const int MAXN = 1e5 + 10;

int n, hec[MAXN];
pii p[2][MAXN];
pair<pii, pii> sec[2][MAXN];
ll ex[MAXN];


bool cmp(int u, int v){return make_pair(p[0][u].S, -p[0][u].F) < make_pair(p[0][v].S, -p[0][v].F);}

int fen[MAXN];
void addFen(int v, int val){for (; v<MAXN; v+=v&-v) fen[v] += val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

pii gec[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[0][i].F >> p[0][i].S >> p[1][i].F >> p[1][i].S;
	iota(hec, hec + n, 0);
	sort(hec, hec + n, cmp);
	for (int i = 0; i < n; i++){
		int v = hec[i];
		int lo = 0, hi = i+1;
		while(hi-lo>1){
			int mid = hi+lo>>1;
			if (p[0][hec[mid-1]].S < p[0][v].F)
				lo = mid;
			else
				hi = mid;
		}
		sec[0][i] = {{p[1][v].F, i}, {lo, i}};
		sec[1][i] = {{p[1][v].S, i}, {lo, i}};
	}

	memset(fen, 0, sizeof(fen));
	sort(sec[0], sec[0] + n);
	for (int i = 0; i < n; i++)
		gec[i] = {p[1][hec[i]].S, i};
	sort(gec, gec + n);
	int pt = 0;
	for (int i = 0; i < n; i++){
		while (pt < n && gec[pt].F < sec[0][i].F.F)
			addFen(gec[pt++].S+1, 1);
		ex[sec[0][i].F.S] -= get(sec[0][i].S.S) - get(sec[0][i].S.F);
	}

	sort(sec[1], sec[1] + n);
	memset(fen, 0, sizeof(fen));
	for (int i = 0; i < n; i++)
		gec[i] = {p[1][hec[i]].F, i};
	sort(gec, gec + n);
	 pt = n-1;
	for (int i = n-1; ~i; i--){
		while (pt > -1 && gec[pt].F > sec[1][i].F.F)
			addFen(gec[pt--].S+1, 1);
		ex[sec[1][i].F.S] -= get(sec[1][i].S.S) - get(sec[1][i].S.F);
	}

	for (int i = 0; i < n; i++)
		if (ex[i]) {
			cout << "NO\n";
			return;
		}
	for (int i = 0; i < n; i++)
		swap(p[0][i], p[1][i]);

	iota(hec, hec + n, 0);
	sort(hec, hec + n, cmp);
	for (int i = 0; i < n; i++){
		int v = hec[i];
		int lo = 0, hi = i+1;
		while(hi-lo>1){
			int mid = hi+lo>>1;
			if (p[0][hec[mid-1]].S < p[0][v].F)
				lo = mid;
			else
				hi = mid;
		}
		sec[0][i] = {{p[1][v].F, i}, {lo, i}};
		sec[1][i] = {{p[1][v].S, i}, {lo, i}};
	}

	memset(fen, 0, sizeof(fen));
	sort(sec[0], sec[0] + n);
	for (int i = 0; i < n; i++)
		gec[i] = {p[1][hec[i]].S, i};
	sort(gec, gec + n);
	 pt = 0;
	for (int i = 0; i < n; i++){
		while (pt < n && gec[pt].F < sec[0][i].F.F)
			addFen(gec[pt++].S+1, 1);
		ex[sec[0][i].F.S] -= get(sec[0][i].S.S) - get(sec[0][i].S.F);
	}

	sort(sec[1], sec[1] + n);
	memset(fen, 0, sizeof(fen));
	for (int i = 0; i < n; i++)
		gec[i] = {p[1][hec[i]].F, i};
	sort(gec, gec + n);
	 pt = n-1;
	for (int i = n-1; ~i; i--){
		while (pt > -1 && gec[pt].F > sec[1][i].F.F)
			addFen(gec[pt--].S+1, 1);
		ex[sec[1][i].F.S] -= get(sec[1][i].S.S) - get(sec[1][i].S.F);
	}

	for (int i = 0; i < n; i++)
		if (ex[i]) {
			cout << "NO\n";
			return;
		}
	cout << "YES\n";
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