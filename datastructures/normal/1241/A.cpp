#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		if (n<4)cout<<4-n<<endl;
		else if (n%2==1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}