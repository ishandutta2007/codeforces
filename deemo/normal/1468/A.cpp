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

const int MAXN = 5e5 + 10;

int n, a[MAXN];
int sec[MAXN], sz, prv[MAXN];
vector<int> vec[MAXN], sv[MAXN];
int fen[MAXN];

void addFen(int v, int val){ for (; v <= n; v += v&-v) fen[v] = max(fen[v], val); }
int getFen(int v) {
    int ret = 0;
    for (; v; v-=v&-v)
        ret = max(ret, fen[v]);
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        vec[i].clear(), sv[i].clear();
    sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (sz && a[sec[sz-1]] <= a[i]) sz--;
        prv[i] = sz? sec[sz-1]: -1;
        sec[sz++] = i;

        if (~prv[i])
            vec[prv[i]].push_back(a[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        sort(vec[i].begin(), vec[i].end());
        vec[i].resize(unique(vec[i].begin(), vec[i].end()) - vec[i].begin());

        int d = getFen(a[i]) + 1;
        if (~prv[i]) {
            int pos = lower_bound(vec[prv[i]].begin(), vec[prv[i]].end(), a[i]) - vec[prv[i]].begin();
            d = max(d, sv[prv[i]][pos] + 2);
        }
        sv[i].resize(vec[i].size());
        for (int j = 0; j < (int)vec[i].size(); j++)
            sv[i][j] = getFen(vec[i][j]);
        addFen(a[i], d);
        ans = max(ans, d);
    }
    fill(fen, fen + n + 2, 0);
    cout << ans << "\n";
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