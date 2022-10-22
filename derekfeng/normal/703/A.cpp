#include <bits/stdc++.h>
using namespace std;
int main(){
	int num0=0,num1=0,n;
	cin>>n;
	while (n--){
		int x,y;
		cin>>x>>y;
		num0+=(x>y);
		num1+=(y>x);
	}
	if (num1>num0) puts("Chris");
	if (num0==num1) puts("Friendship is magic!^^");
	if (num1<num0) puts("Mishka");
	}