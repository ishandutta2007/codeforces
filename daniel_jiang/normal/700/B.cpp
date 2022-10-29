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
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=2e5+5;
int n,k,cnte,hd[N];
ll ans,sum[N];
struct edge{int t,nxt;}es[N<<2];
inline void add(int x,int y){es[++cnte]=(edge){y,hd[x]};hd[x]=cnte;}

inline void dfs(int x,int fa){
	for(re i=hd[x];i;i=es[i].nxt)
		if(es[i].t^fa) dfs(es[i].t,x),sum[x]+=sum[es[i].t];
	ans+=min(sum[x],(k<<1)-sum[x]);
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(k);
	for(re i=1;i<=(k<<1);++i){int x;rd(x);++sum[x];}
	for(re i=1;i<n;++i){int x,y;rd(x);rd(y);add(x,y);add(y,x);}
	dfs(1,0);wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //