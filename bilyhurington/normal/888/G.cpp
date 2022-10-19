#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
int find_min(int k,int l1,int r1,int l2,int r2){
	if(l1>r1||l2>r2) return 2e9;
//	printf("%d %d %d %d %d\n",k,l1,r1,l2,r2);
	if(k==-1) return a[l1]^a[l2];
	int mid1=l1,mid2=l2;
	while(mid1<=r1&&!((a[mid1]>>k)&1)) mid1++;
	while(mid2<=r2&&!((a[mid2]>>k)&1)) mid2++;
	int ans=2e9;
	ans=min(ans,find_min(k-1,l1,mid1-1,l2,mid2-1));
	ans=min(ans,find_min(k-1,mid1,r1,mid2,r2));
	if(ans<2e9) return ans;
	ans=min(ans,find_min(k-1,mid1,r1,l2,mid2-1));
	ans=min(ans,find_min(k-1,l1,mid1-1,mid2,r2));
	return ans;
}
long long solve(int k,int l,int r){
	if(l>=r||k==-1) return 0;
	int mid=l;long long ans=0;
	while(mid<=r&&((a[mid]>>k)&1)==0) mid++;
	if(mid>l&&mid<=r) ans=find_min(k,l,mid-1,mid,r);
//	printf("find %d %d %d %d %d %lld\n",k,l,mid-1,mid,r,ans);
	ans+=solve(k-1,l,mid-1)+solve(k-1,mid,r);
//	printf("%d %d %d %lld\n",k,l,r,ans);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	printf("%lld\n",solve(30,1,n));
	return 0;
}