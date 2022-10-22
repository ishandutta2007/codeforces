#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 1e6 + 8e5;
const int LOG = 20;
const int MOD = 1e9 + 7;

int n;
int vec[max_n];
int save[max_n], d[max_n][LOG + 4];
int cnt[max_n];

void init(){
	save[0] = 1;
	for (int i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * 2) % MOD;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		cnt[vec[i]]++;
	}
	init();
	
	int z = 1 << 20;
	ll sum = 0;
	for (int i = z; i; i--){
		d[i][LOG] = cnt[i];
		for (int j = LOG - 1; j >= 0; j--){
			if (((i>>j) & 1) == 1)	d[i][j] = d[i][j+1];
			else	d[i][j] = d[i][j+1] + d[i ^ (1<<j)][j];
		}
		
		int t = __builtin_popcount(i);
		if (t % 2 == 0)	sum = (sum + MOD * 2 - save[d[i][0]] + 1) % MOD;
		else	sum = (sum + save[d[i][0]] - 1)	% MOD;
	}
	sum = (save[n] - 1 - sum + 2 * MOD) % MOD;
	printf("%I64d\n", sum);
	return 0;
}