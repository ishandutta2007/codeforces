#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string A, B;
int X[1010101], Y[1010101];
int C[2][1101010];
int P[22];
int n, m, k, s, l, r;

void dfs(int f, int b, int t)
{
	if(C[f][b]) return;

	int i, c = 0;

	C[f][b] = t;
	for(i = 0; i < k; i ++){
		if(b & 1 << i){
			c ++; dfs(f, b & ~(1 << i), t);
		}
	}

	if(f && C[0][b] && t - C[0][b] + 1 >= m && s < c){
		s = c; l = C[0][b]; r = t;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, j, x, y, a, b;

	cin >> n >> m >> k >> A >> B;
	
	for(i = 0; i < k; i ++) P[i] = i;

	x = y = 0;
	for(j = 0; j < k; j ++){
		if(A[P[j]] == '1') x |= 1 << j;
		if(B[P[j]] == '1') y |= 1 << j;
	}

	X[0] = x; Y[0] = y;

	for(i = 1; i <= n; i ++){
		cin >> a >> b; a --; b --;
		swap(P[a], P[b]);

		x = y = 0;
		for(j = 0; j < k; j ++){
			if(A[j] == '1') x |= 1 << P[j];
			if(B[j] == '1') y |= 1 << P[j];
		}

		X[i] = x; Y[i] = y;
	}

	s = 0; l = 1; r = n;

	for(i = 0; i < n; i ++){
		dfs(0, X[i], i + 1);
	}

	for(i = n; i >= 1; i --){
		dfs(1, Y[i], i);
	}

	a = b = 0;
	for(i = 0; i < k; i ++){
		if(A[i] == '1') a ++;
		if(B[i] == '1') b ++;
	}

	cout << k + s + s - a - b << "\n" << l << " " << r << "\n";

	return 0;
}