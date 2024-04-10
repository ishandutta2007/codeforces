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

const int N=1e5+5;const ll INF=903372036854775807;
int n,m,k,s1,s2,t,hd[N],cnte,tmp[N],l[N],r[N],u[N],v[N],st[N],tp;
ll dis1[N],dis2[N];
priority_queue<ll,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
struct edge{int nxt,t,id;}es[N];
inline void add(int x,int y,int z){es[++cnte]=(edge){hd[x],y,z};hd[x]=cnte;}

inline void dijkstra(bool op){
	for(re i=1;i<=n;++i) dis1[i]=dis2[i]=INF;
	dis1[s1]=0;dis2[s2]=0;q.push(mp(0,s1));q.push(mp(0,s2));
	while(!q.empty()){
		int x=q.top().second;ll d=q.top().first;q.pop();
		if(min(dis1[x],dis2[x])!=d) continue;
		if(dis1[x]<dis2[x]||op&&dis1[x]==dis2[x]){
			for(re i=hd[x];i;i=es[i].nxt){
				int to=es[i].t;ll w=d+l[es[i].id];
				if(w<min(dis1[to],dis2[to])) q.push(mp(dis1[to]=w,to));
				else dis1[to]=min(dis1[to],w);
			}
		}
		else{
			for(re i=hd[x];i;i=es[i].nxt){
				int to=es[i].t;ll w=d+r[es[i].id];
				if(w<min(dis1[to],dis2[to])) q.push(mp(dis2[to]=w,to));
				else dis2[to]=min(dis2[to],w);
			}
		}
	}
} 

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m);rd(k);rd(s1);rd(s2);rd(t);
	for(re i=1;i<=m;++i){
		int x,y;rd(x);rd(y);rd(l[i]);r[i]=l[i];add(x,y,i);
	}
	for(re i=m+1;i<=m+k;++i){
		int x,y;rd(x);rd(y);rd(l[i]);rd(r[i]);add(x,y,i);u[i]=x;v[i]=y;
	}
	if(s1==s2){
		puts("DRAW");
		for(re i=m+1;i<=m+k;++i) wr(l[i]),putchar(' ');puts("");
		return 0;
	}
	dijkstra(0);
	if(dis1[t]<dis2[t]){
		puts("WIN");
		for(re i=m+1;i<=m+k;++i)
			wr(dis1[u[i]]<dis2[u[i]]&&dis1[v[i]]<dis2[v[i]]?l[i]:r[i]),putchar(' ');puts("");
		return 0;
	}
	dijkstra(1);
	if(dis1[t]<=dis2[t]){
		puts("DRAW");
		for(re i=m+1;i<=m+k;++i)
			wr(dis1[u[i]]<=dis2[u[i]]&&dis1[v[i]]<=dis2[v[i]]?l[i]:r[i]),putchar(' ');puts("");
		return 0;
	}
	puts("LOSE");
	return 0;
}

// ---------- Main ---------- //