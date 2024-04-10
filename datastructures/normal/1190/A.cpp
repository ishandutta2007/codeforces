#include <iostream>
#include <cstdio>
#define int long long 
using namespace std;
int n,m,k,a[1000005],ans;
signed main(){
	cin>>n>>m>>k;
	for (register int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for (register int i=1;i<=m;){
		int j=i;
		while(j<=n&&(a[i]-(i-1)+(k-1))/k==(a[j]-(i-1)+(k-1))/k)j++;
		ans++,i=j;
	}
	cout<<ans<<endl;
	return 0;
}