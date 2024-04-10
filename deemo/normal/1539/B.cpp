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

int n;
string s;
int p[26][MAXN];

void solve() {
    int q;cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++)
            p[j][i+1] = p[j][i];
        p[s[i] - 'a'][i+1]++;
    }
    while (q--) {
        int l, r; cin >> l >> r, l--;
        ll ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += 1ll*(i+1)*(p[i][r] - p[i][l]);
        }
        cout << ans << "\n";
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