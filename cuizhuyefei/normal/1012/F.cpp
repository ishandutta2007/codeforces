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
const int N = 66,inf=2.05e9;
int n,tp,t[N],bg[N],f[1<<22|3],rec[1<<22|3];Pii ans[N];
struct seg{
	int l,r,t,idx;
}a[N];
void GG(){puts("NO");exit(0);}
void recover(int s, int kd){
	while(s){
		ans[rec[s]]=mp(kd,f[s]-t[rec[s]]);s^=1<<rec[s]-1;
	}
}
int main() {
	read(n);read(tp);
	rep(i,1,n)read(a[i].l),read(a[i].r),a[i].r+=a[i].l-1,a[i].idx=i,read(a[i].t),t[i]=a[i].t,bg[i]=a[i].l;
	static int id[N];rep(i,1,n)id[i]=i;
	sort(id+1,id+n+1,[](int x, int y){return t[x]<t[y];});
	sort(a+1,a+n+1,[](seg x, seg y){return x.l<y.l;});
	rep(i,1,n-1)if(a[i].r>=a[i+1].l)GG();
	int all=(1<<n)-1;
	rep(s,0,all)f[s]=inf;f[0]=1;
	rep(s,0,all-1)if(f[s]<inf){
		int x=f[s],p=1,p2=1;
		static Pii seg[N];int sz=0;
		rep(i,1,n)if(s>>a[i].idx-1&1)seg[++sz]=mp(a[i].l,a[i].r);
		rep(j,1,n)if((~s>>id[j]-1&1)){
			while(1){
				int orix=x,orip=p,orip2=p2;
				while(p<=sz&&seg[p].se<x)p++;
				if(p<=sz&&x+t[id[j]]>=seg[p].fi)x=seg[p].se+1,p++;
				while(p2<=n&&a[p2].r<x)p2++;
				if(p2<=n&&x>=a[p2].l&&x<=a[p2].r)x=a[p2].r+1;
				if(orix==x&&orip==p&&orip2==p2)break;
			}
			if(f[s|1<<id[j]-1]>x+t[id[j]]&&x+t[id[j]]<bg[id[j]])
				f[s|1<<id[j]-1]=x+t[id[j]],rec[s|1<<id[j]-1]=id[j];
		}
	//	rep(i,1,n)if(x>=a[i].l&&x<=a[i].r)x=a[i].r+1;
	//	rep(i,1,n)if((~s>>i-1&1)&&f[s|1<<i-1]>x+t[i]-1)
	//		f[s|1<<i-1]=x+t[i]-1,rec[s|1<<i-1]=i;
	}
//	cerr<<f[30]<<':'<<f[30^all]<<endl;
	if(tp==1){if(f[all]>=inf)GG();recover(all,1);}
	else{
		bool ok=0;
		rep(s,0,all)if(!ok&&f[s]<inf&&f[s^all]<inf){
			recover(s,1);recover(s^all,2);ok=1;
		}
		if(!ok)GG();
	}
	puts("YES");rep(i,1,n)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}