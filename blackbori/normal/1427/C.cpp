#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int X[101010], Y[101010], T[101010], D[101010], M[101010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, i, j, t;

	cin >> r >> n;

	X[0] = Y[0] = 1;
	for(i = 1; i <= n; i ++){
		cin >> T[i] >> X[i] >> Y[i]; t = 0;
		for(j = i - 1; j >= 0 && T[i] - T[j] <= r + r; j --){
			if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T[i] - T[j]){
				if(!j || D[j]) t = max(t, D[j] + 1);
			}
		}
		if(j >= 0) t = max(t, M[j] + 1);
		D[i] = t; M[i] = max(M[i - 1], t);
	}

	cout << M[n] << "\n";

	return 0;
}