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

ll a[MAXN];
int sec[MAXN];

void solve() {
    int n; ll w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll sm = 0;
    int sz = 0;
    ll mid = w+1>>1;
    for (int i = 0; i < n; i++) {
        if (a[i] > w) continue;
        if (a[i] >= mid) {
            cout << 1 << "\n";
            cout << i+1 << "\n";
            return;
        }
        else {
            sm += a[i];
            sec[sz++] = i;
            if (sm >= mid) {
                cout << sz << "\n";
                for (int i = 0; i < sz; i++)
                    cout << sec[i]+1 << " ";
                cout << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
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