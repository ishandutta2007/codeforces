#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	cin>>s;
	bool hav1=0;
	int hav0=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			hav0++;
		else
			hav1=true;
	if(hav1)cout<<1;
	for(int i=0;i<hav0;i++)cout<<0;
}