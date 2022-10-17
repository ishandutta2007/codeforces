#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,p,a[100005],c[100005],tot,ans[100005];
inline bool check1(int x){
	for (int i=1;i<=n;i++)
		c[i]=max(a[i]-x+1,1ll);
	sort(c+1,c+1+n);
	for (int i=1;i<=n;i++)
		if (i-c[i]+1<=0)return 0;
	return 1;
}
inline bool check2(int x){
	for (int i=1;i<=n;i++)
		c[i]=max(a[i]-x+1,1ll);
	sort(c+1,c+1+n);
	for (int i=1;i<=n;i++)
		if (i-c[i]+1>=p)return 0;
	return 1;
} 
signed main(){
	cin>>n>>p;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int l,r,ans1=-1,ans2=-1;
	l=1,r=1000000000;
	while(l<=r){
		int mid=(l+r)/2;
		if (check1(mid))ans1=mid,r=mid-1;
		else l=mid+1; 
	}
	if (ans1==-1){
		cout<<0<<endl;
		return 0;
	}
	l=ans1,r=10000000000;
	while(l<=r){
		int mid=(l+r)/2;
		if (check2(mid))ans2=mid,l=mid+1;
		else r=mid-1; 
	}
	if (ans2==-1){
		cout<<0<<endl;
		return 0;
	} 
	for (int i=ans1;i<=ans2;i++)a[++tot]=i;
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)printf("%d ",a[i]);
	cout<<endl;
	return 0;
}