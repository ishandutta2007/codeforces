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

const int N = 1e6+11;const double eps=1e-6;
int n,k;
/*struct dot{
	double x,y;
	dot(double X=0,double Y=0){x=X;y=Y;}
}s[N];*/vector<double>h[N];
//double Cross(dot a, dot b){return a.x*b.y-a.y*b.x;}
Pii a[N];
int sgn(int x){return x>0?1:(x<0?-1:0);}
inline ll Cross(Pii a, Pii b){return 1ll*a.fi*b.se-1ll*a.se*b.fi;}
inline ll Dot(Pii a, Pii b){return 1ll*a.fi*b.fi+1ll*a.se*b.se;}
inline ll getlen(Pii a){return 1ll*a.fi*a.fi+1ll*a.se*a.se;}
bool cmp(const Pii &a, const Pii &b){
	//if(sgn(a.se)*sgn(b.se)<0)return a.se>b.se;
	//if(a.se==0&&b.se==0&&sgn(a.fi)*sgn(b.fi)<0)return a.fi>b.fi;
	if(a.se==0&&a.fi>0&&b.se==0&&b.fi>0)return getlen(a)<getlen(b);
	if(a.se==0&&a.fi>0)return 1;
	if(b.se==0&&b.fi>0)return 0;
	if(sgn(a.se)!=sgn(b.se))return a.se>b.se;
	return Cross(a,b)!=0?Cross(a,b)>0:getlen(a)<getlen(b);
	/*double A=atan2(a.se,a.fi),B=atan2(b.se,b.fi);
	if(A>B+eps||B>A+eps)return A<B;
	return Cross(a,b)!=0?Cross(a,b)>0:getlen(a)<getlen(b);*/
}
priority_queue<Pii,vector<Pii>,greater<Pii> >heap;

inline vector<double>merge(vector<double>a,vector<double>b){
	vector<double>res={0};int A=1,B=1;
	res.reserve(SZ(a)+SZ(b)-1);
	while(A<SZ(a)||B<SZ(b)){
		if(B>=SZ(b)||A<SZ(a)&&a[A]-a[A-1]>b[B]-b[B-1])
			res.pb(res.back()+a[A]-a[A-1]),A++;
		else
			res.pb(res.back()+b[B]-b[B-1]),B++;
	}
	return res;
}
int main() {
	read(n);read(k);int sz=0;
	rep(i,1,n){
	//	int x,y;
	//	read(x),read(y);s[i]=dot(x,y);
		read(a[i].fi),read(a[i].se);
		if(a[i].fi||a[i].se)a[++sz]=a[i];
	}
	assert(sz==n-1);
	n=sz;int gs=k;
	sort(a+1,a+n+1,cmp);
	rep(l,1,n){
		int r=l;while(r+1<=n&&Cross(a[l],a[r+1])==0&&Dot(a[l],a[r+1])>0)r++;
		double cur=0;h[l].pb(cur);
		static double cost[N],qz[N];
		rep(k,1,r-l+1)cost[k]=sqrt(getlen(a[r-k+1])),qz[k]=qz[k-1]+cost[k];
	//	printf("qaq %d %d(%d)\n",a[l].fi,a[l].se,r-l+1);
		int lo=1,hi=r-l+1;
		rep(k,1,r-l+1){
			if(gs-2*k+1>0)cur+=cost[lo++]*(gs-2*k+1);
			else{
				cur+=cost[hi]*(gs-2*lo+1)-2*(qz[r-l+1]-qz[hi]);
				hi--;
			}
			h[l].pb(cur);
		//	printf("%d:%.2lf\n",k,cur);
		}
		heap.push(mp(SZ(h[l]),l));
		l=r;
	}
	while(SZ(heap)>=2){
		int a=heap.top().se;heap.pop();
		int b=heap.top().se;heap.pop();
		h[a]=merge(h[a],h[b]);
		heap.push(mp(SZ(h[a]),a));
	}
	auto q=h[heap.top().se];
//	assert(gs<SZ(q));
	double res=max(gs<SZ(q)?q[gs]:0,q[gs-1]);
	printf("%.10lf\n",res);
	return 0;
}