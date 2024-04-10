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

int n, m;
int a[MAXN], lst[MAXN], b[MAXN];
pii sec[MAXN];

bool check(int mid) {
    memset(lst, -1, sizeof(lst));
    for (int i = 0; i < mid; i++)
        lst[a[i]] = i;
    for (int i = 0; i < m; i++)
        sec[i] = {lst[i + 1], i};
    sort(sec, sec + m);
    int cur = 0;
    for (int i = 0; i < m; i++) {
        int d = b[sec[i].second];
        if (cur + d > sec[i].first)
            return false;
        cur += d + 1;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    int lo = 0, hi = n + 1;
    while (hi - lo > 1) {
        int mid = hi+lo>>1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    if (hi == n+1)
        hi = -1;
    cout << hi << "\n";
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