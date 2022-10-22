#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 30;

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

int n;
int tr[MAXN*C][2], sz;
int cnt[MAXN*C];

void insert(int &x) {
    int cur = 0;
    for (int i = 29; ~i; i--) {
        int d = x>>i&1;
        if (!tr[cur][d])
            tr[cur][d] = ++sz;
        cur = tr[cur][d];
    }
    cnt[cur]++;
}

int dfs(int v) {
    int a = tr[v][0]? dfs(tr[v][0]): 0;
    int b = tr[v][1]? dfs(tr[v][1]): 0;
    if (!a && !b)
        return 1;
    if (!a || !b)
        return a+b;
    if (a && b)
        return 1 + max(a, b);
    return max(a, b);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        insert(x);
    }
    cout << n - dfs(0) << "\n";
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