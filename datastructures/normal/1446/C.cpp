#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int n,a[200005];
inline int lowbit(int x){
	return x&(-x);
}
inline int high(int x){
	while((x-lowbit(x))>0)x-=lowbit(x);
	return x;
}
inline int work(int l,int r){
	if (l==r)return 1;
	int val=a[l],mid=-1;
	for (int i=l;i<=r;i++)val&=a[i];
	for (int i=l;i<=r;i++)a[i]-=val;
	for (int i=r-1;i>=l;i--)
		if (high(a[i])!=high(a[i+1])){
			mid=i;
			break;
		}
	return max(work(l,mid),work(mid+1,r))+1;
}
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	cout<<n-work(1,n)<<endl;
	return 0;
}