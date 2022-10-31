#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int mark=n-1;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]>s[i+1])
		{
			mark=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==mark)
			continue;
		cout<<s[i];
	}
	cout<<endl;
}