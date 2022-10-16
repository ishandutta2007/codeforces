#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,a[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int fg=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
			if (a[i]%2==0)fg^=1;
		}
		if (fg==0)puts("maomao90");
		else puts("errorgorn");
	}
	return 0;
}