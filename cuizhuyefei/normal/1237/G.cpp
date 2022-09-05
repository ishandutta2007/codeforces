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
typedef pair<ll,ll> Pll;
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
const int N = 2e5+10;
int n,k,a[N],step,pos=-1,buc[N],nxt[N],dp[N];ll ave,qz[N];Pll b[N];vector<Vi>ans;
int calc(int n){return n<=k?1:(n+k-3)/(k-1);}
void solve(int l, int r){
	rep(i,l,r)dp[i]=1,nxt[i]=n+1;
	per(i,r-1,l){
		buc[b[i+1].se%(k-1)]=i+1;
		if(buc[(b[i].se+1)%(k-1)]<n)nxt[i]=buc[(b[i].se+1)%(k-1)],dp[i]=dp[nxt[i]]+1;
	//	if(b[i+1].se%(k-1)==(b[i].se+1)%(k-1)&&b[i+1].se>b[i].se+1)nxt[i]=buc[(b[i].se+1)%(k-1)],dp[i]=dp[nxt[i]]+1;
	}
	rep(i,l,r)buc[b[i].se%(k-1)]=n+1;//WA
	int p=r;rep(i,l,r)if(dp[i]>dp[p])p=i;if(dp[p]<n%(k-1))return;
	int tot=(dp[p]-n%(k-1))/(k-1)*(k-1)+n%(k-1);
	if((n-tot)/(k-1)<step)step=(n-tot)/(k-1),pos=p;
}
void perform(int l, int r, int x, int y){
	Vi q={l%n};assert(r>l);int A=0,B=0;
	rep(i,0,k-1){
		int j=(l+i)%n;A+=a[j];
		a[j]=!i?x:(i>r-l?a[j]:(i==r-l?y:0)),q.pb(ave+a[j]);B+=a[j];
	}
//	assert(A==B);
	ans.pb(q);
}
void getans(int l, int r, int x=0, int y=0){
	if(l==r){assert(a[l%n]==(x|y));return;}
	if(r-l+1<=k){perform(l,r,x,y);return;}
	int sum=0;rep(i,l,l+k-1)sum+=a[i%n];
	if(sum>=x){
		perform(l,l+k-1,x,sum-x);getans(l+k-1,r,0,y);return;
	}
	sum=0;rep(i,l,l+k-2)sum+=a[i%n];
	getans(l+k-1,r,x-sum,y);perform(l,l+k-1,x,0);
}
int main() {
	read(n);read(k);
	rep(i,0,n-1)read(a[i]),ave+=a[i];ave/=n;
	rep(i,0,n-1)a[i]-=ave;
	step=calc(n);
	rep(i,0,n-1)qz[i]=(i-1>=0?qz[i-1]:0)+a[i];
	rep(i,0,n-1)b[i]=mp(qz[i],i);sort(b,b+n);
	rep(i,0,n)buc[i]=n+1;
	rep(l,0,n-1){
		int r=l;while(r+1<n&&b[r+1].fi==b[l].fi)r++;
		solve(l,r);l=r;
	}
	fprintf(stderr,"%d %d\n",step,pos);
	if(pos==-1)getans(0,n-1);//WA
	else{
		int p=pos;int tot=(dp[p]-n%(k-1))/(k-1)*(k-1)+n%(k-1);
		int q=p;rep(t,1,tot-1){
			assert((b[nxt[q]].se-(b[q].se+1))%(k-1)==0);
			getans(b[q].se+1,b[nxt[q]].se),q=nxt[q];
		}
	//	rep(i,0,n-1)a[n+i]=a[i],qz[n+i]=qz[i];
		getans(b[q].se+1,b[p].se+n);
	}
	printf("%d\n",SZ(ans));
	for(auto b:ans){for(auto c:b)printf("%d ",c);puts("");}
	return 0;
}