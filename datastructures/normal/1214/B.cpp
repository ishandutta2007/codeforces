#include <iostream>
#include <cstdio>
using namespace std;
int n,b,g,ans;
int main(){
	cin>>b>>g>>n;
	for (int i=0;i<=n;i++){
		if (i>b||n-i>g)continue;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}