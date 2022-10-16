#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,a[300005];
inline bool check(int x){
	int last=0;
	for (int i=1;i<=n;i++){
		if (last-a[i]>x)return 0;
		if (last<a[i]){
			if (last+m-a[i]>x)last=a[i];
		}
	}
	return 1;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=m,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1; 
	}
	cout<<ans<<endl;
	return 0;
}