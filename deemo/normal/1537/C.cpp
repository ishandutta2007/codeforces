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

int n, a[MAXN];

void go(int x, int y){
    for (int i = x; i < n; i++)
        if (i != y)
            cout << a[i] << " ";
    for (int i = 0; i <= y; i++)
        if (i != x)
            cout << a[i] << " ";
    cout << "\n";
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int mn = 2e9;
    for (int i = 0; i + 1 < n; i++)
        mn = min(mn, a[i+1] - a[i]);

    if (a[1] - a[0] == mn)
        go(0, 1);
    else if (a[n-1] - a[n-2] == mn)
        go(n-2, n-1);
    else {
        for (int i = 1; i + 1 < n; i++)
            if (a[i+1] - a[i] == mn) {
                go(i, i+1);
                break;
            }
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