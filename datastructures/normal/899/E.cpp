#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct SGT{
	int tree[2000005];
	int n=200000;
	SGT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline void pushup(int now){
		tree[now]=max(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void update(int now,int nowl,int nowr,int pos,int val){
		if (nowl==nowr){
			tree[now]=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (pos<=mid)update(now*2,nowl,mid,pos,val);
		else update(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	inline int query(int now,int nowl,int nowr){
		if (nowl==nowr){
			if (tree[now]==0)return -1;
			return nowl;
		}
		int mid=(nowl+nowr)/2;
		if (tree[now*2]>=tree[now*2+1])return query(now*2,nowl,mid);
		return query(now*2+1,mid+1,nowr);
	}
	inline void add(int now,int val){
		update(1,1,n,now,val);
		return;
	}
	inline int ask(){
		return query(1,1,n);
	}
}sgt;
int n,a[1000005],size[1000005],pre[1000005],nxt[1000005],ans;
int main(){
	cin>>n;
	int last=0;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==a[i-1]){
			size[last]++;
			pre[i]=i-1,nxt[i-1]=i;
		}
		else last=i,size[i]=1;
	} 
	for (int i=1;i<=n;i++){
		sgt.add(i,size[i]);
		pre[i]=i-1,nxt[i]=i+1;
	}
	while(1){
		int now=sgt.ask();
		if (now==-1)break;
		ans++;
		int nx=now,pr=pre[now];
		sgt.add(now,0);
		size[now]=0;
		while(size[nx]==0&&nx!=0)nx=nxt[nx];
		if (nx==0||pr==0)continue;
		nxt[pr]=nx;
		pre[nx]=pr;
		while(size[pr]==0&&pr!=0)pr=pre[pr];
		if (pr==0||nx==0||a[pr]!=a[nx])continue;
		size[pr]+=size[nx];
		sgt.add(nx,0);
		size[nx]=0;
		sgt.add(pr,size[pr]);
	}
	cout<<ans<<endl;
}