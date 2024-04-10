#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, d[1<<6][1<<6][1<<6][50];
bool vis[1<<6][1<<6][1<<6][50];

int f(int mask, int ind){
	if (ind < 0)	return	mask;
	if ((mask >> ind) & 1)	mask ^= 1<<ind;
	return	mask;
}	

int solve(int a, int b, int c, int rem){
	if (vis[a][b][c][rem])	return	d[a][b][c][rem];
	vis[a][b][c][rem] = 1;
	if (rem == 0 && a == 0 && b == 0 && c == 0)	return	d[a][b][c][rem] = 0;
	d[a][b][c][rem] = 1e5;
	for (int i = 0; i < n; i++)
		if ((a >> i) & 1){
			d[a][b][c][rem] = min(d[a][b][c][rem], solve(f(f(a, i), i + 1), f(b, i), c, rem) + 1);
			d[a][b][c][rem] = min(d[a][b][c][rem], solve(f(f(f(a, i), i + 1), i + 2), f(b, i + 1), c, rem) + 1);
			d[a][b][c][rem] = min(d[a][b][c][rem], solve(f(a, i), f(f(f(b, i - 1), i), i + 1), f(c, i), rem) + 1);
		}

	if (a == 0){
		if (rem)	
			d[a][b][c][rem] = min(d[a][b][c][rem], solve(b, c, (1<<n) - 1, rem - 1));
		else
			d[a][b][c][rem] = min(d[a][b][c][rem], solve(b, c, 0, rem));
	}
	return	d[a][b][c][rem];
}

int main(){
	cin >> n >> m;
	if (n > m)	swap(n, m);
	int a = (1<<n) -1, b = 0, c = 0;
	if (m > 1)	b = (1 << n) -1;
	if (m > 2)	c = (1<<n) - 1;
	cout << n * m - solve(a, b, c, max(0, m - 3)) << "\n";
	return	0;
}