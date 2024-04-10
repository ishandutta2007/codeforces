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

const int MAXN = 1e6 + 10;

int n[2];
int a[2][MAXN];

void solve() {
    cin >> n[0] >> n[1];
    for (int w = 0; w < 2; w++)
        for (int i = 0; i < n[w]; i++)
            cin >> a[w][i];

    int ans = 0;
    int c[2] = {0};
    int sm[2] = {0};
    while (c[0] < n[0] || c[1] < n[1]) {
        if (sm[0] < sm[1])
            sm[0] += a[0][c[0]++];
        else
            sm[1] += a[1][c[1]++];
        ans += sm[0] == sm[1];
    }
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