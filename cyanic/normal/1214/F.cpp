#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
struct node{
	ll p;int id;
	friend bool operator < (node x,node y){
		return x.p<y.p||x.p==y.p&&x.id<y.id;
	}
}a[N],b[N];
int cur[N],L,n,pos;
ll ans=1e18,A,B;
vector<ll> f[N],g[N];

int main(){
	read(L),read(n);
	rep(i,1,n){
		read(a[i].p);
		a[i].id=i;
	}
	rep(i,1,n){
		read(b[i].p);
		b[i].id=i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	rep(i,1,2*n){
		a[i+n]=a[i];
		a[i+n].p+=L;
	}
	rep(i,1,n){
		b[i].p+=L;
		int p=lower_bound(a+1,a+3*n+1,(node){b[i].p,0})-a;
		p=p-i+1;
		f[p].pb(-2*b[i].p);
	}
	rep(i,1,3*n){
		if(a[i].p<b[1].p){
			g[max(1,i-n+1)].pb(-a[i].p);
			g[i+1].pb(a[i].p);
		}
		else if(a[i].p<b[n].p){
			g[max(1,i-n+1)].pb(-a[i].p);
			int p=lower_bound(b+1,b+n+1,(node){a[i].p+1,0})-b-1;
			p=i-p+1;
			g[p].pb(2*a[i].p);
			g[i+1].pb(-a[i].p);
		}
		else{
			g[max(1,i-n+1)].pb(a[i].p);
			g[i+1].pb(-a[i].p);
		}
	}
	rep(i,1,n)B+=b[i].p;
	rep(i,1,2*n+1){
		for(auto x:f[i])B+=x;
		for(auto x:g[i])A+=x;
		//cerr<<i<<" "<<A<<" "<<B<<endl;
		ll now=A+B;
		if(now<ans){
			ans=now;
			pos=i;
		}
	}
	printf("%lld\n",ans);
	rep(i,1,n)
		cur[a[i+pos-1].id]=b[i].id;
	rep(i,1,n)printf("%d ",cur[i]);
	puts("");
	return 0;
}