#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int a[maxn];
int b[21][21];

int g[(1<<21)];
int f[(1<<21)];

int main(){
	int i, j, k;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		char ch;
		scanf(" %c", &ch);
		a[i] = ch - 'a';
	}
	
	for(i=2;i<=n;i++){
		int x = a[i - 1], y = a[i];
		if(x > y)swap(x, y);
		b[x][y]++;
		b[y][x]++;
	}
	
	for(i=1;i<(1<<m);i++){
		for(j=0;j<m;j++){
			if(!((i >> j) & 1))continue;
			for(k=0;k<m;k++){
				if((i >> k) & 1)continue;
				g[i] += b[j][k];
			}
		}
	}
	
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	
	for(i=0;i<(1<<m);i++){
		for(j=0;j<m;j++){
			if((i >> j) & 1)continue;
			int mask = (i | (1 << j));
			int sum = g[mask];
			f[mask] = min(f[mask], f[i] + sum);
		}
	}
	
	printf("%d\n", f[(1 << m) - 1]);
	
	return 0;
}