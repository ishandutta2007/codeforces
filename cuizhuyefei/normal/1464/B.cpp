#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
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
template<class T> inline T Abs(const T &x){return x>0?x:-x;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e6+11;
char s[N];int n,x,y,a[N];
ll res,cur;int cnt,qz[N][2],hz[N][2];
ll calc(ll x){return x*(x-1)/2;}
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	read(x);read(y);
	if(x>y){
		swap(x,y);
		rep(i,1,n)if(s[i]=='0')s[i]++;else if(s[i]=='1')s[i]--;
	}
	rep(i,1,n)qz[i][0]=qz[i-1][0]+(s[i]=='0'),qz[i][1]=qz[i-1][1]+(s[i]=='1');
	per(i,n,1)hz[i][0]=hz[i+1][0]+(s[i]=='0'),hz[i][1]=hz[i+1][1]+(s[i]=='1');
	rep(i,1,n)if(s[i]=='?')a[++cnt]=i;
	rep(i,1,n)if(s[i]!='1')cur+=qz[i][1];
	int one=qz[n][1];
	res=cur*y+(calc(n)-cur-calc(one)-calc(n-one))*x;
	per(i,cnt,1)
		cur+=hz[a[i]][0]-qz[a[i]][1],
		one++,
		umin(res,cur*y+(calc(n)-cur-calc(one)-calc(n-one))*x);
	cout<<res;
	return 0;
}