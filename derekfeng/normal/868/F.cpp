#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,a[100004],tl,tr;
int d[100004];
ll f[100004],ff[100004],sum;
void upd(int l,int r){
	while(tr<r)sum+=d[a[++tr]],++d[a[tr]];
	while(tl>l)sum+=d[a[--tl]],++d[a[tl]];
	while(tr>r)--d[a[tr]],sum-=d[a[tr--]];
	while(tl<l)--d[a[tl]],sum-=d[a[tl++]];
}
void sol(int l,int r,int L,int R){
	int mid=(l+r)>>1,p=L;
	for(int i=min(mid-1,R);i>=L;i--){
		upd(i+1,mid);
		if(ff[i]+sum<f[mid])f[mid]=ff[i]+sum,p=i;
	}
	if(l<mid)sol(l,mid-1,L,p);
	if(mid<r)sol(mid+1,r,p,R);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[i]=ff[i]=1e18;
	tl=1,tr=0;
	for(int i=1;i<=K;i++){
		sol(1,n,0,n-1);
		for(int j=1;j<=n;j++)ff[j]=f[j];
	}
	printf("%I64d",f[n]);
}