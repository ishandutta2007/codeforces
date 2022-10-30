#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1e5+5;
int n,m,K,p,a[MN],h[MN];
struct data{
	int id;ll rem;
	data(int x=0,ll y=0):id(x),rem(y){}
	inline bool operator<(data a)const{return rem>a.rem;}
};
priority_queue<data>q;
int cnt[MN];
inline bool check(ll x){
	for(reg int i=1;i<=n;i++)cnt[i]=0;
	while(!q.empty())q.pop();
	for(reg int i=1;i<=n;i++)
		if(x-1ll*m*a[i]<h[i])q.push(data(i,x/a[i]));
	for(reg int i=1;i<=m;i++)
		for(reg int j=1;j<=K;j++)
			if(!q.empty()){
				reg data v=q.top();q.pop();
				if(v.rem<i)return false;cnt[v.id]++;
				if(x-1ll*m*a[v.id]+1ll*p*cnt[v.id]<h[v.id])
					q.push(data(v.id,(x+1ll*p*cnt[v.id])/a[v.id]));
			}
	return q.empty();
}
int main(){
//	freopen("bamboo.in","r",stdin);
//	freopen("bamboo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&K,&p);
	for(reg int i=1;i<=n;i++)scanf("%d%d",h+i,a+i);
	reg ll l=0,r=1e13,mid,ans=0;
	while(l<=r){
		mid=(l+r>>1);
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}