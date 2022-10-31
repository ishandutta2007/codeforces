#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string ss;
		cin>>ss;
		if (ss.length()<=10) cout<<ss<<endl;
		else cout<<ss[0]<<ss.length()-2<<ss[ss.length()-1]<<endl;
	}
	return 0;
}