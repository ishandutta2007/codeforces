#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string S;
int K[1101010], D[22][22];
int B[1101010], X[1101010], C[22][1101010];
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i, j, l, t;
	
	cin >> n >> m >> S;
	
	for(i=1; i<n; i++){
		D[S[i] - 'a'][S[i - 1] - 'a'] ++;
		D[S[i - 1] - 'a'][S[i] - 'a'] ++;
	}
	
	for(i=0; i<(1<<m); i++){
		for(j=0; j<m; j++){
			if(i & 1 << j) B[i] = j, X[i] ++;
		}
	}
	
	for(i=0; i<m; i++){
		for(j=1; j<(1<<m); j++) if(j & (1 << i)) {
			if(j == 1 << i){
				for(l=0; l<m; l++) if(l != i){
					C[i][j] -= D[i][l];
				}
			}
			else{
				t = B[j ^ (1 << i)];
				C[i][j] = C[i][j ^ (1 << t)] + 2 * D[i][t];
			}
		}
	}
	
	for(i=1; i<(1<<m); i++){
		K[i] = 1e9;
		for(j=0; j<m; j++) if(i & (1 << j)){
			K[i] = min(K[i], K[i ^ (1 << j)] + C[j][i] * X[i]);
		}
	}
	
	cout << K[i - 1] << "\n";
	
	return 0;
}