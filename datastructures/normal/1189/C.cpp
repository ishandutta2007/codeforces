#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[100005],sum[100005],q,l,r;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	cin>>q;
	while(q--){
		scanf("%d%d",&l,&r);
		cout<<(sum[r]-sum[l-1])/10<<endl;
	}
	return 0;
}