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
int n,d[N],id[N],s[N];Pii ans[N];int sz;
bool cmp(int x, int y){return d[x]>d[y];}
int main() {
	read(n);rep(i,1,n)read(d[i]);
	rep(i,1,n)id[i]=i;sort(id+1,id+n+1,cmp);
	int len=n;rep(i,1,n)s[i]=id[i]*2-1;
	rep(i,1,n-1)ans[++sz]=Pii(s[i],s[i+1]);
	rep(j,1,n){
		if(j+d[id[j]]<=len)ans[++sz]=Pii(id[j]*2,s[j+d[id[j]]-1]);
		else{
			s[++len]=id[j]*2;
			ans[++sz]=Pii(s[len],s[len-1]);
		}
	}
	
	rep(i,1,sz)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}