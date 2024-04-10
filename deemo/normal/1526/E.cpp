#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353 ;
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

int n, k;
int s[MAXN], pos[MAXN];
int ss[MAXN], tt[MAXN];

int choose(int a, int b) {
    if (a < b) return 0;
    if (b < 0) return 0;
    return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

void solve() {
    ss[0] = 1;
    for (int i = 1; i < MAXN; i++)
        ss[i] = 1ll*i*ss[i-1] % MOD;
    tt[0] = 1;
    for (int i = 1; i < MAXN; i++)
        tt[i] = pw(ss[i], MOD-2);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i], pos[s[i]] = i;

    int cnt = 0;
    pos[n] = -1e9;
    for (int i = 0; i + 1 < n; i++) {
        int x = s[i], y = s[i+1];
        if (pos[x+1] > pos[y+1])
            cnt++;
    }
    cout << choose(k-2+(n+1-cnt), n) << "\n";
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