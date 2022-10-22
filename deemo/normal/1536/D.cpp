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

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> st;
    st.insert(a[0]);
    int cur = a[0];
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == cur) {
            x++, y++;
        } else if (a[i] < cur) {
            x += 2;
            auto it = st.lower_bound(cur);
            if (it != st.begin()) {
                it--;
                if (*it > a[i]) {
                    cout << "NO\n";
                    return;
                }
            }
            cur = a[i];
            if (!st.count(cur)) {
                st.insert(cur);
                x--;
            }
        } else {
            y += 2;
            auto it = st.upper_bound(cur);
            if (it != st.end() && *it < a[i]) {
                cout << "NO\n";
                return;
            }
            cur = a[i];
            if (!st.count(cur)) {
                st.insert(cur);
                y--;
            }
        }
    }
    cout << "YES\n";
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