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

struct CartesianTree{
	struct node{
		int id,v,fa,ls,rs;
	}tr[10];
	inline void init(){tr[0].id=tr[0].v=tr[0].ls=tr[0].rs=tr[0].fa=0;}
	inline void insert(int x,int y,int z){
		tr[x].id=x;tr[x].v=y;tr[x].fa=z;tr[x].ls=tr[x].rs=0;
		int k=x-1;
		while(tr[k].v>tr[x].v) k=tr[k].fa;
		tr[x].ls=tr[k].rs;tr[k].rs=x;
		tr[x].fa=k;tr[tr[x].rs].fa=x;
	}
}CT;

// ---------- IO ---------- //

const int N=1e5+5,mod=998244353;
int T,n,a[N],ans,k;
bool flag;
vector<int> es[N];

inline int pw(int x,int y){
	int sum=1;
	while(y){
		if(y&1) sum=1ll*sum*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return sum;
}

inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

inline int dfs(int x,int fa){
    if(!flag) return 0;
    int tot=es[x].size();
    for(re i=0;i<es[x].size();++i)
		if(es[x][i]!=fa) tot-=dfs(es[x][i],x);
    if(tot%k&&(tot-1)%k) flag=0;
    if(tot%k==0){ans=gcd(ans,tot);return 1;}
    else{ans=gcd(ans,tot-1);return 0;}
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);
		for(int i=1,x,y;i<n;++i){
			rd(x);rd(y);es[x].pb(y);es[y].pb(x);
		}
		int maxn=n-1;
		for(re i=2;i*i<=maxn;++i)
			if(maxn%i==0){
				flag=1;ans=0;k=i;dfs(1,0);
				if(flag) a[ans]=1;
				while(maxn%i==0) maxn/=i;
			}
		if(maxn>1){
			flag=1;ans=0;k=maxn;dfs(1,0);
			if(flag) a[ans]=1;
		}
		a[1]=pw(2,n-1);
		for(re i=2;i<=n;++i) a[1]=(a[1]-a[i]+mod)%mod;
		for(re i=1;i<=n;++i) wr(a[i]),putchar(' ');puts("");
		for(re i=1;i<=n;++i) a[i]=0,es[i].clear();
	}
	return 0;
}

// ---------- Main ---------- //