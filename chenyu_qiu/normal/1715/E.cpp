#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
typedef long long ll;
const ll inf=1e13;
int n,m,k;
int lst[N],to[N<<1],len[N<<1],nxt[N<<1],ec;
inline void ae(int x,int y,int z){
	to[++ec]=y,nxt[ec]=lst[x],len[ec]=z,lst[x]=ec;	
}
ll dis[N];
void dijkstra(){
	priority_queue<pair<ll,int> > pq;
	for(int i=1;i<=n;i++)pq.push(make_pair(-dis[i],i));
	while(pq.size()){
		int x=pq.top().second;
		ll d=-pq.top().first;
		pq.pop();
		if(d!=dis[x])continue;
		for(int i=lst[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>d+len[i]){
				dis[y]=d+len[i];
				pq.push(make_pair(-dis[y],y));
			}
		}
	}
}
ll px[N],py[N];
int q[N],ql,qr;
bool check(int a,int b,int c){
	ll v1=(ll)(py[b]-py[a])*(px[c]-px[a]);
	ll v2=(ll)(py[c]-py[a])*(px[b]-px[a]);
	return v1>=v2;
}
ll get(int p,int k){
	return py[p]-2*px[p]*k;
}
void dp(){	
	ql=1,qr=0;
	for(int i=1;i<=n;i++){
		px[i]=i,py[i]=dis[i]+(ll)i*i;
		while(ql<qr&&check(q[qr-1],q[qr],i))qr--;
		q[++qr]=i;
		while(ql<qr&&get(q[ql],i)>=get(q[ql+1],i))ql++;
		dis[i]=get(q[ql],i)+(ll)i*i;
	}
}
int main(){
	n=in(),m=in(),k=in();
	while(m--){
		int x=in(),y=in(),z=in();
		ae(x,y,z),ae(y,x,z);	
	}
	for(int i=2;i<=n;i++)dis[i]=inf;
	dijkstra();
	while(k--){
		dp();
		reverse(dis+1,dis+n+1);
		dp();
		reverse(dis+1,dis+n+1);
		dijkstra();
	}
	for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
	return 0;
}