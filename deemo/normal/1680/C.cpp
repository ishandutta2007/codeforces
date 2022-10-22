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

int n; string s;

bool check(int mid) {
    int c[2] = {0};
    for (char ch: s)
        c[ch-'0']++;

    int r = -1;
    int c0 = 0;
    for (int l = 0; l < n; l++) {
        if (r <= l) {
            r = l;
            c0 = 0;
        }
        while (r < n && c0 + int(s[r] == '0') <= mid)
            c0 += int(s[r++] == '0');

        if (c[1] - (r-l-c0) <= mid)
            return true;

        c0 -= int(s[l] == '0');
    }
    return false;
}

void solve() {
    cin >> s; n = s.size();
    int lo = -1, hi = n;
    while (hi-lo>1) {
        int mid = hi+lo>>1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi<<"\n";
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