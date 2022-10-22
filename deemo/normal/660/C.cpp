#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 3e5 + 10;

int n, k;
int a[MAXN], p[MAXN];

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), p[i + 1] = p[i] + int(a[i] == 0);

	int mx = -1, ind = -1;
	for (int i = 0; i < n; i++){
		int b = i, e = n, ret = i;
		while (b <= e){
			int mid = (b + e)/ 2;
			if (p[mid] - p[i] <= k)
				ret = mid, b = mid + 1;
			else
				e = mid - 1;
		}
		if (mx < ret - i){
			ind = i;
			mx = ret - i;
		}
	}
	printf("%d\n", mx);
	for (int i = ind; i <= n && k; i++)
		if (a[i] == 0)	a[i] = 1, k--;
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return	0;
}