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
vector<int> vec[2];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int l = 0; l < n;) {
        int r = l;
        while (r < n && a[l] == a[r]) r++;
        if (r - l > 2) {
            cout << "NO\n";
            return;
        }
        vec[0].push_back(a[l]);
        if (r - l > 1)
            vec[1].push_back(a[l]);
        l = r;
    }
    cout << "YES\n";
    cout << vec[0].size() << "\n";
    for (auto x: vec[0])
        cout << x << " ";
    cout << "\n";
    cout << vec[1].size() << "\n";
    reverse(vec[1].begin(), vec[1].end());
    for (auto x: vec[1])
        cout << x << " ";
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