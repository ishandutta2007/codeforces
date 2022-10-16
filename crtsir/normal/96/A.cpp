#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int f=1;
		for(int j=i+1;j<i+7;j++)
			if(s[j]!=s[i])f=0;
		if(f)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}