#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int f[1000005],n,x,tot,sum[1000005];
signed main(){
	cin>>n>>x;
	f[0]=f[x]=1;
	for (int i=1;i<(1<<n);i++){
		if (f[i]==1)continue;
		sum[++tot]=i;
		f[i]=f[i^x]=1;
	}
	cout<<tot<<endl;
	for (int i=1;i<=tot;i++)cout<<(sum[i]^sum[i-1])<<' ';
	return 0;
}