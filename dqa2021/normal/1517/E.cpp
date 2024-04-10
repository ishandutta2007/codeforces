#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second

const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,a[200010];
ll b[200010],c[2][200010];

ll getsuf(int p){
	if (p>n) return 0;
	return b[n]-b[p-1];
}
ll getsuf2(int p){
	if (p>n) return 0;
	int t=p&1;
	return c[t][n]-c[t][p-1];
}

ll getsum(int l,int r){
	return b[r]-b[l-1];
}

ll getsum2(int r,int len){
	int t=r&1;
	return c[t][r]-c[t][r-len*2+1];
}

void solve(){
	n=read();
	
	static int cnt=0;
//	printf("case %d: n %d\n",++cnt,n);
	
	rep(i,1,n){
		a[i]=read();
		b[i]=b[i-1]+a[i];
		c[0][i]=c[0][i-1];
		c[1][i]=c[1][i-1];
		c[i&1][i]+=a[i];
	}
	if (n==1) return puts("1"),void();
	ll ans=0;
	rep(i,2,n){
		if (b[i-1]+getsuf2(i+1)<a[i]+getsuf2(i+2)) ans++;
	}
//	printf("test1 %lld\n",ans);
	rep(i,2,n){
		if (b[i]-b[1]+getsuf2(i+2)<a[1]+getsuf2(i+1)) ans++;
	}
//	printf("test2 %lld\n",ans);
	rep(i,2,n) if (getsuf(i+1)<b[i]) ans++;
//	printf("test3 %lld\n",ans);
	
	const auto check=[&](int u,int x,int y,int v){
		ll C=0,P=0;
		if (v) C+=a[n];
		C+=getsum(u+1,u+(n-u-v-x-x-y));
		if (x) C+=getsum2(n-v-y,x);
		if (u) P+=a[1];
		P+=getsum(n-v-y+1,n-v);
		if (x) P+=getsum2(n-v-y-1,x);
		return C<P;
	};
	
	rep(u,0,1) rep(v,0,1){
		rep(i,2,n-u-v-1){
			int l=0,r=n-u-v-i-1>>1,mid;
			while (l<r){
				mid=l+r>>1;
				if (check(u,mid,i,v)) r=mid;
				else l=mid+1;
			}
			if (!check(u,l,i,v)) continue;
			ans+=(n-u-v-i-1>>1)-l+1;
		}
	}
	printf("%lld\n",ans%mod);
}

int main()
{
//	freopen("data.in","r",stdin);
	for (int T=read();T--;) solve();
	return 0;
}