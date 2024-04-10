#include <bits/stdc++.h>

using namespace std;

void tc()
{
	int X[111], Y[111];
	int n, k, i, j, s;
	cin >> n >> k;

	for(i = 0; i < n; i ++){
		cin >> X[i] >> Y[i];
	}

	for(i = 0; i < n; i ++){
		s = 0;
		for(j = 0; j < n; j ++){
			if(abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= k){
				s ++;
			}
		}
		if(s == n){
			cout << "1\n"; return;
		}
	}
	cout << "-1\n";
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;

	for(; t --; ){
		tc();
	}
}