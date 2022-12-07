#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int pos=0, ans=0;
	for(int a=0; a<s.size(); a++)
	{
		int nu=s[a]-97, pq;
		if(nu>pos) pq=nu-pos;
		else pq=pos-nu;
		pos=nu;
		ans+=min(pq, 26-pq);
	}
	cout<<ans;
}