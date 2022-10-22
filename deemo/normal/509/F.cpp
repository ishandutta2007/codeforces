#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAXN = 500 + 5;

int n, vec[MAXN], pos[MAXN];
ll p[MAXN][MAXN], d[MAXN][MAXN];

int main(){
	cin >> n;	
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		pos[vec[i]] = i;
	}

	for (int l = n - 1; l >= 0; l--)
		for (int r = l + 1; r <= n; r++){
			if (r - l == 1)
				d[l][r] = 1;
			else{
				for (int maxi = 1; maxi <= n; maxi++){
					int ind = pos[maxi];
					if (ind < l || ind >= r){
						p[r][maxi] = p[r][maxi - 1];
						continue;
					}
					
					ll ret;
					if (ind == l + 1)	
						ret = d[ind][r];
					else
						ret = (d[ind][r] * p[ind][maxi - 1]) % MOD;
					p[r][maxi] = (p[r][maxi - 1] + ret) % MOD;
				}
				d[l][r] = p[r][n];
			}
		}
	cout << d[0][n] << "\n";
	return	0;
}