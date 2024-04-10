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

int n, a[MAXN], d[MAXN];
int sec[2][MAXN], sz[2];

void solve() {
    cin >> n; for (int i = 0; i < n; i++) cin >> a[i];
    d[n-1] = 0;
    sec[0][sz[0]++] = n-1;
    sec[1][sz[1]++] = n-1;

    for (int i = n-2; ~i; i--) {
        d[i] = d[i+1] + 1;
        if (a[i] > a[i+1]) {
            int j;
            for (j = sz[0]-1; j >= 0 && a[sec[0][j]] < a[i]; j--)
                d[i] = min(d[i], d[sec[0][j]] + 1);
            if (j >= 0)
                d[i] = min(d[i], d[sec[0][j]] + 1);
        } else if (a[i] < a[i+1]) {
            int j;
            for (j = sz[1]-1; j >= 0 && a[sec[1][j]] > a[i]; j--)
                d[i] = min(d[i], d[sec[1][j]] + 1);
            if (j >= 0)
                d[i] = min(d[i], d[sec[1][j]] + 1);
        }
        while (sz[0] && a[i] >= a[sec[0][sz[0]-1]]) sz[0]--;
        while (sz[1] && a[i] <= a[sec[1][sz[1]-1]]) sz[1]--;
        sec[0][sz[0]++] = i;
        sec[1][sz[1]++] = i;
    }

    cout << d[0] << "\n";
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