#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge {
	int to,next;
} g[500];
int n,m,x,y,num;
int cnt,head[30],deg[30];
double p[30],f[500][500];
void add(int u,int v) {
	g[++cnt]=(edge) {
		v,head[u]
	};
	head[u]=cnt;
}
int fun(int a,int b) {
	return (a-1)*n+b;
}
void build() {
	for(int a=1; a<=n; a++)
		for(int b=1; b<=n; b++) {
			int u=fun(a,b);
			f[u][u]=-1;
			if(a!=b)f[u][u]+=p[a]*p[b];
			for(int i=head[a]; i; i=g[i].next)
				for(int j=head[b]; j; j=g[j].next) {
					int c=g[i].to,d=g[j].to;
					if(c==d)continue;
					int v=fun(c,d);
					f[u][v]=(1-p[c])/deg[c]*(1-p[d])/deg[d];
				}
			for(int i=head[a]; i; i=g[i].next) {
				int c=g[i].to;
				if(c==b)continue;
				int v=fun(c,b);
				f[u][v]=(1-p[c])/deg[c]*p[b];
			}
			for(int j=head[b]; j; j=g[j].next) {
				int d=g[j].to;
				if(a==d)continue;
				int v=fun(a,d);
				f[u][v]=p[a]*(1-p[d])/deg[d];
			}
		}
	f[fun(x,y)][num+1]=-1;
//	for(int i=1; i<=num; ++i) {
//		for(int j=1; j<=num+1; ++j) {
//			printf("%.2lf ", f[i][j]);
//		}
//		putchar('\n');
//	}
}
void gauss() {
	for(int i=1; i<=num; i++) {
		int pos=i;
		for(int j=i+1; j<=num; j++)
			if(fabs(f[j][i])>fabs(f[pos][i]))
				pos=j;
		swap(f[i],f[pos]);
		for(int j=1; j<=num; j++) {
			if(i==j)continue;
			double div=f[j][i]/f[i][i];
			for(int k=i; k<=num+1; k++)
				f[j][k]-=f[i][k]*div;
		}
	}
	for(int i=1; i<=num; i++)
		f[i][num+1]/=f[i][i];
}
int main() {
	scanf("%d%d%d%d",&n,&m,&x,&y);
	num=n*n;
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
		deg[u]++,deg[v]++;
	}
//	printf("%d\n", cnt);
	for(int i=1; i<=n; i++)
		scanf("%lf",&p[i]);
	build();
	gauss();
	for(int i=1; i<=n; i++)
		printf("%.10lf ",f[fun(i,i)][num+1]);
	return 0;
}