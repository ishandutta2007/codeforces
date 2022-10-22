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
const int LOG = 18;

int n, k, a[MAXN];
ll d[MAXN];
int rmq[LOG][MAXN];

int get_min(int l, int r) {
    int res = 1e9;
    for (int w = LOG-1; ~w; w--)
        if (l+(1<<w) <= r)
            res = min(res, rmq[w][l]), l += 1<<w;
    return res;
}

ll pt[MAXN];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], rmq[0][i] = a[i], pt[i+1] = pt[i] + a[i];
    for (int w = 1; w < LOG; w++)
        for (int i = 0; i < n; i++)
            if (i + (1<<w-1) >= n)
                rmq[w][i] = rmq[w-1][i];
            else
                rmq[w][i] = min(rmq[w-1][i], rmq[w-1][i+(1<<w-1)]);

    ll best = 0;
    for (int i = 0; i < n; i++) {
        best += a[i];
        
        d[i+1] = best;
        if (i + 1 >= k) {
            d[i+1] = min(d[i+1], pt[i+1] - pt[i+1-k] - get_min(i+1-k, i+1) + d[i+1-k]);
        }

        best = min(best, d[i+1]);
    }
    cout << d[n] << "\n";
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