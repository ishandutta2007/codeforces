#include<bits/stdc++.h>
using namespace std;
string s;
string t;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s;
	int ans=-1;
	int lef=-1,rig=-1,coll=-1,colr=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==91&&lef==-1)
			lef=i;
		else if(s[i]==58&&lef!=-1) coll=i;
		if(lef!=-1&&coll!=-1) break;
	}
	for(int i=s.length()-1;i>=0;i--)
	{
		if(s[i]==93&&rig==-1) rig=i;
		else if(s[i]==58&&rig!=-1) colr=i;
		if(rig!=-1&&colr!=-1) break;
	}
	if(colr>coll&&colr!=-1&&coll!=-1)
	{
		ans=4;
		for(int i=coll;i<colr;i++)
		{
			if(s[i]==124) ans++;
		}
	}
	cout<<ans<<endl;
}