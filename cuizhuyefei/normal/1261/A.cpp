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
const int N = 666666;
char a[N],b[N];int n,k;vector<Pii>ans;
int main() {
	int T;read(T);while(T--){
		read(n);read(k);ans.clear();k--;
		scanf("%s",a+1);
		rep(i,1,k)b[2*i-1]='(',b[2*i]=')';
		rep(i,2*k+1,n)b[i]=i-2*k<=(n-2*k)/2?'(':')';
		rep(i,1,n)if(a[i]!=b[i]){
			int j=i;while(a[j]!=b[i])j++;
			ans.pb(Pii(i,j));reverse(a+i,a+j+1);
		}
		printf("%d\n",SZ(ans));
		rep(i,0,SZ(ans)-1)printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}