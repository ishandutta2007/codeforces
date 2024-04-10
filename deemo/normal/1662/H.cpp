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

int n, m;
set<int> st;

void go(int x) {
    if (n%x == 0) {
        if ((m-2)%x == 0) {
            st.insert(x);
            return;
        }
    }
    if ((n-1)%x == 0) {
        if ((m-1) % x == 0 || m % x == 0 && x == 2) {
            st.insert(x);
            return;
        }
    }
    if ((n-2)%x == 0) {
        if (m % x == 0)
            st.insert(x);
    }
}

void solve() {
    st.clear();
    cin >> n >> m;
    for (int w = 0; w < 2; w++) {
        for (int i = 1; i * i <= n; i++)
            go(i), go(n/i), go((n-1)/i), go((n-2)/i);
        swap(n, m);
    }
    cout << st.size() << " ";
    for (auto x: st)
        cout << x << " ";
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