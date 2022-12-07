#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
const int M = 1000000007;

int n, p;
int f[51][51][51][51];
int c[51], pw[51];

int main(){
	scanf("%d%d", &n, &p);
	f[0][0][0][0] = 1;
	pw[0] = 1;
	for(int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * 2 % M;
	for(int i = 1; i <= n; ++i){
		scanf("%d", c + i);
		if(c[i] != 1){ // 0
			for(int j = 0; j < i; ++j) //0
				for(int k = 0; k <= j; ++k) // 0 odd
					for(int l = 0; l < i - j; ++l){ // 1 odd
						ll tmp = (ll)f[i - 1][j][k][l] * pw[i - 1 - j - l] % M * pw[j] % M;
						f[i][j + 1][k][l] = (f[i][j + 1][k][l] + tmp * (l ? pw[l - 1] : 0)) % M; // even
						f[i][j + 1][k + 1][l] = (f[i][j + 1][k + 1][l] + tmp * (l ? pw[l - 1] : 1)) % M; //odd
					}
		}if(c[i] != 0){ // 1
			for(int j = 0; j < i; ++j) //0
				for(int k = 0; k <= j; ++k) // 0 odd
					for(int l = 0; l < i - j; ++l){ // 1 odd
						ll tmp = (ll)f[i - 1][j][k][l] * pw[j - k] % M * pw[i - 1 - j] % M;
						f[i][j][k][l] = (f[i][j][k][l] + tmp * (k ? pw[k - 1] : 0)) % M; //even
						f[i][j][k][l + 1] = (f[i][j][k][l + 1] + tmp * (k ? pw[k - 1] : 1)) % M;
					}
		}
	}

	int sum = 0;
	for(int j = 0; j <= n; ++j)
		for(int k = 0; k <= j; ++k)
			for(int l = 0; l <= n - j; ++l){
				if(((k + l) & 1) != p) continue;
				//printf("%d %d %d %d\n", j, k, l, f[n][j][k][l]);
				sum = (sum + f[n][j][k][l]) % M;
			}

	printf("%d\n", sum);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}