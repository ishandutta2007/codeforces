#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,f[100005],ans[100005],tot;
signed main(){
	cin>>n;
	for (int i=2;i<=n;i++){
		int flag=0;
		for (int j=i;j<=n;j+=i){
			if (f[j]==1)continue;
			if (flag==0)flag=1,tot++;
			f[j]=1,ans[j]=tot; 
		}
	} 
	for (int i=2;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	return 0;
}