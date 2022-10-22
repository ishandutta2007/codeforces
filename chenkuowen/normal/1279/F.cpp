#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
pair<int,int> check(int a[],int std,int n,int l){
	static pair<int,int> f[MAX_N];
	int ret=0;
	for(int i=1;i<=n;++i){
		pair<int,int> key0=make_pair(f[i-1].first+a[i],f[i-1].second);
		pair<int,int> key1=make_pair((i-l>0?f[i-l].first:0)+std
			,(i-l>0?f[i-l].second:0)+1);
		f[i]=min(key0,key1);
	}
	return f[n];
}
int solve(int a[],int n,int k,int l){
	int left=0,right=n;
	while(left<right){
		int mid=left+right>>1;
		if(check(a,mid,n,l).second>k) left=mid+1;
		else right=mid;
	}
	pair<int,int> x=check(a,right,n,l);
	return x.first-k*right;
}
char s[MAX_N];
int a[MAX_N];
int main(){
	int n,k,l; scanf("%d%d%d",&n,&k,&l);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) a[i]=s[i]>='A'&&s[i]<='Z';
	int ans1=solve(a,n,k,l);
	for(int i=1;i<=n;++i) a[i]^=1;
	int ans2=solve(a,n,k,l);
	printf("%d\n",min(ans1,ans2));
	return 0;
}