#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,ans=2e9;
signed main(){
	cin>>n;
	for (int i=1;i*i<=n;i++)
		ans=min(ans,i+((n-1)/i+1));
	cout<<ans<<endl;
	return 0;
}