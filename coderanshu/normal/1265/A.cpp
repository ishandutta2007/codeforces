#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define li long int
#define pii pair<int,int>
#define pb push_back
#define mp make_pair

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	long int i,t,k;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int f=0;
		k=s.length();
		if(k==1)
		{
			cout<<"a\n";
			continue;
		}
		if(s[0]=='?')
		{
			if(s[1]!='a')
				s[0]='a';
			else if(s[1]!='b')
				s[0]='b';
			else if(s[1]!='c')
				s[0]='c';
			else
				s[0]='a';
		}
		else if(s[0]==s[1])
		{
			cout<<-1<<"\n";
			continue;
		}
		for(i=1;i<k-1;i++)
		{
			if(s[i]=='?')
			{
				if(s[i-1]!='a' && s[i+1]!='a')
					s[i]='a';
				else if(s[i-1]!='b' && s[i+1]!='b')
					s[i]='b';
				else if(s[i-1]!='c' && s[i+1]!='c')
					s[i]='c';
				else
					s[0]='a';
			}
			else if(s[i]==s[i-1]||s[i+1]==s[i])
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			cout<<-1<<"\n";continue;
		}
		if(s[k-1]=='?')
		{
			if(s[k-2]!='a')
				s[k-1]='a';
			else if(s[k-2]!='b')
				s[k-1]='b';
			else if(s[k-2]!='c')
				s[k-1]='c';
			else
				s[k-1]='a';
		}
		else if(s[k-1]==s[k-2])
		{
			cout<<-1;continue;
		}
		cout<<s<<"\n";
	}
	return 0;
}