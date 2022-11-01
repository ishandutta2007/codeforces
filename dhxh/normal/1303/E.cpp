#include <bits/stdc++.h>

using namespace std;

int t;

int n, m;
string A, B;

int f[405][405];

int main(){
	int i, j, k;
	
	cin >> t;
	
	while(t--){
		cin >> A >> B;
		n = A.length(), m = B.length();
		A = "0" + A;
		B = "0" + B;
		
		i = 1, j = 1;
		for(i=1;i<=n;i++){
			if(A[i] == B[j]){
				j++;
				if(j == m + 1) break;
			}
		}
		
		if(j == m + 1){
			cout << "YES" << endl;
			continue;
		}
		
		bool flag = false;
		for(k=1;k<n;k++){
			memset(f, 0, sizeof(f));
			
			f[0][0] = k;
			
			for(i=0;i<n;i++){
				for(j=0;j<=k;j++){
					if(f[i][j] == 0) continue;
					f[i + 1][j] = max(f[i + 1][j], f[i][j]);
					if(j < k and A[i + 1] == B[j + 1]){
						f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
					}
					
					if(f[i][j] < m and A[i + 1] == B[f[i][j] + 1]){
						f[i + 1][j] = max(f[i + 1][j], f[i][j] + 1);
					}
				}
			}
			
			if(f[n][k] == m){
				flag = true;
				break;
			}
		}
		
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}