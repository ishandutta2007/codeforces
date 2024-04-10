#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1<<16|3,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
int n,a[N],b[N],m,dp[63][N],f[N],zt[N],C[66][66];bool mrk[N],mtr[66][66],e[66][66];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	rep(i,0,60){
		C[i][0]=C[i][i]=1;
		rep(j,1,i-1)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	read(n);rep(i,1,n)read(a[i]);
	int newlen=0;static int c[N];
	rep(i,1,n){
		bool ok=1;
		rep(j,1,n)if(j!=i)ok&=a[i]%a[j]!=0;
		bool exi=0;
		rep(j,1,n)if(j!=i)exi|=a[j]%a[i]==0;
		mrk[i]=ok&&exi;
		if(mrk[i])b[++m]=a[i];else c[++newlen]=a[i];
	}
	n=newlen;rep(i,1,n)a[i]=c[i];//a[1..n] b[1..m]
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	cerr<<m<<endl;
//	rep(i,1,n)printf("%d ",a[i]);puts("");
//	rep(i,1,m)printf("%d ",b[i]);puts("");
	rep(i,1,n)rep(j,1,m)mtr[i][j]=a[i]%b[j]==0,zt[i]|=mtr[i][j]<<j-1;
	rep(i,1,n)f[i]=i;
	rep(i,1,n)rep(k,i+1,n)rep(j,1,m)if(mtr[i][j]&&mtr[k][j])
		f[find(i)]=find(k);
	int all=0,res=1;
	rep(blo,1,n)if(find(blo)==blo){
		memset(dp,0,sizeof(dp));int sz=0;
		rep(i,1,n)if(find(i)==blo)add(dp[1][zt[i]],1),sz++;
		
		rep(i,1,sz-1)rep(s,0,(1<<m)-1)if(dp[i][s]){
			int need=i;
			rep(j,1,n)if(f[j]==blo&&(zt[j]&s)){
				if((zt[j]|s)==s){need--;if(need<0)add(dp[i+1][s|zt[j]],dp[i][s]);}
				else{add(dp[i+1][s|zt[j]],dp[i][s]);}
			}
		}
		int cur=0;rep(s,0,(1<<m)-1)add(cur,dp[sz][s]);
		all+=sz-1;res=1ll*res*C[all][sz-1]%mo*cur%mo;
	}
	cout<<res;
	return 0;
}