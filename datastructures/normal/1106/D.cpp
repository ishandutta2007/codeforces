#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,m,u[200005],v[200005],first[100005],nxt[200005];
int book[100005];
priority_queue <int>h;
int main(){
//	freopen("1106D.in","r",stdin);
//	freopen("1106D.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	h.push(-1);
	book[1]=1;
	while(!h.empty()){
		int id=-h.top();
		h.pop();
		printf("%d ",id);
		for (int i=first[id];i;i=nxt[i])
			if (!book[v[i]])h.push(-v[i]),book[v[i]]=1;
	}
	return 0;
}