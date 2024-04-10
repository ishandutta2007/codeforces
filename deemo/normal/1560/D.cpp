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
    ll cur = 1;
    vector<string> powers {"1"};
    while (cur < 1e18) {
        cur <<= 1;
        powers.push_back(to_string(cur));
    }

    string s; cin >> s;
    int n = s.size(), ans = 1e9;
    for (const auto &cand: powers) {
        int matched = 0, cur = 0;
        while (matched < cand.size() && cur < n) {
            if (cand[matched] == s[cur])
                matched++, cur++;
            else
                cur++;
        }
        ans = min(ans, n-matched + (int)cand.size()-matched);
    }
    cout << ans << "\n";
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