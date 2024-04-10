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
const int N = 3030,mo=1e9+7;
int a[N],n,lcs[N][N],f[N],ans[N];
bool ck(int l, int r){
	if(r-l+1==4){
		int s=0;rep(i,l,r)s=s*2+a[i];
		if(s==3||s==5||s==14||s==15)return 0;
	}
	return 1;
}
void add(int &x, int y){x=(x+y)%mo;}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n)rep(j,1,n)lcs[i][j]=a[i]==a[j]?lcs[i-1][j-1]+1:0;
	rep(i,1,n){
		int mx=0;rep(j,1,i-1)umax(mx,lcs[i][j]);//len>=mx+1
		memset(f,0,sizeof(f));f[i+1]=1;
		per(j,i,1)rep(k,1,4)if(j+k-1<=i&&ck(j,j+k-1))add(f[j],f[j+k]);
		rep(j,1,i)if(i-j+1>=mx+1)add(ans[i],f[j]);
		add(ans[i],ans[i-1]);printf("%d\n",ans[i]);
	}
	return 0;
}