#include <bits/stdc++.h>

using namespace std;

int A[101010], B[101010], X[101010];
int n, m, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n;
	
	for(i=0; i<n; i++){
		cin >> A[i];
		X[A[i]] = i;
	}
	
	for(i=0; i<n; i++){
		cin >> B[i];
	}
	
	m = n;
	
	for(i=n-1; i>=0; i--){
		if(m < X[B[i]]) ans ++;
		m = min(X[B[i]], m);
	}
	
	cout << ans << "\n";
	
	return 0;
}