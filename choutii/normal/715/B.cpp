#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
#define fir first
#define sec second
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}

#define N 1234
#define M 23333
#define inf 111111111111111ll
struct edge{int to,nxt;ll v;}e[M];int cnt,lst[N];
int n,m,L,s,t,a[M],b[M],c[M],d[M];ll dis[N];
void ins(int a,int b,ll c){e[++cnt]=(edge){b,lst[a],c};lst[a]=cnt;}
void lnk(int a,int b,ll c){ins(a,b,c);ins(b,a,c);}
void me(){memset(lst,0,sizeof(lst));cnt=0;} 
void build(int x,ll v){
	me();
	for(int i=1;i<=m;i++)
		lnk(a[i],b[i],c[i]?c[i]:v+(i<=x));
}
#include<ext/pb_ds/priority_queue.hpp>
namespace Dijkstra{
	#define pa pair<ll,int>
	#define mpa make_pair
	using namespace __gnu_pbds;
	typedef __gnu_pbds::priority_queue<pa,greater<pa>,pairing_heap_tag > heap;
	heap::point_iterator id[N];bool v[N];
	ll dijkstra(int s,int t){
	    heap q;int i,b;
	    for(i=1;i<=n;i++)dis[i]=inf,id[i]=0;
	    dis[s]=0;id[s]=q.push(make_pair(0,s));
		while(!q.empty()){
			int c=q.top().second;q.pop();
	        for(i=lst[c],b;b=e[i].to,i;i=e[i].nxt){
				if(cmin(dis[b],dis[c]+e[i].v))
	                if(id[b]!=0)
	                    q.modify(id[b],mpa(dis[b],b));
	                else 
						id[b]=q.push(mpa(dis[b],b));
			}
	    }
	    return dis[t];
	}
}
using Dijkstra::dijkstra;
int main(){
	int i;
	scanf("%d%d%d%d%d",&n,&m,&L,&s,&t);++s;++t;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",a+i,b+i,c+i);++a[i];++b[i];
		if(c[i])lnk(a[i],b[i],c[i]); 
	}
	if(dijkstra(s,t)<L)return puts("NO"),0;
	for(i=1;i<=m;i++)if(!c[i])lnk(a[i],b[i],1);
	if(dijkstra(s,t)>L)return puts("NO"),0;
	ll l,r,l1,R=inf,o,ans;
	while(l<=R){
		o=(l+R)/2;
		build(0,o);
		if(dijkstra(s,t)<=L)
			l=o+1;
		else R=o-1;
	}
	l1=l;
	l=1;r=m;
	while(l<=r){
		o=(l+r)/2;
		build(o,R);
		if(dijkstra(s,t)<=L)
			l=o+1;
		else r=o-1;
	}
	puts("YES");
	for(i=1;i<=m;i++)
		printf("%d %d %lld\n",a[i]-1,b[i]-1,c[i]?c[i]:(i<=r?l1:R));
	return 0;
}