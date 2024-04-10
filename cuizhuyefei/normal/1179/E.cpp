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
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 66666;
const ll inf=1e18;
int n;ll l,ans1[N],ans2[N],piece;
struct node{
	int idx;ll l,r;
};
map<ll,ll>Map[N];
ll query(int i, ll x){
	if(Map[i].count(x))return Map[i][x];
	printf("? %d %lld\n",i,x);fflush(stdout);
	ll y;read(y);return Map[i][x]=y;
}
/*ll find(int i, ll val, ll l, ll r){
	while(l<=r){
		ll mid=(l+r)>>1,x=query(i,mid);
		if(x==val)return mid;
		if(x>val)r=mid-1;else l=mid+1;
	}
	assert(0);
}*/
ll find(int i, ll val, ll l, ll r){
	while(l<r){
		ll mid=(l+r)>>1,x=query(i,mid);
		if(x<val)l=mid+1;else r=mid;
	}
	return l;
}
void solve(vector<node>a, ll l, ll r){
	assert(l<=r);
	if(SZ(a)==1){ans1[a.back().idx]=l;ans2[a.back().idx]=r;return;}
	vector<node>zuo,you;int mid=SZ(a)/2,tot=SZ(a);
	#define Get(u) (a[u].l+(a[u].r-a[u].l)/tot*mid)
//	rep(i,0,SZ(a)-1)cerr<<a[i].idx<<' '<<find(a[i].idx,Get(i),l,r)<<endl;
	ll MID=l;
	while(SZ(a)){
		int u=R()%SZ(a);ll p=find(a[u].idx,Get(u),l,r);MID=p;
		vector<node>x,y,z;int rec=SZ(zuo);
		rep(i,0,SZ(a)-1)if(i!=u){
			if(Get(i)<=query(a[i].idx,p)){
				if(query(a[i].idx,p-1)<Get(i))y.pb(a[i]);
				else x.pb(a[i]);
			}
			else z.pb(a[i]);
		}
		else y.pb(a[i]);
		int s1=SZ(x),s2=SZ(y),s3=SZ(z);
		if(rec+s1<=mid)zuo.insert(zuo.end(),x.begin(),x.end()),x.clear();
		if(rec>=mid)you.insert(you.end(),x.begin(),x.end()),x.clear();
		rep(i,0,SZ(y)-1)
			if(rec+s1+i+1<=mid)zuo.pb(y[i]);else you.pb(y[i]);
		if(rec+s1+s2+s3<=mid)zuo.insert(zuo.end(),z.begin(),z.end()),z.clear();
		if(rec+s1+s2>=mid)you.insert(you.end(),z.begin(),z.end()),z.clear();
		a=x;a.insert(a.end(),z.begin(),z.end());
	}
	assert(SZ(zuo)==mid);
	rep(i,0,SZ(zuo)-1)zuo[i].r=query(zuo[i].idx,MID);
	rep(i,0,SZ(you)-1)you[i].l=query(you[i].idx,MID);
	solve(zuo,l,MID);solve(you,MID,r);
}
int main() {
	read(n);read(l);piece=l/n;
	vector<node>a;
	rep(i,1,n)a.pb((node){i,0,l});
	solve(a,0,inf);
	puts("!");
	rep(i,1,n)printf("%lld %lld\n",ans1[i],ans2[i]);
	fflush(stdout);
	return 0;
}