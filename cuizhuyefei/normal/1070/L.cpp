#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
bitset<2020>a[2020];
int n,m,deg[2020];
int main() {
	int T;read(T);while(T--){
		read(n);read(m);
		rep(i,0,n){deg[i]=0;rep(j,0,n)a[i][j]=0;}
		rep(i,1,m){
			int u,v;read(u);read(v);
			a[u][v]=a[v][u]=1;deg[u]^=1;deg[v]^=1;
		}
		bool bo=1;rep(i,1,n)bo&=!deg[i];
		if(bo){puts("1");rep(i,1,n)printf("%d ",1);puts("");continue;}
		rep(i,1,n)if(deg[i]&1)a[i][0]=1,a[i][i]=1;
		rep(i,1,n){
			if(!a[i][i])rep(j,i+1,n)if(a[j][i]){swap(a[i],a[j]);break;}
			rep(j,1,n)if(a[j][i]&&j!=i)a[j]^=a[i];
		}
		puts("2");rep(i,1,n)printf("%d ",1+(a[i][0]==1));puts("");
	}
	return 0;
}