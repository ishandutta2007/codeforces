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
const int N = 52;
int n,a[N],Ans,ans[N],qz[N];
bitset<25*50000+5>f[52][26];
int main() {
	read(n);rep(i,1,n*2)read(a[i]);sort(a+1,a+n*2+1);
	rep(i,1,n*2)qz[i]=qz[i-1]+a[i];
	Ans=1e9;f[n*2+1][0][0]=1;
	per(i,n*2,3){
		f[i][0][0]=1;
		rep(j,1,min(n-1,n*2-i+1))f[i][j]=f[i+1][j]|(f[i+1][j-1]<<a[i]);
		if(i-2<=n){
			int p=0,now=1e9;
			rep(j,0,25*50000)if(f[i][n-(i-2)][j]&&max(qz[i-2]+j+a[i-1],qz[n*2]-(qz[i-2]+j)+a[1])<Ans&&max(qz[i-2]+j+a[i-1],qz[n*2]-(qz[i-2]+j)+a[1])<now){
				now=max(qz[i-2]+j+a[i-1],qz[n*2]-(qz[i-2]+j)+a[1]);p=j;
			}
			if(p){
				Ans=now;
				bool cho[N]={0};rep(j,1,i-2)cho[j]=1;
				for(int x=i,y=n-(i-2),z=p;x<=n*2;x++){
					assert(f[x][y][z]);
					if(!f[x+1][y][z])cho[x]=1,y--,z-=a[x];
				}
				int pos=0;rep(i,1,n*2)if(cho[i])ans[++pos]=a[i];
				per(i,n*2,1)if(!cho[i])ans[++pos]=a[i];
			}
		}
	}
	rep(i,1,n)printf("%d ",ans[i]);puts("");
	rep(i,n+1,n+n)printf("%d ",ans[i]);puts("");
	cerr<<Ans<<endl;
	return 0;
}