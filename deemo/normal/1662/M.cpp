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
    int n, m;
    int mx[2] = {0};
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        mx[0] = max(mx[0], a);
        mx[1] = max(mx[1], b);
    }
    if (mx[0] + mx[1] > n)
        cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < mx[0]; i++)
            cout << "R";
        for (int i = 0; i < n - mx[0]; i++)
            cout << "W";
        cout << "\n";
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