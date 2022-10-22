#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;

int n, a[MAXN], d[MAXN];
bool pic[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int temp;	
		scanf("%d", &temp);
		pic[temp] = 1;
	}

	fill(d, d + MAXN, 1);

	int ans = 0;
	for (int i = 1; i < MAXN; i++){
		if (pic[i])
			ans = max(ans, d[i]);
		if (pic[i])
			for (int j = i + i; j < MAXN; j += i)
				d[j] = max(d[j], d[i] + 1);
	}
	
	printf("%d\n", ans);
	return	0;
}