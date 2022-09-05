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
const int N = 1666666,mo=1e9+7;
int x,n;char s[N];
int main() {
	int T;read(T);while(T--){
		read(x);scanf("%s",s+1);n=strlen(s+1);int ori=n;
		for(int i=1;i<=n&&n<x;i++){
			int r=n;//[i+1..r]
			for(int cnt=1;cnt<=s[i]-'0'-1;cnt++)
				for(int p=i+1;p<=r&&n<x;p++)
					s[++n]=s[p];
		}
		int l=ori;
		rep(i,1,x)l=((i+1ll*(l-i)*(s[i]-'0'))%mo+mo)%mo;
		printf("%d\n",l);
	}
	return 0;
}