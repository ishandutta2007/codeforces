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
char s[N];int n;ll res;
bool bx(int l, int r){
	for(int i=r-2;i>=l;i-=2)if(s[i]==s[r]&&s[r]==s[i+r>>1])return 0;
	return 1;
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);res=1ll*n*(n+1)/2;
	for(int l=1,r=1;l<=n;l++){
		umax(r,l);
		while(r<n&&bx(l,r+1))r++;
		res-=r-l+1;
	}
	cout<<res;
	return 0;
}