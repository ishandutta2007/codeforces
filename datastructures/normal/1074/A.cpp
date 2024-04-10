#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,a[1000005],b[1000005],tot,qwq,ans;
int larger(int x){
	int l=1,r=tot,pos=tot+1;
	while(l<=r){
		int mid=(l+r)/2;
		if (b[mid]>=x)pos=mid,r=mid-1;
		else l=mid+1;
	}
	return tot-pos+1;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if (x==1){
			if (y==1000000000)qwq++;
			else b[++tot]=y;
		}
	}
	sort(b+1,b+1+tot);
	ans=larger(a[1]);
	ans=min(ans,n);
	for (int i=1;i<n;i++)ans=min(ans,i+larger(a[i+1]));
	cout<<ans+qwq<<endl;
	return 0;
}