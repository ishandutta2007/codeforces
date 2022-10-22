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

const int MAXN = 2e3 + 10;

int n, p[MAXN], q[MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    if (n == 1) {
        cout << "-1\n";
        return;
    }

    set<int> st;
    for (int i = 0; i < n; i++) st.insert(i);

    for (int i = 0; i + 2 < n; i++) {
        auto mn = *st.begin();
        st.erase(mn);
        if (p[i] != mn)
            q[i] = mn;
        else {
            int x = *st.begin();
            st.erase(x);
            st.insert(mn);
            q[i] = x;
        }
    }

    int x = *st.begin();
    int y = *st.rbegin();
    if (p[n-2] != x && p[n-1] != y)
        q[n-2] = x, q[n-1] = y;
    else
        q[n-1] = x, q[n-2] = y;

    for (int i = 0; i < n; i++)
        cout << q[i]+1 << " ";
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