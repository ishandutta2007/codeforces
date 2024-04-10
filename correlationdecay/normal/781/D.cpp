#include <cstdio>
#include <cmath>
#include <cstring>
#include <bitset>
#include <iostream>
#define maxn 509
using namespace std;
bitset<maxn>A[61][maxn], B[61][maxn], tmp, C[maxn], path[maxn], test[maxn];
const long long INF = 1e18;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0 ; i <= 60; i++){
		for(int j = 0 ; j <= n; j++){
			A[i][j].reset();
			B[i][j].reset();
		}
	}
	for(int i = 0 ; i < m; i++){
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		if(t == 0){
			A[0][u][v] = 1;
		}
		else{
			B[0][u][v] = 1;
		}
	}
	
	for(int i = 1; i <= 60; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				C[j][k] = B[i - 1][k][j];
			}
		}
		for(int j = 1; j <=n ;j++){
			for(int k = 1; k <= n; k++){
				tmp = A[i - 1][j] & C[k];
				if(tmp.any())
					A[i][j][k] = 1;
				else
					A[i][j][k] = 0;
			}
		}
		
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				C[j][k] = A[i - 1][k][j];
			}
		}
		for(int j = 1; j <=n ;j++){
			for(int k = 1; k <= n; k++){
				tmp = B[i - 1][j] & C[k];
				if(tmp.any())
					B[i][j][k] = 1;
				else
					B[i][j][k] = 0;
			}
		}
	}
	
	
	long long ans = 0;
	int cur = 0;
	for(int i = 1;i <= n; i++){
		path[i].reset();
		path[i][i] = 1;
	}		
	
	for(int i = 60; i >= 0; i--){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(cur == 0)
					C[j][k] = A[i][k][j];
				else
					C[j][k] = B[i][k][j];
			}
		}
		for(int j = 1; j <=n ;j++){
			for(int k = 1; k <= n; k++){
				tmp = path[j] & C[k];
				if(tmp.any())
					test[j][k] = 1;
				else
					test[j][k] = 0;
			}
		}
		if(test[1].any()){
			for(int j = 1; j <= n; j++){
				path[j] = test[j];
			}
			cur ^= 1;
			ans += (1LL << i);
		}
		if(ans > INF){
			break;
		}
	}
	if(ans > INF) ans = -1;
	cout << ans << endl;
	return 0;
}