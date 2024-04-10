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

int n, a[MAXN], c[MAXN], p[MAXN];

void solve() {
    cin >> n;
    ll sm = 0;
    for (int i = 0; i < n; i++) cin >> c[i], sm += c[i];

    int ones = sm/n;
    p[n] = 0;
    int seen = 0;
    for (int i = n-1; ~i; i--) {
        bool one = false;
        if (ones) {
            if (ones == i+1)
                one = true;
            else {
                int lo = i+1, hi = n+1;
                while (hi-lo>1) {
                    int mid =hi+lo>>1;
                    if (ones + (seen - p[mid]) >= mid-i)
                        lo = mid;
                    else
                        hi = mid;
                }
                if (c[i] > lo -i)
                    one = true;
            }
        }

        seen += one;
        p[i] = p[i+1] + one;
        ones -= one;
        a[i] = one;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
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