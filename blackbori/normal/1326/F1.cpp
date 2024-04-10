#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string S[22];
int X[32222], L[16666][15][133], R[16666][15][64];
ll A[16666];
int n;

void f(int p, int b, int t, int s1, int s2)
{
	if(p == n + 1 >> 1) R[b][t][s2] ++;
	if(p == n + 2 >> 1){
		L[b][t][s1 >> 1] ++;
		return;
	}

	int i, x, y;
	y = ((1 << n) - 1) & ~b;
	for(; y; y -= y & -y){
		i = X[y & -y];
		if(~b & 1 << i){
			x = t == -1? 0 : S[i][t] - '0';
			f(p + 1, b | 1 << i, i, s1 | x << p, s2 << 1 | x);
		}
	}
}

void calc(int b)
{
	int c, i, j, x1, x2;
	for(i = 0; i < n; i ++) if(b & 1 << i){
		c = ((1 << n) - 1 & ~b) | 1 << i;
		for(j = 0; j < 1 << n - 1; j ++){
			x2 = j >> (n >> 1);
			x1 = j & ~(x2 << (n >> 1));
			A[j] += L[b][i][x1] * R[c][i][x2];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j, s;

	cin >> n;

	for(i = 0; i < n; i ++){
		cin >> S[i];
		X[1 << i] = i;
	}

	f(0, 0, -1, 0, 0);

	for(i = 0; i < 1 << n; i ++){
		for(j = 0, s = 0; j < n; j ++){
			if(i & 1 << j) s ++;
		}
		if(s == n + 2 >> 1){
			calc(i);
		}
	}

	for(i = 0; i < 1 << n - 1; i ++){
		cout << A[i] << " ";
	}
	cout << endl;
	
	return 0;
}