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

const int MAXN = 1e5 + 10;

int n, a[MAXN], p[MAXN];
int d, b;
int tr;

bool check(int mid) {
    // at most mid problems
    int my_first = mid;
    int his_first = n - mid - 1;

    int cur = 0;
    int sum = 0;
    for (int i = 0; i < tr; i++) {
        while (cur < n && cur <= i + 1ll * d * (i+1))
            sum += a[cur++];

        if (i >= my_first) {
            if (sum < b)
                return false;
            sum -= b;
        }
    }

    sum = 0;
    cur = n-1;
    for (int i = n-1; i >= tr; i--) {
        while (cur >= 0 && cur >= i - 1ll * d * (n-i))
            sum += a[cur--];

        if (i <= his_first) {
            if (sum < b)
                return false;
            sum -= b;
        }
    }
    return true;
}

void solve() {
    cin >> n >> d >> b;
    for (int i = 0; i < n; i++) cin >> a[i], p[i+1] = p[i] + a[i];

    if (n&1) {
        if (p[n/2 + 1] >= (n/2 + 1) * b) {
            tr = n/2 + 1;
        } else {
            reverse(a, a + n);
            tr = n/2;
        }
    } else {
        if (p[n/2] < n * b / 2)
            reverse(a, a + n);
        tr = n/2;
    }

    int lo = -1, hi = (n+1>>1);
    while (hi - lo > 1) {
        int mid = hi + lo >> 1;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << "\n";
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