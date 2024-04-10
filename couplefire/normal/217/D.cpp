#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;
 
typedef long long ll;
const int MAXN = 120;
const int MOD = 1e9 + 7;
bitset <MAXN + 6> S;
int cntv[MAXN + 6];
int t, m, n; ll ans;
 
void DFS(bitset <MAXN + 6> S, int cur, ll mulv){
	ans = (ans + mulv) % MOD;
	for(int i = cur; i <= m >> 1; ++ i)
		if(cntv[i] && !S[i] && !S[m - i])
			DFS(S | S << i | S >> i | S << m - i | S >> m - i, i + 1, mulv * cntv[i] % MOD);
}
 
int main(){
	scanf("%d%d%d", &t, &m, &n);
	for(int i = 1, j; i <= n; ++ i){
		scanf("%d", &j); j %= m;
		cntv[min(j, m - j)] ++;
	}
	S[0] = 1; DFS(S, 1, 1);
	printf("%lld\n", ans);
	return 0;
}