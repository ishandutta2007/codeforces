#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,k,a,b,s[100005];
inline int erfen(int x){
	int l=1,r=k,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (s[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
inline int dfs(int l,int r){
	int num=erfen(r)-erfen(l-1);
	if (num==0)return a;
	if (l==r)return b*num;
	int mid=(l+r)/2;
	return min(b*num*(r-l+1),dfs(l,mid)+dfs(mid+1,r));
}
signed main(){
	cin>>n>>k>>a>>b;
	for (int i=1;i<=k;i++)scanf("%I64d",&s[i]);
	sort(s+1,s+1+k);
	cout<<dfs(1,1<<n)<<endl;
}