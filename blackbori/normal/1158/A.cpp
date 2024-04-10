#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;

priority_queue <pll> P;
ll A[101010], B[101010];
ll n, m, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j;
	pll t;
	
	cin >> n >> m;
	
	for(i=0; i<n; i++){
		cin >> A[i];
	}
	
	for(i=0; i<m; i++){
		cin >> B[i];
	}
	
	sort(A, A + n);
	sort(B, B + m);
	
	if(A[n - 1] > B[0]){
		cout << -1 << endl;
		return 0;
	}
	else{
		if(B[0] == A[n - 1]){
			for(i=0; i<n-1; i++){
				ans += A[i] * m;
			}
			for(i=0; i<m; i++){
				ans += B[i];
			}
		}
		else{
			for(i=0; i<n-2; i++){
				ans += A[i] * m;
			}
			ans += A[n - 2] * (m - 1) + B[0];
			ans += A[n - 1];
			for(i=1; i<m; i++){
				ans += B[i];
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}