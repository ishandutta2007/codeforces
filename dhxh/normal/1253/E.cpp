#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;

int f[maxn];
int a[105], b[105], c[105];

bool cmp(int x, int y){
	return a[x] > a[y];
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d%d", &a[i], &b[i]);
		c[i] = i;
	}
	
	memset(f, 0x3f, sizeof(f));
	f[m + 1] = 0;
	
	sort(c + 1, c + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		x = c[i];
		int minx = inf;
		for(j=1;j<=a[x]+b[x]+1;j++){
			minx = min(minx, f[j]);
		}
		
		f[max(1, a[x] - b[x])] = min(f[max(1, a[x] - b[x])], minx);
		
		for(j=1;a[x]+b[x]+j<=2*m;j++){
			minx = min(minx, f[a[x] + b[x] + j + 1]);
			f[max(1, a[x] - b[x] - j)] = min(f[max(1, a[x] - b[x] - j)], minx + j);
		}
	}
	
	printf("%d\n", f[1]);
	
	return 0;
}