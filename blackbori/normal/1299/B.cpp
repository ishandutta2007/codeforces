#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll X[101010], Y[101010];
ll n;

void die() { cout << "NO\n"; exit(0); }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll i, j;

	cin >> n;

	if(n & 1) die();

	for(i = 0; i < n; i ++){
		cin >> X[i] >> Y[i];
	}

	X[n] = X[0]; Y[n] = Y[0];

	for(i = 0; i + i < n; i ++){
		if(X[i + 1] - X[i] != X[i + n / 2] - X[i + n / 2 + 1]) die();
		if(Y[i + 1] - Y[i] != Y[i + n / 2] - Y[i + n / 2 + 1]) die();
	}

	cout << "YES\n";

	return 0;
}