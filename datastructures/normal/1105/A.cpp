#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[1005],t,ans=1e9;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=100;i++){
		int s=0;
		for (int j=1;j<=n;j++){
			if (a[j]>i)s+=a[j]-i-1;
			if (a[j]<i)s+=i-a[j]-1;
		}
		if (s<ans)t=i,ans=s;
	}
	cout<<t<<' '<<ans<<endl;
	return 0;
}