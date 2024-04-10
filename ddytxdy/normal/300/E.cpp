#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e7;
int m,mindiv[N+50],p[N],tot;LL cnt[N+50];
bool check(LL x){
	for(int i=1;i<=tot;i++){
		LL now=0;
		for(LL j=p[i];j<=x;j*=p[i]){
			now+=x/j;
			if(1.0l*j*p[i]>x)break;
		}
		if(now<cnt[p[i]])return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),cnt[x]++;
	for(int i=N;i;i--)cnt[i]+=cnt[i+1];
	for(int i=2;i<=N;i++){
		if(!mindiv[i])mindiv[i]=p[++tot]=i;
		for(int j=1,y;j<=tot&&p[j]<=mindiv[i]&&(y=p[j]*i)<=N;j++)
			mindiv[y]=p[j];
	}
	for(int i=N;i>1;i--)if(mindiv[i]!=i)
		cnt[mindiv[i]]+=cnt[i],cnt[i/mindiv[i]]+=cnt[i];
	LL l=1,r=1e18,ans;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}