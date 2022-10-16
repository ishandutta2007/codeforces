#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
#define int long long
using namespace std;
int n,ans;
struct node{
	int x,y;
}a[200005];
inline bool cmp(node a,node b){
	return a.y>b.y;
}
int c[200005];
int s[200005],tot;
inline int lower(register int x){
	register int l=1,r=tot,ans=0;
	while(l<=r){
		register int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
struct BIT{
	int tree[1000005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=1000000;
	}
	inline int lowbit(register int x){
		return x&(-x);
	}
	inline void add(register int pos){
		while(pos<=maxn)tree[pos]++,pos+=lowbit(pos);
		return;
	}
	inline int ask(register int l,register int r){
		if (l>r)return 0;
		register int ans=0;
		while(r)ans+=tree[r],r-=lowbit(r);
		l--;
		while(l)ans-=tree[l],l-=lowbit(l);
		return ans;
	}
}bit;
int d[200005],len;
signed main(){
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);
	for (register int i=1;i<=n;i++)s[++tot]=a[i].x;
	sort(s+1,s+1+n);
	for (register int i=1;i<=n;i++)a[i].x=lower(a[i].x);
	for (register int i=1;i<=n;){
		register int j=i,len=0;
		while(j<=n&&a[j].y==a[i].y){
			d[++len]=a[j].x;
			if (c[a[j].x]==0)c[a[j].x]=1,bit.add(a[j].x);
			j++;
		}
		ans+=bit.ask(1,1000000)*(bit.ask(1,1000000)+1)/2;
		sort(d+1,d+1+len);
		d[++len]=1000000;
		for (register int i=0;i<len;i++)ans-=bit.ask(d[i]+1,d[i+1]-1)*(bit.ask(d[i]+1,d[i+1]-1)+1)/2;
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}