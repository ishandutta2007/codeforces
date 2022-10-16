#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],mx,ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
	for (int i=1;i<=n;i++){
		if (a[i]!=mx)continue;
		int j=i;
		while(a[j]==mx&&j<=n)j++;
		ans=max(ans,j-i);
		i=j-1;
	}
	cout<<ans<<endl;
	return 0; 
}