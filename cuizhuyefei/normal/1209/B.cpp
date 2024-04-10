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
const int N = 233;
int n,a[N],A[N],B[N],res;char S[N];
int cnt[505000],b[505000];
int main() {
	read(n);scanf("%s",S+1);
	rep(i,1,n)a[i]=S[i]-'0';
	rep(i,1,n)read(A[i]),read(B[i]);
	rep(i,1,n){
		memset(b,0,sizeof(b));b[0]=a[i];
		for(int j=B[i];j<=500000;j+=A[i])b[j]=1;
		rep(j,1,500000)b[j]^=b[j-1];
		rep(j,0,500000)cnt[j]+=b[j];
	}
	rep(j,0,500000)umax(res,cnt[j]);
	cout<<res;
	return 0;
}