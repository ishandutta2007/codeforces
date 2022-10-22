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

int n, fen[MAXN];
void add_fen(int v, int val) {
    for (; v < MAXN; v+=v&-v)
        fen[v] += val;
}

int get_fen(int v) {
    int res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

void solve() {
    cin >> n;
    fill(fen, fen + n + 2, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += (i) - get_fen(x-1);
        add_fen(x, 1);
    }
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