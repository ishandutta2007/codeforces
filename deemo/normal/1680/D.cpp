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

const int MAXN = 3e3 + 10;

int n, k, a[MAXN], b[MAXN];
ll q, sm, tsm;

ll go(bool neg = false) {
    ll res = 1;
    for (int j = 0; j <= n; j++) {
        memcpy(a, b, sizeof(a));
        sm = tsm;
        if (neg) {
            for (int i = 0; i < n; i++)
                a[i] *= -1;
            sm *= -1;
        }

        ll rem = q;
        ll cur = 0;
        for (int i = 0; i < n; i++)
            if (!a[i]) {
                if (i < j) {
                    rem--;
                    a[i] = k;
                    cur += k;
                    if ((abs(sm + cur) + k-1) / k > rem) {
                        ll dif = abs(abs(sm+cur) - rem * k);
                        a[i] -= dif;
                        cur -= k;
                        cur += a[i];
                    }
                } else {
                    rem--;
                    a[i] = -k;
                    cur -= k;
                    if ((abs(sm + cur) + k-1) / k > rem) {
                        ll dif = abs(abs(sm+cur) - rem * k);
                        a[i] += dif;
                        cur += k;
                        cur += a[i];
                    }
                }
            }

        ll l = 0, r = 0;
        cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i];
            l = min(l, cur);
            r = max(r, cur);
        }
        res = max(res, r-l+1);
    }
 /*   for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;*/
    return res;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        if (!a[i])
            q++;
    }
    memcpy(b, a, sizeof(a));
    tsm = sm;
    if (abs(sm) > q * k)
        cout << "-1\n";
    else {
        cout << max(go(0), go(1)) << "\n";
    }
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