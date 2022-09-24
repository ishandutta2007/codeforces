#include <bits/stdc++.h>

using namespace std;

int A[202020];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n, i, l, r, m;
	
	cin >> t;
	
	for(; t --; ){
		cin >> n;
		
		for(i = 1; i <= n; i ++){
			cin >> A[i];
		}
		
		l = -1; r = -1;
		
		for(i = 1, m = -1; i <= n; i ++){
			if(m != -1 && A[i] - i > A[m] - m){
				l = m; r = i; break;
			}
			
			if(m == -1 || A[i] - i < A[m] - m) m = i;
		}
		
		if(l != -1){
			cout << "YES\n" << l << " " << r << "\n";
			continue;
		}
		
		for(i = 1, m = -1; i <= n; i ++){
			if(m != -1 && A[i] + i < A[m] + m){
				l = m; r = i; break;
			}
			
			if(m == -1 || A[i] + i > A[m] + m) m = i;
		}
		
		if(l != -1){
			cout << "YES\n" << l << " " << r << "\n";
			continue;
		}
		
		cout << "NO\n";
	}
	
	return 0;
}