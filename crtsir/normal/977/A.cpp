#include<bits/stdc++.h>
using namespace std;
long long become(long long a){
	if(a%10!=0)a--;else a/=10;
	return a;
}
int main(){
	long long a,b;
	cin>>a>>b;
	for(int i=0;i<b;i++)
		a=become(a);
	cout<<a;
}