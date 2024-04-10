#include<bits/stdc++.h>
using namespace std;
 
int main() {
	string s; cin>>s;
	long long a=0,b=0,ret=0;
	for(int i=0; i<s.length(); i++)
		if(s[i]=='o') b+=a;
		else if(s[i-1]=='v') a++, ret+=b;
	cout<<ret<<endl;
	return 0;
}