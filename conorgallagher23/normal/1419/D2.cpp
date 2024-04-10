#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
int n,a[N],b[N],lim;bool vis[N],cov[N];
multiset<int>ms;
bool check(int mid){
	memset(vis,false,sizeof(vis));
	memset(cov,false,sizeof(cov));
	for(int i=1;i<=mid;i++)b[i<<1]=a[i],vis[i<<1]=cov[i<<1]=true;
	for(int i=mid+1;i<=n;i++)ms.insert(a[i]);
	int p=mid,res=0;
	for(int i=1,t;i<=n;i++)if(!vis[i]){
		t=0;
		if(cov[i-1])t=max(t,b[i-1]);
		if(cov[i+1])t=max(t,b[i+1]);
		auto it=ms.upper_bound(t);
		if(it==ms.end())return false;
		b[i]=(*it);ms.erase(it);
		vis[i]=true;
	}
	for(int i=2;i<n;i++)if(b[i]<b[i-1]&&b[i]<b[i+1])res++;
	return res>=mid; 
}
void binary(int l,int r){
	for(int k=20,t;~k;k--){
		t=l+(1<<k);
		if(t<=r&&check(t))l=t;
	}
	check(l);printf("%d\n",l);
	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(n&1)lim=n>>1;else lim=(n>>1)-1;
	binary(0,lim);
	return 0;
}