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

int n, m, k, b[MAXN];

int reduce(int t) {
    while (t >= k)
        t -= k-1;
    return t;
}

bool check(int t) {
    int others = n - m - t;
    t = reduce(t);
    return t <= others;
}

void solve() {
    cin >> n >> k >> m;
    for (int i = 0; i < m; i++) cin >> b[i];
    if ((n-m)%(k-1) != 0)
        cout << "NO\n";
    else {
        for (int i = 0; i < m; i++)
            if ((b[i] - (i+1)) * 2 == (n-m)) {
                cout << "YES\n";
                return;
            }
        for (int i = 0; i < m; i++)
            if (!check(b[i] - (i == 0? 0: b[i-1]) - 1)) {
                cout << "NO\n";
                return;
            }
        if (!check(n-b[m-1])) {
            cout << "NO\n";
            return;
        }

        for (int i = 0; i + 1 < m; i++) {
            int d1 = (b[i] - (i+1)) - ((n - m) - (b[i] - (i+1)));
            int d2 = (b[i+1] - (i+2)) - ((n - m) - (b[i+1] - (i+2)));
            if (d1 < 0 && d2 > 0) {
                if (d1 % 2 != 0 || d2 % 2 != 0) {
                    cout << "NO\n";
                    return;
                }
                int l = b[i] - (i+1);
                int r = (n-m) - (b[i+1] - (i+2));
                if (l*2 < k-1 && r*2 < k-1) {
                    cout << "NO\n";
                    return;
                }
            }
        }

        cout << "YES\n";
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