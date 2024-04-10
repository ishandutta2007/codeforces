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

int n, k, x, a[MAXN];
ll d[MAXN][MAXN];
pair<ll, int> sec[MAXN];

void solve() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    memset(d, -10, sizeof(d));
    d[0][0] = 0;
    for (int t = 1; t <= x; t++) {
        int head = 0, tail = 0;
        if (d[t-1][0] >= 0)
            sec[tail++] = {d[t-1][0], 0};
        for (int i = 1; i <= n; i++) {
            if (head == tail)
                d[t][i] = -1e15;
            else
                d[t][i] = a[i-1] + sec[head].F;

            while (head < tail && sec[head].S <= i-k) head++;
            while (head < tail && sec[tail-1].F < d[t-1][i]) tail--;
            if (d[t-1][i] >= 0)
                sec[tail++] = {d[t-1][i], i};
        }
    }

    ll ans = -1;
    for (int i = n; i > n - k; i--)
        ans = max(ans, d[x][i]);
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