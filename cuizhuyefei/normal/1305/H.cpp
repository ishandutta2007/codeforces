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
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 266666;
int n,m,l[N],r[N],xz[N];ll lim[N];int a[N],b[N];
void GG(){puts("-1 -1");exit(0);}
void solve1(ll t){
	static int a[N];
	ll mn=0,mx=0;rep(i,1,n)mn+=l[i],mx+=r[i];
	if(mn>t||mx<t)GG();
	int lo=0,hi=m;
	while(lo<hi){
		int mid=(lo+hi+1)>>1;ll cur=0;
		rep(i,1,n)cur+=min(r[i],max(l[i],mid));
		if(cur<=t)lo=mid;else hi=mid-1;
	}
	ll cur=0;
	rep(i,1,n)a[i]=min(r[i],max(l[i],lo)),cur+=a[i];
	assert(t>=cur);t-=cur;
	rep(i,1,n)if(t&&a[i]==lo&&a[i]<r[i])a[i]++,t--;
	assert(!t);
	rep(i,1,n)lim[1]++,lim[a[i]+1]--;
	rep(i,1,m)lim[i]+=lim[i-1];
	rep(i,1,m)lim[i]+=lim[i-1];
}
bool sam(int l, int r){rep(i,l,r)if(a[i]!=a[l])return 0;return 1;}
bool ck(int *a){
	ll cur=0;
	rep(i,1,m){cur+=a[i];if(cur>lim[i])return 0;}
	return 1;
}
bool ckans(int p, int x){//a[1..p]=x,-->b[](if.)
	rep(i,1,m)b[i]=a[i];ll need=0;
	rep(i,1,p)need+=x-b[i],b[i]=x;
	rep(i,p+1,m)if((i==p+1||xz[i-1]>=0)&&need&&xz[i]<0){
		int mx=0,mn=m+1,r=i;
		while(r+1<=m&&xz[r+1]==-1)r++;
		rep(j,i,r)umax(mx,b[j]),umin(mn,b[j]);
		ll have=0;rep(j,i,r)have+=b[j]-mn;
	//	if(mx>mn){
			//1
			if(need>=have){
				need-=have;rep(j,i,r)b[j]=mn;
			}
			else{
				int R=i;while(R+1<=r&&b[R+1]==b[i])R++;
				rep(j,i,R)b[j]-=need/(R-i+1);
				rep(j,i,R)if(need%(R-i+1)>=R-j+1)b[j]--;
				need=0;
			}
			//2
			have=1ll*(r-i+1)*(b[i]-xz[r+1]);
			if(need>=have){need-=have;rep(j,i,r)b[j]=xz[r+1];}
			else{
				rep(j,i,r)b[j]-=need/(r-i+1);
				rep(j,i,r)if(need%(r-i+1)>=r-j+1)b[j]--;
				need=0;
			}
	//	}
	}
	if(need)return 0;
	return ck(b);
}
int main() {
	memset(xz,-1,sizeof(xz));
	read(n);read(m);
	rep(i,1,n)read(l[i]),read(r[i]);
	int q;read(q);
	while(q--){int x,y;read(x);read(y);xz[x]=y;}
	xz[0]=n+1;xz[m+1]=0;
	ll t;read(t);solve1(t);
	per(i,m,1){
		a[i]=a[i+1];if(xz[i]>=0)a[i]=xz[i];
	}
	Vi dd;rep(i,0,m+1)if(xz[i]>=0)dd.pb(i);
	ll cur=0;rep(i,1,m)cur+=a[i];if(cur>t)GG();
	ll need=t-cur;
	per(i,SZ(dd)-2,0)if(need){
		int x=dd[i],y=dd[i+1];
		ll have=1ll*(y-x-1)*(xz[x]-xz[y]);
		if(need>=have){rep(j,x+1,y-1)a[j]=xz[x];need-=have;}
		else if(have){
			rep(j,x+1,y-1)a[j]+=need/(y-x-1)+(need%(y-x-1)>=j-x);//!!!
			need=0;
		}
	}
	if(need)GG();
	if(!ck(a))GG();
	if(sam(1,dd[1])){
		int l=dd[1],r=dd[1];
		while(r+1<=m&&!(xz[r+1]>=0&&xz[r+1]!=xz[l]))r++;
		per(i,r,l)if(xz[i]==xz[dd[1]]){l=i;break;}
		while(l<r){
			int mid=(l+r+1)>>1;
			if(ckans(mid,xz[dd[1]]))l=mid;else r=mid-1;
		}
		printf("%d %d",l,xz[dd[1]]);
		return 0;
	}
	int l=1,r=dd[1]-1;
	while(l+1<=r&&a[l+1]==a[1])l++;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(ckans(mid,a[1]))l=mid;else r=mid-1;
	}
	assert(ckans(l,a[1]));rep(i,1,m)a[i]=b[i];
	int lo=a[1],hi=n;
	while(lo<hi){
		int mid=(lo+hi+1)>>1;
		if(ckans(l,mid))lo=mid;else hi=mid-1;
	}
	printf("%d %d",l,lo);
	return 0;
}