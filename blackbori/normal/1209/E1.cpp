#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[2020][12];
int D[5050], S[5050];
int n, m;

void tc()
{
	int i, j, k, l, s;
	
	cin >> n >> m;
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			cin >> A[j][i];
		}
	}
	
	for(i=0; i<(1<<n); i++){
		D[i] = 0;
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<(1<<n); j++){
			for(k=0, S[j]=0; k<n; k++){
				if(j & (1 << k)){
					S[j] += A[i][k];
				}
			}
		}
		
		for(j=0; j<(1<<n); j++){
			for(k=0; k<n; k++){
				l = ((j << k) & ((1 << n) - 1)) + (j << k >> n);
				D[l] = max(D[l], D[j]);
			}
		}
		
		
		for(j=(1<<n)-1; j>=0; j--){
			for(k=j; k; k=(k-1)&j){
				D[j] = max(D[j], D[j - k] + S[k]);
			}
		}
	}
/*	
	for(i=0; i<(1<<n); i++){
		for(j=0; j<n; j++){
			k = ((i << j) & ((1 << n) - 1)) + (i << j >> n);
			D[k] = max(D[k], D[i]);
		}
	}
	
	for(i=0; i<(1<<n); i++){
		cout << i << " " << D[i] << "\n";
		for(j=i; j; j=(j-1)&i){
			D[i] = max(D[i], D[i - j] + D[j]);
		}
	}
*/	
	cout << D[(1 << n) - 1] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	for(; t--; ){
		tc();
	}
	
	return 0;
}