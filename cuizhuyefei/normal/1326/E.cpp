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
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 366666;
int n,p[N],q[N],ans[N],pos[N],val[N<<2],lzy[N<<2];
void pushdown(int k){
	if(lzy[k]){
		lzy[k<<1]+=lzy[k];val[k<<1]+=lzy[k];
		lzy[k<<1|1]+=lzy[k];val[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
void mdy(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){val[k]+=x;lzy[k]+=x;return;}
	int mid=(L+R)/2;pushdown(k);
	if(r<=mid)mdy(k<<1,l,r,x,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,x,mid+1,R);
	else mdy(k<<1,l,mid,x,L,mid),mdy(k<<1|1,mid+1,r,x,mid+1,R);
	val[k]=min(val[k<<1],val[k<<1|1]);
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;rep(i,1,n)cin>>p[i],pos[p[i]]=i;rep(i,1,n)cin>>q[i];
	
	int curans=n+1;
	rep(i,1,n){
		while(val[1]>=0)curans--,mdy(1,1,pos[curans],-1,1,n);
		printf("%d ",curans);
		mdy(1,1,q[i],1,1,n);
	}
	return 0;
}