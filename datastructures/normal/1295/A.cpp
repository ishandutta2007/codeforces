#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		if (n%2==0){
			for (int i=1;i<=n/2;i++)printf("1");
			cout<<endl;
		}
		else{
			cout<<7;
			for (int i=1;i<=n/2-1;i++)printf("1");
			cout<<endl;
		}
	}
	return 0;
}