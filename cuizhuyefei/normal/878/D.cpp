#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a; i<=b; ++i)
using namespace std;
const int N = 110200;
int n,k,size;
int a[14][N],c[14][N];
bitset<4098> b[N<<1];
inline void read(int &x) {
	x=0; char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();}
}
int main(){
//	freopen("1.in","r",stdin);
	int q; read(n); read(k); read(q);
	rep(j,1,k) rep(i,1,n) read(a[j][i]);
	//get b,c.
	rep(i,1,k) rep(j,0,(1<<k)-1) b[i][j]=((j>>(i-1))&1); //b[i][j]:ji1>=ii<=
	//c[i][j]:>=(i,j)
	rep(i,1,k) rep(j,1,n) rep(p,1,k)
		if (a[p][j]>=a[i][j]) c[i][j]|=(1<<(p-1));
	size=k;
	while (q--) {
		int op,x,y; read(op); read(x); read(y);
		if (op==1) b[++size]=b[x]|b[y]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		else if (op==2) b[++size]=b[x]&b[y];
		else {
			int ans=0;
			rep(i,1,k) if (b[x][c[i][y]]) ans=max(ans,a[i][y]);
			printf("%d\n",ans);
		}
	}
	return 0;
}