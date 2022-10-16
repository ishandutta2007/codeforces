#include<bits/stdc++.h>
using namespace std;
int n,cnt1,cnt2;
string s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n/2;i++)
		if(s[i]=='?')
			cnt1+=9;
		else
			cnt1+=(s[i]-'0')*2;
	for(int i=n/2;i<n;i++)
		if(s[i]=='?')
			cnt2+=9;
		else
			cnt2+=(s[i]-'0')*2;
	if(fabs(cnt1-cnt2)==0)
		cout<<"Bicarp";
	else
		cout<<"Monocarp";
}