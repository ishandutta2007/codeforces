#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int t,n,s;
struct node{
	int l,r;
}a[200005];
bool cmp(node a,node b){
	if (a.l==b.l)return a.r<b.r;
	return a.l<b.l;
}
inline bool check(int x){
	int now=0,nows=0;
	for (int i=1;i<=n;i++)
		if (a[i].r>=x)now++;
	if (now<=n/2)return 0;
	for (int i=1;i<=n;i++){
		if (a[i].r<x)nows+=a[i].l;
		else{
			if (now==(n+1)/2||a[i].l>=x){
				nows+=max(x,a[i].l);
			} 
			else now--,nows+=a[i].l;
		}
	}
	return nows<=s;
}
signed main(){
//	freopen("1251D.in","r",stdin);
//	freopen("1251D.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%I64d%I64d",&n,&s);
		int l=0,r=1e18,ans=0;
		for (int i=1;i<=n;i++){
			scanf("%I64d%I64d",&a[i].l,&a[i].r);
		}
		sort(a+1,a+1+n,cmp);
		while(l<=r){
			int mid=(l+r)/2; 
			if (check(mid))l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}