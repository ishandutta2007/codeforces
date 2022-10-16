#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
    if(s.size()<3)
    {
        cout<<"NO";
        return 0;
    }
	for(int i=0;i<s.size()-2;i++)
	{
		char c[3];
		c[0]=s[i];
		c[1]=s[i+1];
		c[2]=s[i+2];
		sort(c,c+3);
		if(c[0]=='A'&&c[1]=='B'&&c[2]=='C')
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}