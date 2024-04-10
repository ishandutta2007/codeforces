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

const int N=1e5+5,mod=998244389;
int n,m,st,ed,cnte1,cnte2,u[N],v[N],w[N];
ll cnt1[N],cnt2[N],dis1[N],dis2[N],hd1[N],hd2[N];
bool vst1[N],vst2[N];
struct edge{int t,nxt;ll w;}es1[N],es2[N];
inline void add1(int x,int y,int z){es1[++cnte1]=(edge){y,hd1[x],z};hd1[x]=cnte1;}
inline void add2(int x,int y,int z){es2[++cnte2]=(edge){y,hd2[x],z};hd2[x]=cnte2;}

struct node{
	int id;ll w;
	bool operator < (const node &a) const{return w>a.w;}
};

priority_queue<node> q;

inline void dijkstra(){
	for(re i=1;i<=n;++i) dis1[i]=dis2[i]=2e18;
	dis1[st]=0;cnt1[st]=1;
	q.push((node){st,0});
	while(!q.empty()){
		int x=q.top().id;
		if(vst1[x]){q.pop();continue;}
		q.pop();vst1[x]=1;
		for(re k=hd1[x];k;k=es1[k].nxt){
			if(dis1[es1[k].t]>dis1[x]+es1[k].w){
				dis1[es1[k].t]=dis1[x]+es1[k].w;
				cnt1[es1[k].t]=cnt1[x];
				q.push((node){es1[k].t,dis1[es1[k].t]});
			}
			else if(dis1[es1[k].t]==dis1[x]+es1[k].w){
				cnt1[es1[k].t]=(cnt1[es1[k].t]+cnt1[x])%mod;
			}
		}
	}
	dis2[ed]=0;cnt2[ed]=1;
	q.push((node){ed,0});
	while(!q.empty()){
		int x=q.top().id;
		if(vst2[x]){q.pop();continue;}
		q.pop();vst2[x]=1;
		for(re k=hd2[x];k;k=es2[k].nxt){
			if(dis2[es2[k].t]>dis2[x]+es2[k].w){
				dis2[es2[k].t]=dis2[x]+es2[k].w;
				cnt2[es2[k].t]=cnt2[x];
				q.push((node){es2[k].t,dis2[es2[k].t]});
			}
			else if(dis2[es2[k].t]==dis2[x]+es2[k].w){
				cnt2[es2[k].t]=(cnt2[es2[k].t]+cnt2[x])%mod;
			}
		}
	}
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m);rd(st);rd(ed);
	for(re i=1;i<=m;++i) rd(u[i]),rd(v[i]),rd(w[i]),add1(u[i],v[i],w[i]),add2(v[i],u[i],w[i]);
	dijkstra();
	for(re i=1;i<=m;++i){
		if(dis1[u[i]]+dis2[v[i]]+w[i]==dis1[ed]&&cnt1[u[i]]*cnt2[v[i]]%mod==cnt1[ed]) puts("YES");
		else{
			if(dis1[ed]-dis1[u[i]]-dis2[v[i]]<=1) puts("NO");
			else cout<<"CAN ",wr(w[i]-(dis1[ed]-dis1[u[i]]-dis2[v[i]])+1),puts("");
		}
	}
	return 0;
}

// ---------- Main ---------- //