// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x)fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')fl=-fl;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0)x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[40]={0},cnt=0;
	while(x)tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i)putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=5e5+5,mod=998244353;
int n,cnt,m,T,rt,fac[N],inv[N];
struct node{int l,r,rd,v,sz,tag;}t[N];

inline int pw(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=1ll*sum*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return sum;
}

inline void init(int n){
	fac[0]=1;
	for(re i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=pw(fac[n],mod-2);
	for(re i=n-1;i>=0;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
}

inline int C(int x,int y){
	if(x<y||y<0)return 0;
	return 1ll*fac[x]*inv[x-y]%mod*inv[y]%mod;
}

inline int newnode(int val){
	++cnt;t[cnt].l=t[cnt].r=t[cnt].tag=0;t[cnt].v=val;t[cnt].sz=1;t[cnt].rd=rand();
	return cnt;
}

inline void pushup(int p){
	if(!p) return;
	t[p].sz=t[t[p].l].sz+t[t[p].r].sz+1;
}

inline void pushdown(int p){
	if(!p) return;
	if(t[p].tag){
		if(t[p].l) t[t[p].l].v+=t[p].tag,t[t[p].l].tag+=t[p].tag;
		if(t[p].r) t[t[p].r].v+=t[p].tag,t[t[p].r].tag+=t[p].tag;
		t[p].tag=0;
	}
}

inline void split(int p,int k,int &x,int &y){
	if(!p){x=y=0;return;}
	pushdown(p);
	if(k>=t[p].v) x=p,split(t[p].r,k,t[p].r,y);
	else y=p,split(t[p].l,k,x,t[p].l);
	pushup(p);
}

inline int merge(int x,int y){
	if(!x||!y) return x|y;
	if(t[x].rd<t[y].rd){
		pushdown(x);t[x].r=merge(t[x].r,y);pushup(x);
		return x;
	}
	else{
		pushdown(y);t[y].l=merge(x,t[y].l);pushup(y);
		return y;
	}
}

inline bool find(int x,int p){
	if(!p) return 0;
	if(t[p].v==x) return 1;
	pushdown(p);
	if(x<t[p].v) return find(x,t[p].l);
	else return find(x,t[p].r);
}

inline void solve(){
	rd(n);rd(m);rt=cnt=0;
	for(re i=1;i<=m;++i){
		int a,b,x,y;rd(a);rd(b);
		bool f=find(b,rt);
		split(rt,b-1,x,y);
		if(y) ++t[y].v,++t[y].tag;
		rt=merge(x,f?y:merge(newnode(b+1),y));
	}
	wr(C(n+n-cnt-1,n));puts("");
}

// ----------	---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	init(400000);srand(time(nullptr));
	rd(T);while(T--)solve();
	return 0;
}

// ---------- Main ---------- //