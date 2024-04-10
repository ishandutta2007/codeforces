#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size(), ar[26];
	char ans[n];
	bool fou=0;
	if(n>=26)
	{
		for(int a=0; a<26; a++) ar[a]=0;
		for(int a=0; a<26; a++) if(s[a]!='?') ar[s[a]-65]++;
		for(int b=25; b<n; b++)
		{
			bool pos=1;
			stack <char> st;
			for(int a=0; a<26; a++)
			{
				if(ar[a]>1)
				{
					pos=0;
					break;
				}
				else if(ar[a]==0) st.push(a+65);
			}
			if(pos)
			{
				for(int a=b-25; a<=b; a++)
				{
					if(s[a]!='?') ans[a]=s[a];
					else
					{
						ans[a]=st.top();
						st.pop();
					}
				}
				for(int a=0; a<(b-25); a++)
				{
					if(s[a]!='?') ans[a]=s[a];
					else ans[a]='A';
				}
				for(int a=b+1; a<n; a++)
				{
					if(s[a]!='?') ans[a]=s[a];
					else ans[a]='A';
				}
				fou=1;
				break;
			}
			if(b!=(n-1))
			{
				if(s[b-25]!='?') ar[s[b-25]-65]--;
				if(s[b+1]!='?') ar[s[b+1]-65]++;
			}
		}
		if(fou) for(int a=0; a<n; a++) cout<<ans[a];
		else cout<<-1;
	}
	else cout<<-1;
}