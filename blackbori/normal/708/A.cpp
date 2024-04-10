#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string s;

int main()
{
	cin>>s;

	int f1,f2,i;

	f1=f2=0;

	for(i=0;i<s.size();i++){
		if(s[i]!='a') f1=1;
		if(f1==1 && s[i]=='a') f2=1;

		if(f1==1 && f2==0) s[i]--;
	}

	if(f1==0) s[s.size()-1]='z';

	cout<<s;

	return 0;
}