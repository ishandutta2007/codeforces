#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,a[10005],book[10005],ans;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)cin>>a[i];
		memset(book,0,sizeof(book));
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				book[a[j]-a[i]]=1;
		ans=0;
		for (int i=1;i<=10000;i++)ans+=book[i];
		cout<<ans<<endl;
	}
	return 0;
}