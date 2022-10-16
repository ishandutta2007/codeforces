#include <iostream>
#include <cstdio>
#define int long long
#define inf 1000000000000000000
using namespace std;
int n,q,a[1000005],k[1000005],sum[1000005],val[1000005],s[1000005];
int tree[1000005],tag[1000005],l,r,pos,x;
char opt[5];
inline void pushup(int now){
	tree[now]=tree[now*2]+tree[now*2+1];
	return;
}
inline void pushdown(int now,int nowl,int nowr){
	if (tag[now]==-inf)return;
	int mid=(nowl+nowr)/2;
	tree[now*2]=(mid-nowl+1)*tag[now];
	tree[now*2+1]=(nowr-mid)*tag[now];
	tag[now*2]=tag[now],tag[now*2+1]=tag[now];
	tag[now]=-inf;
	return;
}
inline void tree_update(int now,int nowl,int nowr,int lt,int rt,int val){
	pushdown(now,nowl,nowr);
	if (nowl>=lt&&nowr<=rt){
		tag[now]=val;
		tree[now]=(nowr-nowl+1)*val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)tree_update(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)tree_update(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
inline void update(int l,int r,int val){
	tree_update(1,1,n,l,r,val);
	return;
}
inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
	pushdown(now,nowl,nowr);
	if (nowl>=lt&&nowr<=rt)return tree[now];
	int mid=(nowl+nowr)/2,s=0;
	if (mid>=lt)s+=tree_query(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=tree_query(now*2+1,mid+1,nowr,lt,rt);
	return s; 
}
inline int query(int l,int r){
	return tree_query(1,1,n,l,r);
}
signed main(){
	for (int i=0;i<=1000000;i++)tag[i]=inf;
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<n;i++)scanf("%lld",&k[i]),sum[i]=sum[i-1]+k[i];
	for (int i=1;i<=n;i++)val[i]=a[i]-sum[i-1],update(i,i,val[i]);
	for (int i=1;i<=n;i++)s[i]=s[i-1]+sum[i-1];
	cin>>q;
	while(q--){
		scanf("%s",opt);
		if (opt[0]=='s'){
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",query(l,r)+(s[r]-s[l-1]));
		}
		else{
			scanf("%lld%lld",&pos,&x);
			int to=query(pos,pos)+x,l=pos,r=n,ans=0;
			while(l<=r){
				int mid=(l+r)/2;
				if (query(mid,mid)<=to)ans=mid,l=mid+1;
				else r=mid-1;
			}
			update(pos,ans,to);
		}
	}
	return 0;
}