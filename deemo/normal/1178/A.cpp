#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int MAXN = 100 + 5;//XXX
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

int n, a[MAXN];
int sec[MAXN];

bool cmp(int u, int v){return a[u] < a[v];}

void solve() {
	cin >> n;
	int sm = 0;
	for (int i = 0; i < n; i++) cin >> a[i], sm += a[i];
	iota(sec, sec + n, 0);
	sort(sec+1, sec + n, cmp);
	int sm2 = a[0];
	int i;
	for (i = 1; i < n && a[sec[i]] <= a[0]/2; i++)
		sm2 += a[sec[i]];
	if (sm2 * 2 <= sm)
		cout << "0\n";
	else{
		cout << i << "\n";
		for (int j = 0; j <i; j++)
			cout << sec[j]+1 << " ";
		cout << "\n";
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