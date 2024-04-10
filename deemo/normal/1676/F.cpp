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

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> cnt;
    while (n--) {
        int x; cin >> x; cnt[x]++;
    }
    vector<int> vec;
    for (auto [x, y]: cnt)
        if (y >= k)
            vec.push_back(x);
    if (vec.empty())
        cout << "-1\n";
    else {
        int sz = vec.size();
        int tl = -1, tr = -3;
        for (int l = 0; l < sz; ){
            int r = l+1;
            while (r < sz && vec[r-1] == vec[r] - 1) r++;
            if (tr - tl < r-l)
                tr = vec[r-1], tl = vec[l];
            l = r;
        }
        cout << tl << " " << tr << "\n";
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