#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
int a[2005];
ll f[2005][2005];
ll DFS(int l,int r,int x){
	if(l==r)return f[l][r]=1LL*a[l]*x;
	if(f[l][r]!=-1)return f[l][r];
	return f[l][r]=min(1LL*a[l]*x+DFS(l+1,r,x+1),1LL*a[r]*x+DFS(l,r-1,x+1));
}
int main(){
	int n,i,j;
	ll s;
	scanf("%d",&n);
	if(n==1){
		puts("0");
		return 0;
	}
	memset(f,-1,sizeof(f));
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	s=a[n]-a[1];
	for(i=n;i>=2;--i)a[i]-=a[i-1];
	//for(i=2;i<=n;++i)printf("%d ",a[i]);
	printf("%lld\n",DFS(2,n,1));
	return 0;
}