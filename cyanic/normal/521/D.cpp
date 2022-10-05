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
typedef pair<ll,int> pli;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
struct frac{
	ll a,b;	int id; // 1 + a / b;
	inline void set(ll x,ll y,int i){
		ll g=__gcd(x,y);
		a=x/g,b=y/g,id=i;
	}
	friend bool operator < (frac x,frac y){
		return x.a*y.b>x.b*y.a;
	}
}x[N];
ll fir[N],p[N],a[N],t[N],k[N],b[N];
int n,Q,m,cnt;
vi add[N],ans;

int main(){
	read(n),read(Q),read(m);
	rep(i,1,n)read(a[i]),fir[i]=a[i];
	rep(i,1,Q){
		read(t[i]),read(k[i]),read(b[i]);
		if(t[i]==1){
			if(b[i]>fir[k[i]]){
				fir[k[i]]=b[i];
				p[k[i]]=i;
			}
		}
		else if(t[i]==2){
			add[k[i]].pb(i);
		}
		else{
			x[++cnt].set(b[i]-1,1,i);
		}
	}
	rep(i,1,n){
		if(p[i]){
			b[p[i]]=fir[i]-a[i];
			add[i].pb(p[i]);
		}
		sort(add[i].begin(),add[i].end(),[&](int x,int y){
			return b[x]>b[y];
		});
		for(auto t:add[i]){
			x[++cnt].set(b[t],a[i],t);
			a[i]+=b[t];
		}
	}
	sort(x+1,x+cnt+1);
	rep(i,1,min(cnt,m)) ans.pb(x[i].id);
	sort(ans.begin(),ans.end(),[&](int x,int y){
		return t[x]<t[y];
	});
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	return 0;
}