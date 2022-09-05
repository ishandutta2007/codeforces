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
const int N = 303000;
int n,a[N],vis[N],ok[N],s[N],len,res;
int main() {
	read(n);rep(i,1,n)read(a[i]);
	memset(vis,0,sizeof(vis));
	rep(i,1,n)ok[i]|=!vis[a[i]],vis[a[i]]=1;
	memset(vis,0,sizeof(vis));
	per(i,n,1)ok[i]|=!vis[a[i]],vis[a[i]]=1;
	rep(i,1,n)if(ok[i])s[++len]=i;
	rep(i,1,len-1){
		int p=len;while(a[s[i]]==a[s[p]]&&p>i)p--;
		if(a[s[i]]!=a[s[p]]&&p>i)umax(res,s[p]-s[i]);
	}
	cout<<res;
	return 0;
}