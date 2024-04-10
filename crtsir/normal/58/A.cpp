#include<iostream>
using namespace std;
int main()
{
	string s,k="hello";
	cin>>s;
	int b=0;
	for(int i=0;i<s.size();i++)
		if(s[i]==k[b])
		{
			b++;
			if(b>=k.size())
			{
				cout<<"YES";
				return 0;
			}
		}
	cout<<"NO";
}