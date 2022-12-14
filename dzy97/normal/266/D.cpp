#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N = 210;
struct edge{
	int x, y, w;
}e[N * N];
struct node{
	int x, y;
}a[N];
int n, m, f[N][N], ans = 1e9;
bool cmp(const node &a, const node &b){
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}
void work(int A, int B, int w){
	for(int i = 1;i <= n;i ++) a[i] = (node){f[i][A], f[i][B]};
	sort(a + 1, a + n + 1, cmp);
	int top = n, ret = 2 * a[n].x;
	for(int i = n - 1;i;i --) if(a[i].x < a[top].x && a[i].y > a[top].y) ret = min(ret, a[i].x + a[top].y + w), top = i;
	ret = min(ret, 2 * a[top].y);
	ans = min(ans, ret);
}
int main(){
	scanf("%d%d", &n, &m);
	memset(f, 63, sizeof(f));
	for(int i = 1;i <= n;i ++) f[i][i] = 0;
	for(int i = 1;i <= m;i ++) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].w), f[e[i].x][e[i].y] = f[e[i].y][e[i].x] = e[i].w;
	for(int k = 1;k <= n;k ++)
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for(int i = 1;i <= m;i ++) work(e[i].x, e[i].y, e[i].w);
	printf("%.2lf\n", ans / 2.0);
	return 0;
}