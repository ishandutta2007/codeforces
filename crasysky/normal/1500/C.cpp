#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=2e3+3;
int a[N][N],b[N][N],d[N],p[N],q[N],col[N],z,tmp[N]; queue<int> Q; bool del[N];
bool cmpa(int i,int j){
	int x=a[q[i]][col[z]],y=a[q[j]][col[z]]; return x<y||x==y&&i<j;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%d",&a[i][j]);
	rep(i,1,n) rep(j,1,m) scanf("%d",&b[i][j]);
	rep(j,1,m) rep(i,2,n) if (b[i-1][j]>b[i][j]) ++d[j];
	rep(j,1,m) if (!d[j]) Q.push(j);
	int k=0;
	while (!Q.empty()){
		int u=Q.front(); Q.pop(); col[++k]=u;
		rep(i,2,n)
			if (b[i-1][u]<b[i][u]&&!del[i]){
				del[i]=true;
				rep(j,1,m)
					if (b[i-1][j]>b[i][j]){
						--d[j]; if (d[j]==0) Q.push(j);
					}
			}
	}
	rep(i,1,n) q[i]=i;
	for (z=k;z>=1;--z){
		rep(i,1,n) p[i]=i; sort(p+1,p+1+n,cmpa);
		rep(i,1,n) tmp[i]=q[i]; rep(i,1,n) q[i]=tmp[p[i]];
	}
	bool f=false;
	rep(i,1,n) rep(j,1,m) if (a[q[i]][j]!=b[i][j]) f=true;
	if (f){ puts("-1"); return 0; }
	printf("%d\n",m); per(i,m,1) printf("%d ",col[i]);
 	return 0;
}