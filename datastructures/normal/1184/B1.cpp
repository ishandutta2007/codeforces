#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int d,g;
}a[100005];
int ask[100005],s,b;
bool cmp(node a,node b){
	return a.d<b.d;
}
int sum[100005];
int work(int x){
	int l=1,r=b;
	while(l<=r){
		int mid=(l+r)/2;
		if (x<a[mid].d)r=mid-1;
		else l=mid+1;
	}
	return l-1;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>s>>b;
	for (int i=1;i<=s;i++)cin>>ask[i];
	for (int i=1;i<=b;i++)scanf("%I64d%I64d",&a[i].d,&a[i].g);
	sort(a+1,a+1+b,cmp);
	for (int i=1;i<=b;i++)sum[i]=sum[i-1]+a[i].g;
	for (int i=1;i<=s;i++)
		printf("%I64d ",sum[work(ask[i])]);
	cout<<endl;
	return 0;
}