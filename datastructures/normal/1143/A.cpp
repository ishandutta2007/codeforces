#include <iostream>
#include <cstdio>
using namespace std;
int a[200005],n;
int ans=2e9,flag[2]={1,1};
int main(){
//	freopen("1143A.in","r",stdin);
//	freopen("1143A.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=n;i;i--)
		if (flag[a[i]])ans=i,flag[a[i]]=0;
		
	cout<<ans<<endl;
}