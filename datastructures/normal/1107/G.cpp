#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
#define inf 1000000000000000000
using namespace std;
int n,a,d[300005],c[300005],sum[300005],val[300005],ans;
struct SGT{
	int tree[3000005],tag[3000005];
	SGT(){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		return;
	}
	inline void pushup(register int now){
		tree[now]=max(tree[now*2],tree[now*2+1]);
		return;
	}
	inline void pushdown(register int now){
		tree[now*2]+=tag[now],tree[now*2+1]+=tag[now];
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		tag[now]=0;
		return;
	}
	inline void tree_add(register int now,register int nowl,register int nowr,register int lt,register int rt,register int val){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tree[now]+=val;
			tag[now]+=val;
			return;
		}
		register int mid=(nowl+nowr)/2;
		if (mid>=lt)tree_add(now*2,nowl,mid,lt,rt,val);
		if (mid+1<=rt)tree_add(now*2+1,mid+1,nowr,lt,rt,val);
		pushup(now);
		return;
	}
	inline void add(register int l,register int r,register int val){
		if (l<1)l=1;
		if (l>r)return;
		tree_add(1,1,n,l,r,val);
		return;
	}
	inline int tree_ask(register int now,register int nowl,register int nowr,register int lt,register int rt){
		if (nowl!=nowr)pushdown(now);
		if (nowl>=lt&&nowr<=rt)return tree[now];
		int mid=(nowl+nowr)/2,s=-inf;
		if (mid>=lt)s=max(s,tree_ask(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,tree_ask(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int ask(register int l,register int r){
		return tree_ask(1,1,n,l,r);
	}
}sgt;
int q[1000005],tail;
signed main(){
	cin>>n>>a;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&d[i],&c[i]),val[i]=(d[i]-d[i-1])*(d[i]-d[i-1]),sum[i]=sum[i-1]+c[i];
	for (int i=1;i<=n;i++){
		sgt.add(i,i,sum[i-1]-a*i);
		sgt.add(i-1,i-1,-val[i]);
		while(tail&&val[i]>=val[q[tail]]){
			sgt.add(q[tail-1],q[tail]-1,-(val[i]-val[q[tail]]));
			--tail;
		}
		q[++tail]=i;
		ans=max(ans,i*a-sum[i]+a+sgt.ask(1,i));
	}
	cout<<ans<<endl;
	return 0;
}
//val(l,r)=(r-l+1)*a-max{mx[l+1]~mx[r]}-(sum[r]-sum[l-1])
//val(l,r)=r*a-sum[r]+a+(sum[l-1]-a*l-max{mx[l+1]~mx[r]})