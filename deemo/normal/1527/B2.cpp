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
    int n; string s; cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());
    int cnt = 0;
    for (char c: s)
        if (c == '0')
            cnt++;
    if (s == t) {
        if (cnt > 1 && n & 1 && s[n/2] == '0')
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }
    else {
        int mismatch = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                mismatch++;
        mismatch >>= 1;
        if (mismatch == 1 && n&1 && s[n/2] == '0' && cnt == 2)
            cout << "DRAW\n";
        else
            cout << "ALICE\n";
    }
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