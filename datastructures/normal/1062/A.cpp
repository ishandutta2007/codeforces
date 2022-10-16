#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[100005];
signed main(){
	a[1]=0;
	cin>>n;
	n++;
	for (int i=2;i<=n;i++)cin>>a[i];
	a[++n]=1001;
	int ans=0;
	for (int i=1;i<=n;){
		int j=i+1;
		while(j<=n&&a[j]-a[j-1]==1)j++;
		ans=max(ans,j-i-2);
		i=j;
	}
	cout<<ans<<endl;
	return 0;
}