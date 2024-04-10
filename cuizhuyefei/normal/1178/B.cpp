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
const int N = 2333333;
int n,qz[N],hz[N];char s[N];ll res;
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,2,n)qz[i]=qz[i-1]+(s[i]=='v'&&s[i-1]=='v');
	per(i,n-1,1)hz[i]=hz[i+1]+(s[i]=='v'&&s[i+1]=='v');
	rep(i,1,n)if(s[i]=='o')res+=1LL*qz[i]*hz[i];
	cout<<res;
	return 0;
}