#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int t,n,m;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		if (n==1&&m==1)puts("0");
		else if (n==1||m==1)puts("1");
		else puts("2");
	}
	return 0;
}