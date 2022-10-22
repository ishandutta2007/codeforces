#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e6 + 20;

int ans[MAXN];

int main(){
	int n, k;	scanf("%d%d", &n, &k);
	if (3 * k > n){
		printf("-1\n");
		return 0;
	}
	int tt = n;
	n = 3 * k;
	int cnt = 1, cur = 0;

	if (k % 2 == 1){
		ans[0] = ans[1] = ans[3] = cnt++;
		ans[2] = ans[5] = ans[6] = cnt++;
		ans[4] = ans[7] = ans[8] = cnt++;
		cur = 9;
	}

	for (int i = cur; i < n; i += 6){
		ans[i] = ans[i + 1] = ans[i + 3] = cnt++;
		ans[i + 2] = ans[i + 4] = ans[i + 5] = cnt++;
		cur += 6;
	}

	for (; cur < tt; cur++)
		ans[cur] = 1;

	for (int i = 0; i < tt; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}