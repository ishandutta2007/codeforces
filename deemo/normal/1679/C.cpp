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

int n, q, cnt[2][MAXN];

void solve() {
    cin >> n >> q;
    set<int> st[2];
    for (int i = 1; i <= n; i++) st[0].insert(i), st[1].insert(i);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int r, c; cin >> r >> c;
            st[0].erase(r);
            st[1].erase(c);
            cnt[0][r]++;
            cnt[1][c]++;
        } else if (t == 2) {
            int r, c; cin >> r >> c;
            if (!--cnt[0][r])
                st[0].insert(r);
            if (!--cnt[1][c])
                st[1].insert(c);
        } else {
            int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
            auto i1 = st[0].lower_bound(r1);
            auto i2 = st[1].lower_bound(c1);
            if ((i1 == st[0].end() || *i1 > r2) || (i2 == st[1].end() || *i2 > c2))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
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