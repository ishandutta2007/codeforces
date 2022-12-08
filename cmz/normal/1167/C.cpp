#include<cstdio>
using namespace std;
const int MAXN=5e5+100;
int n,m,k,x,last,top,aa;
int ans[MAXN],fa[MAXN];
bool vis[MAXN];
inline int max(int x,int y){
	if (x>y) return x; else return y;
}
int find(int x) {
	int r=x;
	while ( fa[r ] != r )
		r=fa[r ];
	int i=x , j ;
	while( i != r ) {
		j = fa[ i ];
		fa[ i ]= r ;
		i=j;
	}
	return r ;
}
void join(int x,int y) {
	int fx=find(x),fy=find(y);
	if(fx!=fy)
		fa[fx ]=fy;
}
int kkkkk;
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; ++i) fa[i]=i;
	for (int i=1; i<=m; ++i) {
		scanf("%d",&k);
		if (k==0) {
			continue;
		}
		if (k==1) {
			scanf("%d",&last);
			continue;
		}
		scanf("%d",&last);
		for (int j=1; j<k; ++j) {
			scanf("%d",&x);
			int a=find(x),b=find(last);
			if (a!=b) fa[a]=fa[b];
			last=x;
		}
	};
	for (int i=1;i<=n;++i) find(i);
	for (int i=1; i<=n; ++i) {
		++ans[fa[i]];
	}
	for (int i=1; i<=n; ++i) ans[i]=max(ans[fa[i]],ans[fa[fa[i]]]);
	for (int i=1; i<=n; ++i) {
		printf("%d ",ans[i]);
	}
	return 0;
}