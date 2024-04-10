#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int MAXN = 1e6 + 10;
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
/*
void plant(int v, int b, int e){
	if (e - b == 1){

		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
}*/

int n;
string s, t[2];

void solve() {
	cin >> s;
	n = s.size();
	int l = 0, r = n;
	while (r-l > 0){
		if (r - l <= 3){
			t[0] += s[l];
			break;
		}
		if (s[l] == s[r-1])
			t[0] += s[l], t[1] += s[l], l++, r--;
		else if (s[l] == s[r-2])
			t[0] += s[l], t[1] += s[l], l++, r -= 2;
		else if (s[l+1] == s[r-1])
			t[0] += s[l+1], t[1] += s[l+1], l += 2, r--;
		else if (s[l+1] == s[r-2])
			t[0] += s[l+1], t[1] += s[l+1], l += 2, r -= 2;
		else
			assert(0);
	}

	reverse(t[1].begin(), t[1].end());
	cout << t[0] + t[1] << "\n";
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