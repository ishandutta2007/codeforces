#include<bits/stdc++.h>
using namespace std;
string s;
bool ue[2018];
vector<int>cnt[2018];
int main()
{
	int p,n;
	cin>>p>>n>>s;
	bool can=1;
	for(int i=0;i<p;i++)
		if(s[i]!='.')
			cnt[i%n].push_back(s[i]-'0');
	bool ok=1;
	for(int i=0;i<n;i++)
		if(cnt[i].size()>0)
			for(int j=0;j<cnt[i].size()-1;j++)
				if(cnt[i][j]!=cnt[i][cnt[i].size()-1])
			  		ue[i]=1;
	for(int i=0;i<p-n;i++)
		if(s[i]!=s[i+n]||s[i]=='.'||s[i+n]=='.')
			ok=false;
	if(ok)
	{
		cout<<"NO";
		return 0;
	}
	for(int i=0;i<p;i++)
		if(cnt[i%n].size()==0)
			cout<<char('0'+(i/n)%2);
		else
		{
			if(s[i]!='.')
				cout<<s[i];
			else
			{
				if(ue[i%n])
					cout<<'0';
				else
					cout<<char((cnt[i%n][0]+1)%2+'0');
			}
		}
}