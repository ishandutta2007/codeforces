#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 10505;
int n,a[N];ll f[105][10505],g[105][10505],cnt[105];
void add(ll &x, ll y, ll mo){x=x+y<mo?x+y:x+y-mo;}
void init(ll f[105][10505], ll mo){
	f[0][0]=1;
//	rep(i,1,n)per(j,i,1)per(k,10000,a[i])
//		{f[j][k]=(f[j][k]+f[j-1][k-a[i]]);f[j][k]=f[j][k]<mo?f[j][k]:f[j][k]-mo;}
	rep(l,1,n){
		int r;for(r=l;r<=n;r++)if(a[l]!=a[r])break;
		//[l,r-1]
		int mx=0;rep(i,1,r-1)mx+=a[i];
		per(j,r-1,0)per(k,mx,0)for(int c=1;c<=r-l&&j-c>=0&&k-c*a[l]>=0;c++)
			add(f[j][k],f[j-c][k-c*a[l]],mo);
		l=r-1;
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i]);sort(a+1,a+n+1);
	init(f,1e9+7);init(g,1e9+9);rep(i,1,n)cnt[a[i]]++;
	int res=0;
//	rep(i,1,3)rep(j,1,100)if(f[i][j])printf("%d %d:%d\n",i,j,f[i][j]);
//	rep(i,1,n)rep(j,1,cnt[i])printf("%d %d:%d %d\n",i,j,f[j][i*j],g[j][i*j]);
	int x=0;rep(i,1,100)x+=cnt[i]>0;
	rep(i,1,100)rep(j,1,cnt[i])if(f[j][i*j]==1&&g[j][i*j]==1){
		res=max(res,j);if(x==2&&j==cnt[i])res=n;
	}
	printf("%d\n",res);
	return 0;
}