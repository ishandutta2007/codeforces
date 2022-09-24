#include <bits/stdc++.h>

using namespace std;

string A[22], B[22];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, q, x;
	
	cin >> n >> m;
	
	for(i = 0; i < n; i ++){
		cin >> A[i];
	}
	
	for(i = 0; i < m; i ++){
		cin >> B[i];
	}
	
	cin >> q;
	
	for(; q --; ){
		cin >> x; x --;
		cout << A[x % n] << B[x % m] << "\n";
	}
	
	return 0;
}