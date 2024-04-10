#include <iostream>
#include <cstdio>
using namespace std;
int n,d,e,ans=1e9;
int main(){
	cin>>n>>d>>e;
	e*=5;
	for (int i=0;i<=n;i+=e)ans=min(ans,(n-i)%d);
	cout<<ans<<endl;
	return 0;
}