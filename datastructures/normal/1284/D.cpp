#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
struct SGT{
	int tree[2000005],tag[2000005],maxn;
	void mem(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		maxn=500000;
		return;
	}
	void pushup(int now){
		tree[now]=tree[now*2]+tree[now*2+1];
		return;
	}
	void pushdown(int now,int nowl,int nowr){
		int mid=(nowl+nowr)/2;
		tree[now*2]+=tag[now]*(mid-nowl+1);
		tree[now*2+1]+=tag[now]*(nowr-mid);
		tag[now*2]+=tag[now];
		tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	void update(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=(nowr-nowl+1)*val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	void add(int l,int r,int val){
		update(1,1,maxn,l,r,val);
		return;
	}
	int query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl!=nowr)pushdown(now,nowl,nowr);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s+=query(now*2,nowl,mid,lt,rt);
		if (mid+1<=rt)s+=query(now*2+1,mid+1,nowr,lt,rt);
		return s;
	}
	int ask(int l,int r){
		return query(1,1,maxn,l,r);
	}
}sgt;
int n,l1[100005],r1[100005],l2[100005],r2[100005],s[500005],tot;
vector<int> ins[500005],ask[500005];
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int fg=1;
void work(){
	sgt.mem();
	for (int i=0;i<=tot;i++)ins[i].clear(),ask[i].clear();
	for (int i=1;i<=n;i++)ins[r1[i]].push_back(i),ask[l1[i]-1].push_back(i);
	for (int i=1;i<=tot;i++){
		for (int j=0;j<ins[i].size();j++)sgt.add(l2[ins[i][j]],r2[ins[i][j]],1);
		for (int j=0;j<ask[i].size();j++)
			if (sgt.ask(l2[ask[i][j]],r2[ask[i][j]])>0)fg=0;
	}
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld%lld%lld%lld",&l1[i],&r1[i],&l2[i],&r2[i]),s[++tot]=l1[i],s[++tot]=r1[i],s[++tot]=l2[i],s[++tot]=r2[i];
	sort(s+1,s+1+tot);
	for (int i=1;i<=n;i++)l1[i]=lower(l1[i]),r1[i]=lower(r1[i]),l2[i]=lower(l2[i]),r2[i]=lower(r2[i]);
	work();
	for (int i=1;i<=n;i++)swap(l1[i],l2[i]),swap(r1[i],r2[i]);
	work();
	if (fg==1)puts("YES");
	else puts("NO");
	return 0;
}