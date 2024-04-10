#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int max_n = 1e6 + 200;

int n, m, k;
bool mark[max_n], ch[max_n];
int p[max_n];
ll save[max_n];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	bool fl = 0;
	int maxi = -1, mini = 1e9, cnt = 0;
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		if (b - a != 1 && b - a != k + 1)	fl = 1;

		if (b - a == k + 1){
			ch[b] = 1;
			maxi = max(maxi, b);
			mini = min(mini, b);
			cnt++;
		}
	}

	if (fl){
		printf("0\n");
		return 0;
	}

	save[0] = 1;
	for (int i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * 2) % MOD;
	if (maxi == -1){
		ll ans = 1;
		for (int i = k + 1; i < n; i++){
			int z = min(k, i - k - 1);
			ans = (ans + save[z]) % MOD;
		}
		printf("%d\n", (int)ans);
		return 0;
	}

	ll ans = 0;
	for (int i = maxi; i < n && i < mini + k + 1; i++){
		int z = min(k, i - k - 1);
		z -= cnt;
		if (i == maxi)	z++;
		ans = (ans + save[z]) % MOD;
	}
	printf("%d\n", (int)ans);
	return 0;
}