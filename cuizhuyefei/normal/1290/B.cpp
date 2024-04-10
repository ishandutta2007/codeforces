#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333;
char s[N];int n,q,qz[28][N];
int main() {
	scanf("%s",s+1);n=strlen(s+1);read(q);
	rep(c,0,25)rep(i,1,n){
		qz[c][i]=qz[c][i-1]+(s[i]=='a'+c);
	}
	while(q--){
		int l,r;read(l);read(r);int ss=0;
		rep(c,0,25)ss+=qz[c][r]-qz[c][l-1]>0;
		bool ok=0;
		if(ss>=3){ok=1;}
		else if(ss==1){ok=r-l+1==1;}
		else ok=s[l]!=s[r];
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}