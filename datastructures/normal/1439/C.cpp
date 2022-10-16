#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n,q,opt,x;
ll a[200005],y;
ll val[800005],sum[800005],tag[800005];
void pushdown(int now,int nowl,int nowr){
	if (tag[now]==0)return;
	int mid=(nowl+nowr)/2;
	val[now*2]=tag[now],val[now*2+1]=tag[now];
	sum[now*2]=tag[now]*(mid-nowl+1),sum[now*2+1]=tag[now]*(nowr-mid);
	tag[now*2]=tag[now],tag[now*2+1]=tag[now];
	tag[now]=0;
	return;
}
void pushup(int now){
	sum[now]=sum[now*2]+sum[now*2+1];
	val[now]=val[now*2+1];
	return;
}
void update(int now,int nowl,int nowr,int lt,int rt,ll nowval){
	if (nowl!=nowr)pushdown(now,nowl,nowr);
	if (nowl>=lt&&nowr<=rt){
		val[now]=nowval;
		sum[now]=nowval*(nowr-nowl+1);
		tag[now]=nowval;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)update(now*2,nowl,mid,lt,rt,nowval);
	if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,nowval);
	pushup(now);
	return;
}
ll asksum(int now,int nowl,int nowr,int lt,int rt){
	if (nowl!=nowr)pushdown(now,nowl,nowr);
	if (nowl>=lt&&nowr<=rt)return sum[now];
	int mid=(nowl+nowr)/2;
	ll s=0;
	if (mid>=lt)s+=asksum(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)s+=asksum(now*2+1,mid+1,nowr,lt,rt);
	return s;
}
ll askval(int now,int nowl,int nowr,int pos){
	if (nowl!=nowr)pushdown(now,nowl,nowr);
	if (nowl==nowr)return val[now];
	int mid=(nowl+nowr)/2;
	if (pos<=mid)return askval(now*2,nowl,mid,pos);
	return askval(now*2+1,mid+1,nowr,pos);
}
int find1(int now,int nowl,int nowr,int pos,ll nowval){//find v[i]<=val
	if (nowl!=nowr)pushdown(now,nowl,nowr);
	if (nowl==nowr)return nowl;
	int mid=(nowl+nowr)/2;
	if (val[now*2]>nowval||pos>mid)return find1(now*2+1,mid+1,nowr,pos,nowval);
	return find1(now*2,nowl,mid,pos,nowval);
}
int find2(int now,int nowl,int nowr,ll nowsum){//find s[i]<=sum
	if (nowl!=nowr)pushdown(now,nowl,nowr);
	if (nowl==nowr)return nowl;
	int mid=(nowl+nowr)/2;
	if (sum[now*2]>=nowsum)return find2(now*2,nowl,mid,nowsum);
	return find2(now*2+1,mid+1,nowr,nowsum-sum[now*2]);
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		update(1,1,n,i,i,a[i]);
	}
	while(q--){
		scanf("%d%d%lld",&opt,&x,&y);
		if (opt==1){
			int pos=find1(1,1,n,1,y);
			if (pos<=x&&askval(1,1,n,pos)<=y)update(1,1,n,pos,x,y);
		}
		if (opt==2){
			int ans=0,now=x;
			while(y>0&&now<=n){
				int qwq=find1(1,1,n,now,y);
				ll nowval=askval(1,1,n,qwq);
				if (nowval>y)break;
				ll awa=y;
				if (qwq>1)awa+=asksum(1,1,n,1,qwq-1);
				int qaq=find2(1,1,n,awa+1);
				ll s=0;
				if (qaq==n){
					s=asksum(1,1,n,qwq,qaq);
					if (s>y)s-=askval(1,1,n,n),qaq--;
				}
				else{
					qaq--;
					s=asksum(1,1,n,qwq,qaq);
				}
				ans+=qaq-qwq+1;
				y-=s;
				now=qaq+1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}