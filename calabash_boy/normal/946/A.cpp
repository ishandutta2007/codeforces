#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	int n;
	cin>>n;
	while (n--){
		int a;
		cin>>a;
		ans+=abs(a);
	}
	cout<<ans<<endl;
	return 0;
}