#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	string s1,s2;
	cin>>n;
	cin>>m;
	cin>>s1;
	cin>>s2;
	bool b=true,c=true,lk=false;
	int k=0;
	if(n>m+1)
	cout<<"NO";
	else{
	for(int i=0;i<n;i++)
	{
		if(s1[i]=='*')
		{
			lk=true;
		}
	}
	if(!lk)
	{
		if(s1==s2)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	else
	{
	for(int i=0;i<n&&b;i++)
	{
		if(s1[i]=='*')
		{
			k=m-(n-i);
		}
		else if(s1[i]!=s2[k]){
		b=false;
		//cout<<i;
		}
		k++;
	}
	if(b)
	cout<<"YES";
	else
	{
		cout<<"NO";
	}
	}}
	return 0;
}