#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	char gl[]={'A', 'E', 'I', 'O', 'U', 'Y'};
	string s;
	cin>>s;
	int n=s.size(), pr=-1, an=0;
	for(int a=0; a<n; a++)
	{
		int pos=0;
		for(int b=0; b<6; b++) if(s[a]==gl[b]) pos=1;
		if(pos)
		{
			an=max(an, a-pr);
			pr=a;
		}
	}
	an=max(an, n-pr);
	cout<<an;
}