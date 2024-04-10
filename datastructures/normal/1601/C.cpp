#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct SGT{
	int tree[8000005],tag[8000005],maxn;
	void mem(int n){
		for (int i=0;i<=4*(n+1);i++)tree[i]=tag[i]=0;
		maxn=n;
		return;
	}
	void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	void pushdown(int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	void update(int l,int r,int val){
		tree_update(1,0,maxn,l,r,val);
		return;
	}
	int query(){
		return tree[1];
	}
}sgt;
struct BIT{
	int tree[2000005],maxn;
	void mem(int n){
		for (int i=0;i<=n;i++)tree[i]=0;
		maxn=n;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
int t,n,m,a[1000005],b[1000005],s[2000005],tot,f[2000005];
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
vector<int> pos[2000005];
ll ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		sgt.mem(n);
		bit.mem(n+m);
		for (int i=1;i<=n;i++)a[i]=read(),s[++tot]=a[i];
		for (int i=1;i<=m;i++)b[i]=read(),s[++tot]=b[i];
		sort(s+1,s+1+tot);
		for (int i=1;i<=n;i++)a[i]=lower(a[i]),pos[a[i]].push_back(i);
		for (int i=1;i<=m;i++)b[i]=lower(b[i]);
		for (int i=1;i<=n;i++)bit.add(a[i],1),ans+=i-bit.ask(a[i]);
		for (int i=1;i<=n;i++)
			if (a[i]>1)sgt.update(i,n,1);
		for (int i=1;i<=tot;i++){
			f[i]=sgt.query();
			for (int j=0,len=pos[i+1].size();j<len;j++)sgt.update(pos[i+1][j],n,-1);
			for (int j=0,len=pos[i].size();j<len;j++)sgt.update(0,pos[i][j]-1,1);
		}
		for (int i=1;i<=m;i++)ans+=f[b[i]];
		cout<<ans<<endl;
		for (int i=1;i<=tot;i++)pos[i].clear();
		ans=0;
		tot=0;
	}
	return 0;
}