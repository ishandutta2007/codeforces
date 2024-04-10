#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> X;
ll A[303030], L[303030], R[303030];
ll n, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll q, i, s;
	
	cin >> q;
	
	for(; q--; ){
		cin >> n;
		
		X.clear();
		
		for(i=0; i<n; i++){
			cin >> A[i];
			X.push_back(A[i]);
			L[i] = n - 1; R[i] = 0;
		}
		
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		
		for(i=0; i<n; i++){
			A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
			L[A[i]] = min(L[A[i]], i); R[A[i]] = max(R[A[i]], i);
		}
		
		ans = n;
		
		for(i=0; i<X.size(); i++){
			if(!i || R[i - 1] > L[i]) s = 1;
			else s ++;
			ans = min(ans, (ll)X.size() - s);
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}