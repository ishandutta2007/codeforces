#include<iostream>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i][1]=='+')
			ans++;
		else
			ans--;
	}
	cout<<ans;
}