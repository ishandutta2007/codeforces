#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 2e3 + 200;

int n, cnt;
int a[max_n + 5];
bool seen[max_n + 4], mark[max_n + 4];
vector<int>	vec;
ll d[max_n + 3][max_n + 3];
int c[max_n + 3];

void init(){
	d[0][0] = 1;
	for (int i = 1; i < max_n; i++){
		d[i][i] = d[i][0] = 1;
		for (int j = 1; j < i; j++)
			d[i][j] = (d[i - 1][j] + d[i - 1][j - 1]) % MOD;
	}

	c[0] = c[1] = 1;
	for (int i = 2; i < max_n; i++)
		c[i] = (ll(c[i - 1]) * i) % MOD;
}

ll get(int x){
	ll temp = (d[cnt - x][vec.size() - x] * c[vec.size() - x]) % MOD;
	return (d[vec.size()][x] * temp) % MOD;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (a[i] != -1)	seen[a[i]] = 1;
		if (a[i] != -1)
			mark[i + 1] = 1;
		if (a[i] == -1)	cnt++;
	}	

	for (int i = 1; i <= n; i++){
		if (seen[i])	continue;
		if (mark[i])	continue;
		vec.push_back(i);
	}	
	init();

	ll t = 0;
	for (int i = 1; i <= vec.size(); i++)
		if (i % 2 == 1)
			t = (t + get(i)) % MOD;
		else
			t = (t + MOD - get(i)) % MOD;
	t = (t * c[cnt - vec.size()]) % MOD;
	cout << (c[cnt] + MOD - t) % MOD << endl;
	return 0;
}