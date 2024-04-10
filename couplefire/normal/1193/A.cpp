#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define SP fixed << setprecision(10)
#define ER(x) cout << #x << " = " << x << endl;
 
using namespace std;
 
const long long MOD = 998244353;
const int N = 20 , P = 1000000;
int mat[N][N] , edge[P] , ind[P] , bp[P];
long long d[P] , num[P];
 
 
int main(){
 
	ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	int n, u, v, tmp;
   	long long c , m;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		mat[--u][--v] = 1;
		mat[v][u] = 1;
	}	
	
	for(int i = 0; i < n; i++)
		ind[1 << i] = 1;
 
 
	int p = (1 << n);
	
	for(int i = 1; i < p; i++){
		int l = i & (-i) , rem = l ^ i;
		l = __builtin_ctz(l);
		edge[i] = edge[rem];
		while(rem){
			int tmp = rem & (-rem);
			rem ^= tmp;
			edge[i] += mat[l][__builtin_ctz(tmp)];
		}
		
		bp[i] = __builtin_popcount(i);
		ind[i] = (edge[i] == 0);
	}
	
	num[0] = 1;
 
	for(int mask = 1; mask < p; mask++){
		for(int smask = mask; smask > 0; smask = (smask-1) & mask){
			if(ind[smask]){
				tmp = mask ^ smask;
				c = (bp[smask] & 1? 1 : -1);
				num[mask] += c*num[tmp];
//				d[mask] += c*(d[tmp] + (edge[mask] - edge[tmp])*num[tmp]);			
			}
		}
 
//		d[mask] = (d[mask]%MOD + MOD)%MOD;
		num[mask] = (num[mask]%MOD + MOD)%MOD;
	}
 
	cout << (num[p-1]*m % MOD *(MOD + 1)/2) % MOD;
 
	return 0;
}