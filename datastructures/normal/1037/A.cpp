#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,ans;
int main(){
	cin>>n;
	while(n>0)ans++,n/=2;
	cout<<ans<<endl;
	return 0;
}