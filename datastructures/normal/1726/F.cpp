#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n,t,g[500005],c[500005];
int dis[500005],d[500005],e[500005];
int tot,s[500005];
int f[500005][2],ans=1e18;
int larger(int x){
	int l=1,r=tot,ans=tot+1;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]>x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int lower(int x){
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int tree[2000005],tag[2000005];
void pushdown(int now){
	if (tag[now]!=0){
		tree[now*2]=tag[now*2]=tree[now*2+1]=tag[now*2+1]=tag[now];
		tag[now]=0;
	}
	return;
}
void upd(int now,int nowl,int nowr,int lt,int rt,int val){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]=tag[now]=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)upd(now*2+1,mid+1,nowr,lt,rt,val);
	return;
}
int ask(int now,int nowl,int nowr,int pos){
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr)return tree[now];
	int mid=(nowl+nowr)/2;
	if (pos<=mid)return ask(now*2,nowl,mid,pos);
	return ask(now*2+1,mid+1,nowr,pos);
}
signed main(){
	cin>>n>>t;
	for (int i=1;i<=n;i++)scanf("%lld%lld",&g[i],&c[i]);
	for (int i=1;i<n;i++)scanf("%lld",&dis[i]);
	int sumdis=0;
	for (int i=1;i<=n;i++){
		d[i]=(c[i]+sumdis)%t;
		e[i]=(d[i]-g[i]+1+t)%t;
		sumdis=(sumdis+dis[i])%t;
		s[++tot]=d[i];
		s[++tot]=e[i];
	}
	sort(s+1,s+1+tot);
	memset(tree,0,sizeof(tree));
	memset(tag,0,sizeof(tag));
	for (int i=n;i>=1;i--){
		int pos=ask(1,1,tot,lower(d[i]));
		if (pos==0)f[i][0]=0;
		else{
			int qwq=(d[pos]-d[i]+t)%t;
			f[i][0]=f[pos][0]+t-qwq;
		}
		pos=ask(1,1,tot,lower(e[i]));
		if (pos==0)f[i][1]=0;
		else{
			int qwq=(d[pos]-e[i]+t)%t;
			f[i][1]=f[pos][0]+t-qwq;
		}
		int l=larger(d[i]-t),r=lower(d[i]-g[i]);
		if (l<=r)upd(1,1,tot,l,r,i);
		l=larger(d[i]),r=lower(d[i]-g[i]+t);
		if (l<=r)upd(1,1,tot,l,r,i);
	}
	memset(tree,0,sizeof(tree));
	memset(tag,0,sizeof(tag));
	for (int i=1;i<=n;i++){
		if (ask(1,1,tot,lower(d[i]))==0)ans=min(ans,f[i][0]);
		if (ask(1,1,tot,lower(e[i]))==0)ans=min(ans,f[i][1]);
		int l=larger(d[i]-t),r=lower(d[i]-g[i]);
		if (l<=r)upd(1,1,tot,l,r,i);
		l=larger(d[i]),r=lower(d[i]-g[i]+t);
		if (l<=r)upd(1,1,tot,l,r,i);
	}
	for (int i=1;i<n;i++)ans+=dis[i];
	cout<<ans<<endl;
	return 0;
}