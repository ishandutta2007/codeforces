#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m;
int vec[MAXN], sec[MAXN];
int cnt[MAXN], cc[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);
		sec[i] = vec[i];
	}
	int tn = n;
	sort(vec, vec + n);
	for (int i = 0; i < n;){
		int j = i;
		while (j < n && vec[i] == vec[j])	j++;
		if (vec[i] <= m)	cnt[vec[i]] = j - i;
		i = j;
	}
	n = unique(vec, vec + n) - vec;
	for (int i = 0; i < n; i++)
		for (int j = vec[i]; j < MAXN; j += vec[i])
			cc[j] += cnt[vec[i]];

	int ans = 1, c = 0;
	for (int i = 1; i <= m; i++)
		if (cc[i] > c){
			ans = i;
			c = cc[i];
		}

	printf("%d %d\n", ans, c);
	for (int i = 0; i < tn; i++)
		if (ans % sec[i] == 0)	printf("%d ", i + 1);
	printf("\n");
	return	0;
}