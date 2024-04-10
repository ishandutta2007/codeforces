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
char s[N];int n;
int main() {
	int T;read(T);while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		bool ok=0;
		rep(i,1,n)ok|=s[i]=='0';
		int sum=0;rep(i,1,n)sum+=s[i]-'0';
		ok&=sum%3==0;
		int cnt=0;rep(i,1,n)cnt+=(s[i]-'0')%2==0;
		ok&=cnt>=2;
		printf("%s\n",ok?"red":"cyan");
	}
	return 0;
}