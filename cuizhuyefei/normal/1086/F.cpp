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
const int N = 55*55, mo = 998244353,inv2=(mo+1)/2,inv6=(mo+1)/6;
int n,t,x[N],y[N],s[N],len,now;
inline int Abs(int x){return x>0?x:-x;}
//Pii(fi,se) --> fi*now+se
bool operator<(const Pii &a,const Pii &b){
	return a.fi*now+a.se<b.fi*now+b.se;
}
Pii operator-(const Pii &a,const Pii &b){
	return Pii((a.fi-b.fi+mo)%mo,(a.se-b.se+mo)%mo);
}
Pii operator+(const Pii &a,const Pii &b){
	return Pii((a.fi+b.fi)%mo,(a.se+b.se)%mo);
}
inline void add(int &x,int y){x=(x+y)%mo;}
struct Line{
	Pii l,r,p;int kd;
}a[N];int tot;
bool cmp(const Line &a,const Line &b){return a.p<b.p;}
struct Seg{
	Pii l,r;
}seg[N];int seglen;
bool operator==(const Pii &a,const Pii &b){return a.fi==b.fi&&a.se==b.se;}
bool operator==(const Seg &a,const Seg &b){return a.l==b.l&&a.r==b.r;}
bool cmp1(const Seg &a,const Seg &b){return a.l<b.l;}
inline Pii getlen(){//seg[1..seglen]
	sort(seg+1,seg+seglen+1,cmp1);
	static Seg a[N];int len=0;
	rep(i,1,seglen)
		if(!len||a[len].r<seg[i].l)a[++len]=seg[i];
		else if(a[len].r<seg[i].r)a[len].r=seg[i].r;
	Pii res(0,0);rep(i,1,len)res=res+a[i].r-a[i].l+Pii(0,1);
	return res;
}
inline void solve(int poly[3]){
	tot=0;
	rep(i,1,n){
		Line tmp;tmp.p=Pii(-1,x[i]);tmp.l=Pii(-1,y[i]);tmp.r=Pii(1,y[i]);
		tmp.kd=1;a[++tot]=tmp;
		tmp.kd=-1;tmp.p=Pii(1,x[i]+1);a[++tot]=tmp;
	}
	sort(a+1,a+tot+1,cmp);seglen=0;
	rep(i,1,tot){
		Pii x=getlen(),y=a[i].p-a[i-1].p;
	//	printf("<%d %d> <%d %d>\n",x.fi,x.se,y.fi,y.se);
		add(poly[0],1LL*x.se*y.se%mo);
		add(poly[1],(1LL*x.se*y.fi+1LL*x.fi*y.se)%mo);
		add(poly[2],1LL*x.fi*y.fi%mo);
		if(a[i].kd==1)seg[++seglen]=(Seg){a[i].l,a[i].r};
		else rep(j,1,seglen)if(seg[j]==(Seg){a[i].l,a[i].r}){
			rep(k,j,seglen-1)seg[k]=seg[k+1];seglen--;
			break;
		}
	}
}
int main() {
	read(n);read(t);rep(i,1,n)read(x[i]),read(y[i]);
	s[++len]=0;s[++len]=t;
	rep(i,1,n)rep(j,i+1,n){
		s[++len]=(max(Abs(x[i]-x[j]),Abs(y[i]-y[j]))+1)/2;
		if(s[len]>t)len--;
	}
	sort(s+1,s+len+1);len=unique(s+1,s+len+1)-s-1;
	int res=0;
	rep(i,1,len){
		now=s[i];int poly[3]={0};solve(poly);
	//	printf("%d:%d %d %d\n",s[i],poly[0],poly[1],poly[2]);
		if(i==len)res=(res+1LL*(1LL*poly[0]+1LL*poly[1]*now+1LL*poly[2]*now%mo*now)%mo*now)%mo;
		else{
			int l=s[i],r=s[i+1]-1;
			res=(res-(1LL*poly[0]*(r-l+1)+1LL*poly[1]*(l+r)%mo*(r-l+1)%mo*inv2+1LL*poly[2]*(1LL*r*(r+1)%mo*(2*r+1)%mo-1LL*(l-1)*l%mo*(2*l-1)%mo)%mo*inv6))%mo;
		}
	}
	res=(res%mo+mo)%mo;cout<<res;
	return 0;
}