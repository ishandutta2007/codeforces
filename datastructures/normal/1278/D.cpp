#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define int long long
using namespace std;
int n;
struct node{
	int l,r;
}a[2000005];
struct BIT{
	int tree[2000005];
	int maxn;
	inline void mem(){
		memset(tree,0,sizeof(tree));
		maxn=2000000;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int tree_ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
	inline int ask(int l,int r){
		return tree_ask(r)-tree_ask(l-1);
	}
	inline int nxt(int x){
		int l=x,r=maxn,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if (ask(l,mid)!=0)ans=mid,r=mid-1;
			else l=mid+1;
		}
		return ans;
	}
}bit;
int c[2000005],idl[2000005],idr[2000005],num[2000005];
int f[2000005],tot,fg=1;
inline int find(int x){
	if (x==f[x])return x;
	return f[x]=find(f[x]);
}
inline void merge(int x,int y){
	if (find(x)==find(y)){
		fg=0;
		return;
	}
	f[find(x)]=y;
	return;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&a[i].l,&a[i].r);
	for (int i=1;i<=n;i++)c[a[i].l]=a[i].r,idl[a[i].l]=i,idr[a[i].r]=i;
	bit.mem();
	for (int i=1;i<=2*n;i++)f[i]=i;
	for (int i=1;i<=2*n;i++){
		if (c[i]==0)continue;
		int now=bit.nxt(i);
		while(now&&now<=c[i]){
			tot++;
			if (tot>=n){
				fg=0;
				break;
			}
			merge(idl[i],idr[now]);
			now=bit.nxt(now+1);
		}
		bit.add(c[i],1);
	}
	if (fg==1&&tot==n-1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}