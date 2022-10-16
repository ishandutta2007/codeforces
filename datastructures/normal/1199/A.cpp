#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[200005],x,y,ans;
signed main(){
	cin>>n>>x>>y;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int flag=0;
		for (int j=max(1,i-x);j<=min(n,i+y);j++)
			if (a[i]>a[j])flag=1;
		if (flag==0&&ans==0)ans=i;
	}
	cout<<ans<<endl;
	return 0;
}