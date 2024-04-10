//	I know that it feels like we just pissed away our history
//	and just today I looked at your picture, almost hate to say
//	I missed you subconsciously
//  wish it didn't end this way, but I just had to get away, don't know why
//	I don't know what else to say..

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int max_n = 1e4 + 10;
const int MOD = 1e9 + 7;

int n, tx, ty;
char c[3][max_n];
int save[max_n];
ll d[max_n][10][10];

void paint(int mask){
	if (mask & 1){
		if (c[ty - 1][tx] == 'X')
			c[ty - 1][tx] = c[ty - 2][tx] = '.';
		else
			c[ty - 1][tx] = c[ty - 2][tx] = 'X';
	}
	if (mask & 2){
		if (c[ty][tx + 1] == 'X')
			c[ty][tx + 1] = c[ty][tx + 2] = '.';
		else
			c[ty][tx + 1] = c[ty][tx + 2] = 'X';
	}
	if (mask & 4){
		if (c[ty + 1][tx] == 'X')
			c[ty + 1][tx] = c[ty + 2][tx] = '.';
		else
			c[ty + 1][tx] = c[ty + 2][tx] = 'X';
	}
	if (mask & 8){
		if (c[ty][tx - 1] == 'X')
			c[ty][tx - 1] = c[ty][tx - 2] = '.';
		else
			c[ty][tx - 1] = c[ty][tx - 2] = 'X';
	}
}

ll f(int cur, int m1, int m2){
	if (cur == n + 3)	return 1;
	if (d[cur][m1][m2] != -1)	return	d[cur][m1][m2];
	if (m1 == 7)	return	d[cur][m1][m2] = f(cur + 1, m2, save[cur]);
	d[cur][m1][m2] = 0;

	if ((m1 & 1) == 0){
		if ((m2 & 1) == 0)	
			d[cur][m1][m2] = (d[cur][m1][m2] + f(cur, m1 ^ 1, m2 ^ 1)) % MOD;
		if ((m1 & 2) == 0)
			d[cur][m1][m2] = (d[cur][m1][m2] + f(cur, m1 ^ 3, m2)) % MOD;
	}
	else if ((m1 & 2) == 0){
		if ((m2 & 2) == 0)
			d[cur][m1][m2] = (d[cur][m1][m2] + f(cur, m1 ^ 2, m2 ^ 2)) % MOD;
		if ((m1 & 4) == 0)
			d[cur][m1][m2] = (d[cur][m1][m2] + f(cur, m1 ^ 6, m2)) % MOD;
	}
	else if ((m1 & 4) == 0){
		if ((m2 & 4) == 0)
			d[cur][m1][m2] = f(cur, m1 ^ 4, m2 ^ 4);
	}
	return	d[cur][m1][m2];
}

ll cal(){
	for (int i = 0; i < n; i++){
		save[i] = 0;
		if (c[0][i] == 'X')	save[i] += 1;
		if (c[1][i] == 'X')	save[i] += 2;
		if (c[2][i] == 'X')	save[i] += 4;
	}
	save[n] = save[n + 1] = save[n + 2] = save[n + 3] = save[n + 4] = 7;
	for (int i = 0; i <= n + 2; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
				d[i][j][k] = -1;
	return	f(2, save[0], save[1]);
}	

int get(int mask){
	if ((mask & 1) && (ty != 2 || c[ty - 1][tx] == 'X' || c[ty - 2][tx] == 'X'))	return	0;
	if ((mask & 2) && (tx > n - 3 || c[ty][tx + 1] == 'X' || c[ty][tx + 2] == 'X'))	return	0;
	if ((mask & 4) && (ty != 0 || c[ty + 1][tx] == 'X' || c[ty + 2][tx] == 'X'))	return	0;
	if ((mask & 8) && (tx < 2 || c[ty][tx - 1] == 'X' || c[ty][tx - 2] == 'X'))	return	0;
	paint(mask);
	ll ret = cal();
	paint(mask);
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++){
			cin >> c[i][j];
			if (c[i][j] == 'O')
				ty = i, tx = j, c[i][j] = 'X';
		}	

	ll ans = 0;
	for (int i = 1; i < 16; i++){
		int temp = get(i);
		if (__builtin_popcount(i) % 2 == 1)	
			ans = (ans + temp) % MOD;
		else
			ans = (ans + MOD - temp) % MOD;
	}
	cout << ans << endl;
	return 0;
}