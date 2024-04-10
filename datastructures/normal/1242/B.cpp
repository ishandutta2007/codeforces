#include <iostream>
#include <cstdio>
#include <map>
#define int long long 
using namespace std;
map <int,int>a;
int n,m,book[100005];
int nxt[100005],pre[100005];
int q[100005],head,tail;
inline int ask(int u,int v){
	return u*1000000+v;
}
inline void del(int i){
	int pr=pre[i],nx=nxt[i];
	nxt[pr]=nx,pre[nx]=pr;
	return;
}
inline void bfs(int now){
	q[head=tail=1]=now;
	while(head<=tail){
		int c=q[head];
		head++;
		book[c]=1;
		for (int i=nxt[0];i>=1&&i<=n;i=nxt[i]){
			if (a[ask(c,i)]==0){
				q[++tail]=i;
				del(i);
			}
		}
	}
	return;
}
signed main(){
//	freopen("1242B.in","r",stdin);
//	freopen("1242B.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%I64d%I64d",&u,&v);
		a[ask(u,v)]=a[ask(v,u)]=1;
	}
	for (int i=1;i<=n;i++)pre[i]=i-1,nxt[i]=i+1;
	nxt[0]=1;
	int ans=0;
	for (int i=1;i<=n;i++){
		if (book[i]==0)ans++,del(i),bfs(i);
	}
	cout<<ans-1<<endl;
	return 0;
}