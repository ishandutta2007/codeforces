#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std; 
char s[200005];
int n,T,m,sa[400005],rk[400005],tp[400005],tax[400005],h[400005],height[400005];
struct SGT{
	int tree[1000005];
	SGT(){
		memset(tree,0x7f,sizeof(tree));
		return;
	}
	inline void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void tree_update(int now,int nowl,int nowr,int pos,int val){
		if (nowl==nowr){
			tree[now]=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (pos<=mid)tree_update(now*2,nowl,mid,pos,val);
		else tree_update(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	inline void update(int pos,int val){
		tree_update(1,1,n,pos,val);
		return;
	}
	inline int tree_query(int now,int nowl,int nowr,int lt,int rt){
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=1e9;
		if (mid>=lt)s=min(s,tree_query(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,tree_query(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int query(int l,int r){
		return tree_query(1,1,n,l,r);
	}
}sgt;
inline void Qsort(){
	memset(tax,0,sizeof(tax));
	for (int i=1;i<=n;i++)tax[rk[i]]++;
	for (int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for (int i=n;i>=1;i--)
		sa[tax[rk[tp[i]]]--]=tp[i];
	return;
}
inline void Suffix_Sorting(){
	m=200;
	for (int i=1;i<=n;i++)tp[i]=i,rk[i]=(int)(s[i]); 
	Qsort();
	for (int w=1,p=0;p<n;m=p,w*=2){
		p=0;
		for (int i=n-w+1;i<=n;i++)tp[++p]=i;
		for (int i=1;i<=n;i++)
			if (sa[i]>w)tp[++p]=sa[i]-w;
		Qsort();
		swap(rk,tp);
		rk[sa[1]]=1;
		p=1;
		for (int i=2;i<=n;i++){
			if (tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
	}
	return;
} 
inline void Get_Height(){
	for (int i=1;i<=n;i++){
		h[i]=max(0,h[i-1]-1);
		while(s[i+h[i]]==s[sa[rk[i]-1]+h[i]]&&i+h[i]<=n&&sa[rk[i]-1]+h[i]<=n)h[i]++;
	}
	for (int i=1;i<=n;i++)height[i]=h[sa[i]];
	return;
}
int a[200005],b[200005],c[400005],tot;
int tail;
struct node{
	int cnt,val;
	node(){
		cnt=val=0;
	}
}q[400005];
ll calc(){
	for (int i=1;i<=tot;i++)c[i]=rk[c[i]];
	sort(c+1,c+1+tot);
	if (tot==1)return 0; 
	tot--;
	for (int i=1;i<=tot;i++)
		if (c[i]==c[i+1])c[i]=n-sa[c[i]]+1;
		else c[i]=sgt.query(c[i]+1,c[i+1]);
	ll nowsum=0,sum=0;
	tail=0;
	for (int i=1;i<=tot;i++){
		node now;
		now.cnt=1,now.val=c[i];
		while(tail>0&&q[tail].val>now.val){
			now.cnt+=q[tail].cnt;
			nowsum-=q[tail].cnt*q[tail].val;
			tail--;
		}
		q[++tail]=now;
		nowsum+=q[tail].cnt*q[tail].val;
		sum+=nowsum;
	}
	return sum;
}
int main(){
	cin>>n>>T;
	scanf("%s",s+1);
	Suffix_Sorting();
	Get_Height();
	for (int i=2;i<=n;i++)sgt.update(i,height[i]);
	while(T--){
		int l1,l2;
		scanf("%d%d",&l1,&l2);
		for (int i=1;i<=l1;i++)scanf("%d",&a[i]);
		for (int i=1;i<=l2;i++)scanf("%d",&b[i]);
		ll ans=0;
		tot=0;
		for (int i=1;i<=l1;i++)c[++tot]=a[i];
		ans-=calc();
		tot=0;
		for (int i=1;i<=l2;i++)c[++tot]=b[i];
		ans-=calc();
		tot=0;
		for (int i=1;i<=l1;i++)c[++tot]=a[i];
		for (int i=1;i<=l2;i++)c[++tot]=b[i];
		ans+=calc();
		printf("%lld\n",ans);
	}
}//AHOI2020RP+=INF