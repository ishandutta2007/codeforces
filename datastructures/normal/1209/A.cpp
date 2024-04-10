#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[105],book[105],ans;
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if (book[i])continue;
		book[i]=1,ans++;
		for (int j=i+1;j<=n;j++)
			if (a[j]%a[i]==0)book[j]=1;
	}
	cout<<ans<<endl;
	return 0;
}