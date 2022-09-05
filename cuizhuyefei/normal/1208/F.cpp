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
const int N = 1<<21|3;
int n,a[N],res,cnt[N];
void dfs(int dep, int s){
	if(cnt[s]>=2)return;
	if(dep<0){cnt[s]++;return;}
	dfs(dep-1,s);if(s>>dep&1)dfs(dep-1,s^(1<<dep));
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	per(i,n,1){
		if(n-i+1>=3){
			int cur=a[i],s=0;
			per(j,20,0)if(!(a[i]>>j&1))
				if(cnt[s|(1<<j)]>=2)cur|=1<<j,s|=1<<j;
			umax(res,cur);
		}
		dfs(20,a[i]);
	}
	cout<<res;
	return 0;
}