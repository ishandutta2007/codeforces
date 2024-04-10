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

int n, a[MAXN];
string b;

int get(int i) {
    if (b[i-1] == b[i-2] && b[i-2] == b[i-3] && b[i-3] == b[i-4])
        return b[i-1] - '0';
    return -1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> b;
    int l=-1e9, r=1e9; // XXX;
    for (int i = 4; i < n; i++) {
        int what = get(i);
        if (what == -1) {
            assert(b[i] == b[i-1]);
            continue;
        }

        if (what == 1 && b[i] == '0')
            r = min(r, -1 + min({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}));
        else if (what == 0 && b[i] == '1')
            l = max(l, 1 + max({a[i], a[i-1], a[i-2], a[i-3], a[i-4]}));
    }
    cout << l << " " << r << endl;
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