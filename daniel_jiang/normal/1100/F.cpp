// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

#define int ll

const int N=5e5+5;
int n,q,ans[N],b[N];
struct question{
	int l,r,id;
	inline bool operator < (const question &o)const{return r<o.r;}
}p[N];

struct XOR_Base{
	const int M=63;
	ll a[64],p[64],pos[64];int cnt;
	inline void insert(ll x,int k){
		for(re i=M;i>=0;--i)
			if(x&(1ll<<i))
				if(!a[i]){a[i]=x;pos[i]=k;return ;}
				else{if(pos[i]<k) swap(pos[i],k),swap(x,a[i]);x^=a[i];}
	}
	inline ll maxn(int k){
		ll ans=0;
		for(re i=M;i>=0;--i) if(pos[i]>=k) ans=max(ans,ans^a[i]);
		return ans;
	}
}A;

// ---------- XOR-Base ---------- //

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i) rd(b[i]);
	rd(q);
	for(re i=1;i<=q;++i) rd(p[i].l),rd(p[i].r),p[i].id=i;
	sort(p+1,p+q+1);int nw=0;
	for(re i=1;i<=q;++i){
		while(nw<p[i].r) ++nw,A.insert(b[nw],nw);ans[p[i].id]=A.maxn(p[i].l);
	}
	for(re i=1;i<=q;++i) wr(ans[i]),puts("");
	return 0;
}

// ---------- Main ---------- //