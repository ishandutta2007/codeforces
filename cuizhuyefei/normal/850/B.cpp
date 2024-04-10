#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2002000;
ll n,x,y,mx=1e6;
ll cnt1[N],cnt2[N];
ll prime[N],len,mrk[N];
void getp(int n) {
	rep(i,2,n) {
		if (!mrk[i]) prime[++len]=i;
		rep(j,1,len) {
			if (i*prime[j]>n) break;
			mrk[i*prime[j]]=prime[j];
			if (i%prime[j]==0) break;
		}
	}
}
ll S(ll *a, int l, int r) {return a[r]-a[l-1];}
ll getans(ll p) {
	ll res=0;
	for (ll l=0; p*l+1<=mx; l++) {
	//	ll a=p*l+(p*y-x)/y+p*l; while (a<1.0*(p*y-x)/y+p*l) a++; a=max(a,p*l);
		ll a=(-x+y*(p*l+p)-1)/y+1; a=max(a,p*l+1); a=min(a,p*l+p+1);
		res+=x*S(cnt1,p*l+1,a-1)+y*(S(cnt1,a,p*l+p)*(p*l+p)-S(cnt2,a,p*l+p));
	//	res+=x*S(cnt1,p*l,a-1)+y*(S(cnt1,a,p*l+p-1)*(p+p*l)-S(cnt2,a,p*l+p-1));
	//	printf("%lld : %lld\n",a,res);
	}
	return res;
}
int main() {
	read(n); read(x); read(y); mx=10;
	rep(i,1,n) {ll a; read(a); mx=max(mx,a); cnt1[a]++; cnt2[a]+=a;}
	rep(i,1,mx*2) cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
	getp(mx); ll ans=x*n; rep(i,1,len) ans=min(ans,getans(prime[i]));
//	cout<<getans(17)<<endl;
	cout<<ans;
	return 0;
}