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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s[2]; cin >> s[0] >> s[1];
    sort(s[0].begin(), s[0].end());
    sort(s[1].begin(), s[1].end());
    string res;
    int i = 0, j = 0;
    int c[2] = {0};
    while (i < n  && j < m) {
        if ((c[0] < k && s[0][i] < s[1][j]) || (c[1] == k)) {
            res += s[0][i++];
            c[0]++;
            c[1] = 0;
        } else {
            res += s[1][j++];
            c[1]++;
            c[0] = 0;
        }
    }
    cout << res << "\n";
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