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
const int N = 1<<20|3;
int n,all,f[N];ll a[26];
int getque(ll *a, int l, int r, ll *ans){
	int n=1;ans[1]=0;
	static ll f[N],g[N];
	rep(j,l,r){
		rep(i,1,n)f[i]=ans[i]+a[j];
		rep(i,1,n)g[i]=ans[i]-a[j];
		int p1=1,p2=1,sz=0;
		while(sz<n*2){
			if(p1>n||(p2<=n&&f[p1]>g[p2]))ans[++sz]=g[p2++];
			else ans[++sz]=f[p1++];
		}
		n*=2;
	}
	return n;
}
bool ck(int s){
	static ll q[26],q1[N],q2[N];int sz=0;ll sum=0;
	rep(i,1,n)if(s>>i-1&1)q[++sz]=a[i],sum+=a[i];
	if(sum+sz-1&1)return 0;
	int n1=getque(q,1,sz/2,q1);
	int n2=getque(q,sz/2+1,sz,q2);
	int tot=0-(sum<=sz-1&&sum>=-sz+1)*2;
	/*if(s==all){
		rep(i,1,n1)printf("%lld ",q1[i]);puts("");
		rep(i,1,n2)printf("%lld ",q2[i]);puts("");
	}*/
	for(int i=n2,j=1;i>=1;i--){
		while(j<=n1&&q1[j]+q2[i]<-(sz-1))j++;
		if(j<=n1&&q1[j]+q2[i]<=sz-1){
			for(int k=j;k<=n1&&tot<=0&&q1[k]+q2[i]<=sz-1;k++)tot++;
		}
	}
	return tot>0;
}
int main() {
	int newsz=0;read(n);rep(i,1,n){read(a[i]);if(a[i])a[++newsz]=a[i];}n=newsz;
	all=(1<<n)-1;
	rep(s,1,all)if(!f[s]&&ck(s)){
		int wai=s^all;f[s]=1;
		for(int t=wai;t;t=(t-1)&wai)umax(f[s|t],f[t]+1);
	}
	cout<<n-f[all];
	return 0;
}