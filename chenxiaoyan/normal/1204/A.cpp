/*








*/
#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	cin>>a;
	if(a=="0")return cout<<"0",0;
	bool all0=true;
	for(int i=1;i<a.size();i++)all0&=a[i]=='0';
	int ans=0;
	for(int i=1;i<=a.size();i+=2)if(i<a.size()||!all0)ans++;
	cout<<ans;
	return 0;
}