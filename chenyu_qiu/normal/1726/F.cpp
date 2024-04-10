#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
using namespace std;
const int N=1e6,inf=1e18,mod=998244353,inv2=(mod+1)/2;
int n,t,tt;
struct sgt {
	struct node{
		signed ls,rs;
		int cov,mx;
	}t[10000005];
	int ADD,nid;
	void add(int x) {
		ADD+=x;
	}
	void give(int now,int x) {
		t[now].cov=t[now].mx=x;
	}
	void pd(int now) {
		if(t[now].cov!=-1) {
			give(t[now].ls,t[now].cov);
			give(t[now].rs,t[now].cov);
			t[now].cov=-1;
		}
	}
	void build(int now,int l,int r) {
		t[++nid]={0,0,-1,r};
	//	for(int i=l;i<=r;i++) a[i]=i;
	}
	int ask(int now,int p,int L,int R) {
	//	cout << now << " " << t[now].mx << "&&\n";
		if(L==R) return t[now].mx+ADD;
		if(!t[now].ls) t[now].ls=++nid,t[nid]={0,0,-1,(L+R)/2};
		if(!t[now].rs) t[now].rs=++nid,t[nid]={0,0,-1,R};
		pd(now);
		int mid=(L+R)/2;
		if(p<=mid) return ask(t[now].ls,p,L,mid);
		return ask(t[now].rs,p,mid+1,R);
	}
	void cov(int now,int L,int R,int l,int r,int x) {
	//	cout << l << " " << r << "?\n";
		if(L==l&&R==r) {
			give(now,x-ADD);
			return ;
		}
		if(!t[now].ls) t[now].ls=++nid,t[nid]={0,0,-1,(L+R)/2};
		if(!t[now].rs) t[now].rs=++nid,t[nid]={0,0,-1,R};
		pd(now);
		int mid=(L+R)/2;
		if(r<=mid) cov(t[now].ls,L,mid,l,r,x);
		else if(mid+1<=l) cov(t[now].rs,mid+1,R,l,r,x);
		else cov(t[now].ls,L,mid,l,mid,x),cov(t[now].rs,mid+1,R,mid+1,r,x);
		t[now].mx=max(t[t[now].ls].mx,t[t[now].rs].mx);
	}
/*	int ask(int p) {
		return a[p];
	}*/
	int MN(int now,int L,int R) {
		int rtn=inf,mid=(L+R)/2;
		if(t[now].ls) pd(now);
		if(t[now].ls) rtn=min(rtn,MN(t[now].ls,L,mid));
		if(t[now].rs) rtn=min(rtn,MN(t[now].rs,mid+1,R));
		return min(rtn,t[now].mx-R+ADD);
	}
/*	void cov(int l,int r,int x) {
		for(int i=l;i<=r;i++) a[i]=x;
	}*/
	int lwb(int now,int L,int R,int x) {
		if(L==R) {
			if(t[now].mx+ADD>=x) return L;
			return R+1;
		}
		if(!t[now].ls) t[now].ls=++nid,t[nid]={0,0,-1,(L+R)/2};
		if(!t[now].rs) t[now].rs=++nid,t[nid]={0,0,-1,R};
		pd(now);
		int mid=(L+R)/2;
		if(t[t[now].ls].mx+ADD>=x) return lwb(t[now].ls,L,mid,x);
		return lwb(t[now].rs,mid+1,R,x);
	}
/*	int lwb(int x) {
		for(int i=0;i<t;i++) if(a[i]>=x) return i;
		return t;
	}*/
}T;
void Change(int l,int r) {
	if(l>r) return ;
	int L=T.lwb(1,0,t-1,l),R=T.lwb(1,0,t-1,r+1)-1;
//	cout << l << " " << L << "??" << R << "\n";
	if(L<=R) T.cov(1,0,t-1,L,R,r+1);
}
int a[N],b[N],d[N];
void solve(){
	cin >> n >> t;
	tt=t;
	T.build(1,0,t-1);
	for(int i=1;i<=n;i++) cin >> a[i] >> b[i];
	for(int i=1;i<n;i++) cin >> d[i];
	for(int i=1;i<=n;i++) {
		int g=a[i],c=b[i];
		int P=T.ask(1,0,0,t-1);
		int l1=P/t*t+g-c,r1=P/t*t+t-1-c;
		int l2=l1-t,r2=r1-t;
		int l3=l1+t,r3=r1+t;
		int l4=l2-t,r4=r2-t;
		int l5=l3+t,r5=r3+t;
	/*	l1=max(l1,P),r1=min(r1,P+t);
		l2=max(l2,P),r2=min(r2,P+t);
		l3=max(l3,P),r3=min(r3,P+t);
		l4=max(l4,P),r3=min(r4,P+t);
		l5=max(l5,P),r3=min(r5,P+t);*/
		Change(l1,r1);
		Change(l2,r2);
		Change(l3,r3);
		Change(l4,r4);
		Change(l5,r5);
		T.add(d[i]);
//		for(int j=0;j<t;j++) cout << T.ask(1,j,0,t-1) << " ";
//		cout << "\n";
	}
	cout << T.MN(1,0,t-1) << "\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
//	cin >> T;
	while(T--){
		solve();
	//	Clear();
	}
	return 0;
}