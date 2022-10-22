#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAX = 1e6 + 20;

int n;
int ans[MAX];
bool mark[MAX];

int get(int x){
	int ret = 0, t = 1;
	while (x){
		if ((x & 1) == 0)
			ret |= t;
		x >>= 1;
		t <<= 1;
	}
	return	ret;
}

int main(){
	scanf("%d", &n);
	ll sum = n;
	sum *= (n + 1);
	printf("%I64d\n", sum);
	if (n % 2 == 0)	mark[0] = 1, ans[0] = 0;

	for (int i = n; i >= 0; i--){
		if (mark[i])	continue;

		int g = get(i);
		mark[i] = mark[g] = 1;
		ans[g] = i;
		ans[i] = g;
	}
	for (int i = 0; i <= n; i++)	
		printf("%d ", ans[i]);
	printf("\n");
	return 0;	
}