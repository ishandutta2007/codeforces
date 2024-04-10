#include<cstdio>
using namespace std;
const int N = 100005;
int n, num, h[N], e[N<<1], pre[N<<1];
double ans;
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u, int fa=0, int dep=1){
	ans+=1./dep;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa) dfs(e[i], u, dep+1);
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i) scanf("%d%d", &x, &y), add(x, y), add(y, x);
	return dfs(1), printf("%.20lf", ans), 0;
}