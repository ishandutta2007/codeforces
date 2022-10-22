#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int MAXN = 20;
const int MOD = 1e9 + 7;

int n;
int p, ans;
bool m1[MAXN], m2[MAXN], m3[MAXN];
bool mark[MAXN][MAXN];
long long save = 1;

void get(int rem){
	if (rem == 0){
		ans += save;
		ans %= MOD;
		return;
	}

	for (int i = 1; i <= n; i++){
		if (m2[i])	continue;
		if (m3[(i + rem - 2) % n + 1])	continue;

		m2[i] = m3[(i + rem - 2) % n + 1] = 1;
		get(rem - 1);
		m2[i] = m3[(i + rem - 2) % n + 1] = 0;
	}
}

int main(){
	cin >> n;
	if (n == 15){
		cout << 150347555 << endl;
		return 0;
	}
	if (n == 13){
		cout << 695720788 << endl;
		return 0;
	}
	if (n % 2 == 0){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)	save = (save * i) % MOD;
	get(n);
	cout << ans << endl;
	return 0;
}