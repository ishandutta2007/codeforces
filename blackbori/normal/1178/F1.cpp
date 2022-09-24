#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;
ll D[555][555];
ll C[555];
ll n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll i, j, k, l, r, v1, v2, s1, s2;
	
	cin >> n >> m;
	
	for(i=1; i<=n; i++){
		cin >> C[i];
	}
	
	for(i=1; i<=n; i++){
		for(j=i; j<=n; j++){
			l = j - i + 1; r = j;
			for(k=l, m=l; k<=r; k++){
				if(C[m] > C[k]) m = k;
			}
			
			s1 = s2 = 0;
			
			for(k=m; k>=l; k--){
				v1 = (l <= k - 1? D[l][k - 1] : 1);
				v2 = (k <= m - 1? D[k][m - 1] : 1);
				s1 = (s1 + v1 * v2) % mod;
			}
			
			for(k=m; k<=r; k++){
				v1 = (m + 1 <= k? D[m + 1][k] : 1);
				v2 = (k + 1 <= r? D[k + 1][r] : 1);
				s2 = (s2 + v1 * v2) % mod;
			}
			
			D[l][r] = s1 * s2 % mod;
		}
	}
	
	cout << D[1][n] << "\n";
	
	return 0;
}