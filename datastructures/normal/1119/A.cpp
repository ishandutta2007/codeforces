#include <iostream>
#include <cstdio>
using namespace std;
int n,a[300005],pos,ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]!=a[1]&&pos==0)pos=i;
	}
	for (int i=pos;i<=n;i++)
		if (a[i]==a[1])ans=max(ans,i-pos);
		else ans=max(ans,i-1);
	cout<<ans<<endl;
	return 0;
}