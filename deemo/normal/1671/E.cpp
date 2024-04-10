#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;
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

const int MAXN = 1<<21;

int n;
string s, t[MAXN];
int d[MAXN];

void solve() {
    cin >> n >> s;
    int mx = (1<<n)-1;
    for (int i = mx; i; i--)
        if (i*2 > mx) {
            t[i] = s[i - 1];
            d[i] = 1;
        } else {
            t[i] = string(1, s[i-1]) + min(t[i*2] + t[i*2+1], t[i*2+1] + t[i*2]);
            bool same = t[i*2] == t[i*2+1];
            if (same)
                d[i] = 1ll*d[i*2]*d[i*2]%MOD;
            else
                d[i] = 2ll*d[i*2]*d[i*2+1]%MOD;
        }
    cout << d[1] << "\n";
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