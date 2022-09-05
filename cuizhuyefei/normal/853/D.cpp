#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 304040,inf=0x3f3f3f3f;
int n,a[N],f[N][40];
inline void umin(int &x, int y){x=min(x,y);}
int main() {
	read(n);rep(i,1,n)read(a[i]);memset(f,inf,sizeof(f));
	f[0][0]=0;rep(i,0,n-1)rep(j,0,35)if(f[i][j]<inf){
		umin(f[i+1][j+a[i+1]/1000],f[i][j]+a[i+1]);
		umin(f[i+1][max(0,j-a[i+1]/100)],f[i][j]+max(0,a[i+1]-100*j));
	}
	int res=inf;rep(i,0,35)res=min(res,f[n][i]);cout<<res;
	return 0;
}