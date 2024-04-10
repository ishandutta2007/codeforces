#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int l,r,d;
}a[2000005],b[2000005];
bool cmp(node a,node b){
	return a.l<b.l;
}
int n,m,k,t,tot;
int s[2000005];
inline bool check(int mind){
	int nowt=m+1;
	tot=0;
	for (int i=1;i<=k;i++)
		if (a[i].d>mind)b[++tot]=a[i];
	for (int i=1;i<=tot;){
		int nowr=b[i].r;
		int j;
		for (j=i+1;j<=tot;j++){
			if (b[j].l>nowr)break;
			nowr=max(nowr,b[j].r);
		}
		nowt+=(nowr-b[i].l)*2;
		i=j;
	}
	return nowt<=t;
}
int main(){
	cin>>n>>m>>k>>t;
	for (int i=1;i<=n;i++)scanf("%d",&s[i]);
	sort(s+1,s+1+n);
	for (int i=1;i<=k;i++)scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d),a[i].l--;
	sort(a+1,a+1+k,cmp);
	int ans=0,l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(s[mid]))ans=n-mid+1,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
//	return 0;
}