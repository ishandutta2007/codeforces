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
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 366;
int n,tot,cur,a[N];
int qry(int l,int r, int tar, int Len){
	bool c[2]={0};int res=-1;cur=tot;
	while(1){
		printf("? %d %d\n",l,r);fflush(stdout);
		int ans;read(ans);int tp=ans+cur&1;
		c[tp]^=1;
		if(res==-1){if(c[tar]==1&&c[tar^1]==0)assert((Len-ans+tot)%2==0),res=(Len-ans+tot)/2;}//,printf("[%d %d]%d %d %d\n",l,r,Len,ans,tot);}
		else if(!c[0]&&!c[1]){cur=ans;break;}
		cur=ans;
	}
	return res;
}
int main() {
	read(n);read(tot);cur=tot;
	rep(t,1,n/2){
		//t
		int cnt=qry(t+1,n-t+1,n-t&1,n-t);
		a[t]=tot-cnt;rep(i,1,t-1)a[t]-=a[i];
		//n-t+1
		cnt=qry(t,n-t,n-t&1,n-t);
		a[n-t+1]=tot-cnt;rep(i,n-t+2,n)a[n-t+1]-=a[i];
	}
	if(n&1){a[n+1>>1]=tot;rep(i,1,n)if(i!=(n+1>>1))a[n+1>>1]-=a[i];}
	printf("! ");rep(i,1,n)printf("%d",a[i]);fflush(stdout);
	return 0;
}