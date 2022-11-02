 #include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#define maxn 1000009
using namespace std;
const int MOD = 1e9 + 7;
int f[maxn][20], tot;
int p[maxn];
bool flag[maxn];
vector<int>G[maxn];
void init(){
	for(int  i = 2; i < maxn; i++){
		if(!flag[i])
			p[tot++] = i;
		for(int j = 0; j < tot && 1LL * i * p[j] < maxn; j++){
			flag[i * p[j]] = 1;
			if(i % p[j] == 0)
				break;
		}
	}
	for(int i = 0; i < tot; i++){
		for(int j = p[i]; j < maxn; j += p[i]){
			int  x = j;
			int  cnt = 0;
			while(x % p[i] == 0){
				x /= p[i];
				cnt++;
			}
			G[j].push_back(cnt);
		}
	}
}
int main(){
	f[0][0] = 1;
	for(int i = 1 ; i <= 19; i++){
		f[0][i] = 2;
	}
	for(int i = 1; i < maxn; i++){
		f[i][0] = f[i - 1][0];
		for(int j = 1; j <= 19; j++){
			f[i][j] = (f[i][j - 1] + f[i - 1][j]) % MOD;
		}
	}

	init();

	int tt,r , n;
	scanf("%d", &tt);
	while(tt--){
		scanf("%d%d", &r, &n);
		int ans = 1;
		for(int i = 0; i < G[n].size(); i++){
			ans = (1LL * ans * f[r][G[n][i]]) % MOD;
		}
		printf("%d\n", ans);
	}	
	return 0;
}