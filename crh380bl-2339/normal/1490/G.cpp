#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s;
	int id;
}a[200005];
bool cmp(node x,node y){
	return x.s==y.s?x.id<y.id:x.s<y.s;
}
int Bins(long long x,int r){
	int l=1,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid].s>=x){
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans-1;
}
int main(){
	int T,n,m,i;
	long long sum,mx=0,x,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		a[0].s=0;
		for(i=1;i<=n;++i){
			scanf("%lld",&x);
			a[i].s=a[i-1].s+x;
			a[i].id=i;
		}
		sum=a[n].s;
		//sort(a+1,a+1+n,cmp);
		for(i=2;i<=n;++i)a[i].s=max(a[i-1].s,a[i].s);
		mx=a[n].s;
		while(m--){
			scanf("%lld",&x);
			if(x>mx&&sum<=0)printf("-1 ");
			else{
				if(sum>0&&x>mx)k=(x-mx+sum-1)/sum;
				else k=0;
				x=x-k*sum;
				printf("%lld ",k*n+Bins(x,n));
			}
		}
		puts("");
	}
	return 0;
}