#include <iostream>
#include <cstdio>
#define inf 1000000000
#define int long long
using namespace std;
int n,a[300005],pre[300005],ans;
int q[300005],tail;
int val[1200005],cnt[1200005],tag[1200005];
void pushdown(int now){
	val[now*2]+=tag[now],val[now*2+1]+=tag[now];
	tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
	tag[now]=0;
	return;
}
void pushup(int now){
	if (val[now*2]<val[now*2+1])val[now]=val[now*2],cnt[now]=cnt[now*2];
	if (val[now*2]>val[now*2+1])val[now]=val[now*2+1],cnt[now]=cnt[now*2+1];
	if (val[now*2]==val[now*2+1])val[now]=val[now*2],cnt[now]=cnt[now*2]+cnt[now*2+1];
	return;
}
void update(int now,int nowl,int nowr,int lt,int rt,int nowval){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		val[now]+=nowval;
		tag[now]+=nowval;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,nowval);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,nowval);
	pushup(now);
	return;
}
int ask(){
	if (val[1]==0)return cnt[1];
	return 0;
}
void build(int now,int nowl,int nowr){
	val[now]=inf,cnt[now]=nowr-nowl+1;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	return;
}
signed main(){
	cin>>n;
	build(1,1,n);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++){
		if (pre[a[i]])update(1,1,n,1,pre[a[i]],inf);
		pre[a[i]]=i;
		update(1,1,n,i,i,-inf);
		update(1,1,n,i,i,a[i]);
		update(1,1,n,1,i,-1);
		while(tail&&a[q[tail]]<a[i]){
			update(1,1,n,q[tail-1]+1,q[tail],a[i]-a[q[tail]]);
			--tail;
		}
		q[++tail]=i;
		ans+=ask();
	}
	cout<<ans<<endl;
	return 0;
}
//max{l,r}-(r-l+1) >=0