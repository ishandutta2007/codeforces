#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define	int long long
using namespace std;
int n,ans;
inline int work(int x){
	if (x==0)return 0;
	return x%10+work(x/10);
}
signed main(){
	cin>>n;
	int now=0;
	while(now<=n)ans=max(work(now)+work(n-now),ans),now=now*10+9;
	cout<<ans<<endl;
	return 0;
}