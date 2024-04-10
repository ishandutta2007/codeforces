#include<iostream>
#include<vector>
using namespace std;
int main()
{
	bool a[129]={false};
	string s;
	int tt=0;
	getline(cin,s);
	if(s=="{}")
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<s.size();i+=3)
		a[s[i]]=true;
	for(int i=0;i<129;i++)
		tt+=a[i];
	cout<<tt;
}