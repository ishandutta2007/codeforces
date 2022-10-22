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

const int MAXN = 32;

int n, a[MAXN + 3][MAXN + 3][2];


void solve() {
    int q; cin >> n >> q;
    int sm = 0;
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++) {
            a[r][c][0] = 1<<__builtin_ctz(r+1)*2;
            a[r][c][1] = 1<<__builtin_ctz(c+1)*2+1;
            if (r+1 < n)
                sm += a[r][c][0];
            if (c+1 < n)
                sm += a[r][c][1];
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n; j++)
            cout << a[i][j][1] << " ";
        cout << "\n";
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j][0] << " ";
        cout << "\n";
    }

    int lst = 0;
    while (q--) {
        int x; cin >> x;
        x ^= lst;
        lst = x;

        int r, c;
        int rx=0;
        for (r = 0; r < n; r++) {
            int cx = 0;
            for (c = 0; c < n; c++) {
                if ((rx^cx) == x)
                    goto there;
                cx ^= a[r][c][1];
            }
            rx ^= a[r][0][0];
        }
there:

        cout << r+1 << " " << c+1 << endl;
    }
}

int main(){
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}