#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> A, B;
ll X[101010], Y[101010];
ll n, s, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j, l, x, y, f;
	
	cin >> n;
	
	for(i = 0; i < n; i ++){
		cin >> l >> x;
		X[i] = Y[i] = x;
		
		for(f = 0; -- l; ){
			cin >> y;
			X[i] = max(X[i], y);
			Y[i] = min(Y[i], y);
			if(x < y) f = 1;
			x = y;
		}
		
		if(f) s ++;
		else A.push_back(X[i]), B.push_back(Y[i]);
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	
	ans = 2 * s * n - s * s;
	
	for(i = 0, j = 0; i < A.size(); i ++){
		for(; j < B.size() && B[j] < A[i]; j ++);
		ans += j;
	}
	
	cout << ans << "\n";
	
	return 0;
}