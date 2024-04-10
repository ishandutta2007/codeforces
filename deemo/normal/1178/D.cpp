#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int MAXN = 2e3 + 10;//XXX
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
vector<pii> vec;
bool pr[MAXN];
void solve() {
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXN; i++)
		for (int j = i+i; j < MAXN; j += i)
			pr[j] = 1;

	for (int i = 3; i <= 1000; i++){
		int t = 0, j = i;
		while (pr[j])
			j++, t++;
		assert(t <= i/2);
	}

	cin >> n;
	for (int i = 0; i < n; i++)
		vec.push_back({i, (i+1)%n});
	int cur = n, ind = 0;
	while (pr[cur]){
		cur++;
		vec.push_back({ind, ind + n/2});
		ind++;
	}
	
	cout << vec.size() << "\n";
	for (auto x:vec)
		cout << x.F+1 << " " << x.S+1 << "\n";
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