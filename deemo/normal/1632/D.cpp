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

int n, sz;
pii sec[MAXN], gec[MAXN];

void solve() {
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1)
            sz = 0, cur++;
        else {
            if (!sz)
                sec[sz++] = {x, 1};
            else {
                int g = x;
                int ln = 1;
                bool fl = false;
                for (int j = sz-1; ~j; j--) {
                    g = __gcd(g, sec[j].F);
                    if (ln + 1 <= g && g <= ln + sec[j].S) {
                        sz = 0, cur++;
                        fl = true;
                        break;
                    }
                    sec[j].F = g;
                    ln += sec[j].S;
                }
                if (!fl){
                sec[sz++] = {x, 1};
                int tt = 0;
                for (int j = 0; j < sz; j++)
                    if (!tt || gec[tt-1].F != sec[j].F)
                        gec[tt++] = sec[j];
                    else
                        gec[tt-1].S += sec[j].S;
                for (int j = 0; j < tt; j++)
                    sec[j] = gec[j];
                sz = tt;
                }
            }
        }
        cout << cur << " ";
    }
    cout << "\n";
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