//Little did I know..
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int BASE = 701;
const int max_n = 5e6 + 40;

string s;
int n;
ll h[max_n], save[max_n], h2[max_n];
ll ans[max_n], sum;

ll get(int l, int r){
	return	(h2[l] + MOD - ((h2[r] * save[r - l]) % MOD)) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	
	n = s.size();

	save[0] = 1;
	for (int i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * BASE) % MOD;
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] * BASE + s[i]) % MOD;
	for (int i = n - 1; i >= 0; i--)
		h2[i] = (h2[i + 1] * BASE + s[i]) % MOD;

	ans[0] = sum = 1;
	for (int i = 1; i < n; i++){
		int sz = (i + 1)/ 2;
		if (h[sz] == get(i - sz + 1, i + 1))	ans[i] = ans[sz - 1] + 1;
		sum += ans[i];
	}
	cout << sum << endl;
	return 0;
}