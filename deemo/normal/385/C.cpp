#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 1e7;

int n;
int a[MAX], f[MAX + 20], ans[MAX + 20], cnt[MAX + 20];
bool pr[MAX + 20];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);	
		cnt[a[i]]++;
	}

	pr[1] = 1;
	for (int i = 2; i <= MAX; i++)
		for (int j = i + i; j <= MAX; j += i)
			pr[j] = 1;
	
	for (int i = 2; i <= MAX; i++)
		if (!pr[i])
			for (int j = i; j <= MAX; j += i)
				f[i] += cnt[j];

	ans[0] = 0;
	for (int i = 1; i <= MAX; i++)
		ans[i] = ans[i - 1] + f[i];
	int m;
	scanf("%d", &m);
	while (m--){
		int l, r;	scanf("%d%d", &l, &r);
		if (l > MAX){
			printf("0\n");
			continue;
		}
		r = min(r, MAX);
		printf("%d\n", ans[r] - ans[l - 1]);
	}	
	return 0;
}