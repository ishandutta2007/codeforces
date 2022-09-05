#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
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
int n,qz[55],QZ[55]; ll f[55][5050];
struct ele{int a,b;}s[55];
bool cmp(ele x, ele y){return x.a!=y.a?x.a>y.a:x.b>y.b;}
inline void umin(ll &x, ll y){x=x<y?x:y;}
int main() {//freopen("1.in","r",stdin);
	read(n);rep(i,1,n)read(s[i].a);rep(i,1,n)read(s[i].b);
	sort(s+1,s+n+1,cmp);rep(i,1,n)QZ[i]=QZ[i-1]+s[i].b;
	rep(i,0,n)rep(j,0,5000)f[i][j]=1e18;f[0][0]=0;
	rep(t,1,n){
		int r;for(r=t;r<=n;r++)if(s[r].a!=s[t].a)break;
		//[t,r-1]
		int len=r-t;rep(i,1,len)qz[i]=qz[i-1]+s[i+t-1].b;
		per(j,QZ[t-1],0)rep(i,0,t-1)if(f[i][j]<1e18){
			rep(k,max(0,len-i),len)umin(f[i+k-(len-k)][j+qz[k]],f[i][j]+1LL*s[t].a*k);
			f[i][j]=1e18;
		}
		t=r-1;
	}
//	rep(i,0,n)rep(j,1,QZ[i])if(f[i][j]<1e18)printf("%d %d:%lld\n",i,j,f[i][j]);
//	cerr<<ceil(9.0)<<' '<<ceil(9.001)<<endl;
//	ll res=1e18;rep(i,0,n)rep(j,1,QZ[i])res=min(res,(ll)(ceil(1000.0*(double)f[i][j]/j)));
//	cout<<res;
	double res=1e18;rep(i,0,n)rep(j,1,QZ[n])res=min(res,1.0*f[i][j]/j);
	cout<<(ll)ceil(res*1000);
	return 0;
}