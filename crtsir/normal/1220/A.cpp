#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s>>s;
	int cnt1=0,cnt2=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='n')
			cnt2++;
		else if(s[i]=='z')
			cnt1++;
	for(int i=0;i<cnt2;i++)cout<<"1 ";
	for(int i=0;i<cnt1;i++)cout<<"0 ";
}