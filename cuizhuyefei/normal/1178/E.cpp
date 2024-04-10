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
const int N = 1666666;
bool c[N];char s[N];int n;
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	int l=1,r=n;
	while(r-l+1>=4){
		bool fd=0;
		rep(i,1,2)rep(j,1,2)if(!fd&&s[l+i-1]==s[r-j+1]){
			fd=1;
			c[l+i-1]=c[r-j+1]=1;
			l+=2;r-=2;
		}
	}
	if(r-l+1>=1)c[l]=1;
	rep(i,1,n)if(c[i])putchar(s[i]);
	return 0;
}