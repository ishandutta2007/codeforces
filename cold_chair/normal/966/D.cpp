#include<cstdio>
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define P pair<int, int>
#define mp make_pair<int, int> 
#define fi first
#define se second
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 6e5 + 5;

int n, m, x, y, r[N], mx[N];
int final[N], next[N], to[N], tot;
int d[N], bz[N], fd[N], dis[N];
int f[N];

void link(int x, int y) {
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
	next[++ tot] = final[y], to[tot] = x, final[y] = tot;
}

int find(int x) {return f[x] == x ? x : (f[x] = find(f[x]));}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, n) f[i] = i, mx[i] = 1;
	fo(i, 1, m) {
		scanf("%d %d", &x, &y);
		if(x != 1 && y != 1 && x != n && y != n)
		if(find(x) != find(y))
			mx[f[y]] += mx[f[x]], f[f[x]] = f[y];
		link(x, y);
	}
	fo(i, 2, n) for(int j = final[i]; j; j = next[j]) if(to[j] != 1)
		r[i] ++;
	fo(i, 2, n) mx[i] = mx[find(i)];
	bz[1] = 1; d[d[0] = 1]  = 1; dis[1] = 0;
	fo(i, 1, d[0]) {
		int x = d[i];
		for(int j = final[x]; j; j = next[j]) {
			int y = to[j]; if(bz[y]) continue;
			bz[y] = 1;
			dis[y] = dis[x] + 1;
			fd[y] = x;
			d[++ d[0]] = y;
		}
	}
	if(dis[n] > 0 && dis[n] <= 3) {
		printf("%d\n", dis[n]);
		d[0] = 0;
		while(n != 1) {
			d[++ d[0]] = n;
			n = fd[n];
		}
		printf("1");
		fd(i, d[0], 1) printf(" %d", d[i]);
		return 0;
	}
	memset(bz, 0, sizeof bz);
	for(int i = final[1]; i; i = next[i]) bz[to[i]] = 1;
	for(int i = final[1]; i; i = next[i]) {
		int x = to[i]; if(x == 1) continue;
		for(int j = final[x]; j; j = next[j]) {
			int y = to[j]; if(y == 1 || x == y) continue;
			if(!bz[y]) {
				printf("4\n1 %d %d 1 %d\n", x, y, n);
				return 0;
			}
		}
	}
	memset(bz, 0, sizeof bz);
	for(int ii = final[1]; ii; ii = next[ii]) {
		int x = to[ii]; if(r[x] + 1 == mx[x]) continue;
		for(int j = final[x]; j; j = next[j]) bz[to[j]] = x;
		for(int j = final[x]; j; j = next[j]) {
			int y = to[j]; if(y == 1 || y == x) continue;
			for(int k = final[y]; k; k = next[k]) {
				int z = to[k]; if(z == 1 || z == y || z == x) continue;
				if(bz[z] != x) {
					printf("5\n1 %d %d %d %d %d\n", x, y, z, x, n);
					return 0;
				}
			}
		}
	}
	printf("-1");
}