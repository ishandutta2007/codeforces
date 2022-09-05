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
const int N = 266666;
int n,a[N],b[N],ans[N];char S[N];Vi pos[12];
bool ck(){
	static int c[N];int p=0;
	rep(i,1,n)if(ans[i]==1)c[++p]=a[i];
	rep(i,1,n)if(ans[i]==2)c[++p]=a[i];
	rep(i,1,n)if(c[i]!=b[i])return 0;
	return 1;
}
int main() {
	int T;read(T);while(T--){
		read(n);scanf("%s",S+1);rep(i,0,9)pos[i].clear();
		rep(i,1,n)a[i]=S[i]-'0',b[i]=a[i];
		sort(b+1,b+n+1);
		rep(i,1,n)pos[a[i]].pb(i);rep(i,1,n)ans[i]=2;
		for(int i=pos[b[1]][0],cnt=2;cnt<=n;cnt++){
			ans[i]=1;if(i>=pos[b[cnt]].back())break;
			i=*upper_bound(pos[b[cnt]].begin(),pos[b[cnt]].end(),i);ans[i]=1;
		}
		if(ck()){
			rep(i,1,n)printf("%d",ans[i]);puts("");
		}else puts("-");
	}
	return 0;
}