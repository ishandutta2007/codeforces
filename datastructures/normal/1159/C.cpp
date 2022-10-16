#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,m,a[1000005],b[1000005],ans;
signed main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%I64d",&b[i]);
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	if (a[n]>b[1]){
		cout<<-1<<endl;
		return 0; 
	}
	for (int i=1;i<=n;i++)ans+=m*a[i];
	for (int i=1;i<=m;i++)ans+=b[i]-a[n];
	if (a[n]<b[1])ans+=a[n]-a[n-1];
	cout<<ans<<endl;
	return 0;
}