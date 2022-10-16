#include <iostream>
#include <cstdio>
using namespace std;
int n,v;
int main(){
	cin>>n>>v;
	if (v>=n-1){
		cout<<n-1<<endl;
		return 0;
	}
	int ans=v;
	for (int i=1;i<=(n-1)-v;i++)ans+=i+1;
	cout<<ans<<endl;
	return 0;
}