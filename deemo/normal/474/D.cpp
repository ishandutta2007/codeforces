#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 2e5;

int t, k;
int a, b;
ll d[max_n], par[max_n];

void init(){
	d[0] = 1;
	par[0] = 1;
	for (int i = 1; i < max_n; i++){
		d[i] = d[i - 1];
		if (i >= k)	d[i] += d[i - k];
		par[i] = (par[i - 1] + d[i]) % MOD;
		d[i] %= MOD;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> k;
	init();
	while(t--){
		cin >> a >> b;
		cout << (par[b] + MOD - par[a - 1]) % MOD << endl;
	}
	return 0;
}