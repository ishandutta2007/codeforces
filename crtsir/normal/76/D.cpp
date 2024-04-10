#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long a,b,c;
	cin>>a>>b;
	vector<int>v1,v2;
	c=(a-b);
	if(c%2)
		cout<<-1;
	else
		cout<<c/2<<' '<<(a+b)/2;
}