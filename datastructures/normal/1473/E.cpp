#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define int long long
using namespace std; 
int n,m,totm,u[4000005],v[4000005],w[4000005],first[4000005],nxt[4000005];
struct node{
	int id,dis;
	inline bool operator <(const node &x)const{
		return x.dis<dis;
	}
};
inline node make_node(register int a,register int b){
	node x;
	x.id=a,x.dis=b;
	return x;
}
priority_queue <node>h;
int dis[1000005],book[1000005];
inline void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	h.push(make_node(1,0));
	while(!h.empty()){
		while(!h.empty()&&book[(h.top()).id]==1)h.pop();
		if (h.empty())return;
		register int now=(h.top()).id;
		book[now]=1; 
		h.pop();
		for (register int i=first[now];i;i=nxt[i]){
			if (dis[v[i]]>dis[now]+w[i]){
				dis[v[i]]=dis[now]+w[i];
				h.push(make_node(v[i],dis[v[i]]));
			}
		} 
	}
	return;
}
inline void add(register int a,register int b,register int c){
	register int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
signed main(){
	cin>>n>>m;
	for (register int i=1;i<=m;i++){
		register int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		add(a,b,c),add(b,a,c);
		add(a+n,b+n,c),add(b+n,a+n,c);
		add(a+2*n,b+2*n,c),add(b+2*n,a+2*n,c); 
		add(a+3*n,b+3*n,c),add(b+3*n,a+3*n,c);
		add(a,b+n,0),add(b,a+n,0);
		add(a,b+2*n,2*c),add(b,a+2*n,2*c);
		add(a,b+3*n,c),add(b,a+3*n,c);
		add(a+n,b+3*n,2*c),add(b+n,a+3*n,2*c);
		add(a+2*n,b+3*n,0),add(b+2*n,a+3*n,0);
	}
	dijkstra();
	for (register int i=2;i<=n;i++)
		printf("%lld ",dis[i+3*n]);
	cout<<endl;
	return 0;
}