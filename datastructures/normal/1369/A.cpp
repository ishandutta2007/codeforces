#include <iostream>
#include <cstdio>
using namespace std;
int t,n;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if (n%4==0)puts("YES");
		else puts("NO");
	}
	return 0;
}